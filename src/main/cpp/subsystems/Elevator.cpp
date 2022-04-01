#include "subsystems/Elevator.h"
#include <frc/smartdashboard/SmartDashboard.h>

Elevator::Elevator()
{
	m_encoder.SetDistancePerPulse(k_elevatorDPR);
}

void Elevator::Periodic()
{
	if (!m_keepingStill)
	{
		m_height = GetHeight();
	}

	m_keepingStill = false;
}

// ---------- Actions -----------

void Elevator::Reset()
{
	ResetEncoder();
	ResetHeightPID();
}

void Elevator::Move(double speed)
{
	SetMotor(speed);
}

void Elevator::KeepStill()
{
	m_keepingStill = true;

	SetHeight(m_height);
}

// --------- Motor ---------

void Elevator::SetMotor(double speed)
{

	if (m_limitSafety)
	{
		if (GetTopLimit())
		{
			speed = fmin(speed, 0);
		}
		else if (GetBottomLimit())
		{
			speed = fmax(speed, 0);
		}
	}

	if (m_heightSafety)
	{
		if (GetHeight() >= k_elevatorMaxHeight)
		{
			speed = fmin(speed, 0);
		}
		else if (GetHeight() <= k_elevatorMinHeight)
		{
			speed = fmax(speed, 0);
		}
	}

	m_motor.Set(speed);
}

double Elevator::GetMotor()
{
	return m_motor.Get();
}

void Elevator::InvertMotor(bool invert)
{
	m_motor.SetInverted(invert);
}

void Elevator::PrintMotor()
{
	SmartDashboard::PutNumber("Elevator Motor", GetMotor());
}

// --------- Encoder ---------

double Elevator::GetEncoder()
{

	// TODO : change if spark encoder

	// return m_encoder.GetPosition();

	return m_encoder.GetDistance();
}

void Elevator::ResetEncoder()
{

	// TODO : change if spark encoder

	// m_encoder.SetPosition(0);

	m_encoder.Reset();
}

void Elevator::InvertEncoder(bool invert)
{
	// TODO : change if spark encoder

	// m_encoder.SetInverted(invert);

	m_encoder.SetReverseDirection(invert);
}

void Elevator::PrintEncoder()
{
	SmartDashboard::PutNumber("Elevator Encoder", GetEncoder());
}

// ---------- Height ---------

bool Elevator::SetHeight(double height)
{
	if (height >= k_elevatorMinHeight && height <= k_elevatorMaxHeight)
	{
		m_heightPID.SetSetpoint(height);
		double output = m_heightPID.Calculate(GetHeight());
		SetMotor(std::clamp(output, -k_elevatorMaxSpeed, k_elevatorMaxSpeed));
		return m_heightPID.AtSetpoint();
	}
	else
	{
		return false;
	}
}

double Elevator::GetHeight()
{
	return GetEncoder(); // TODO : change if there is offset
}

void Elevator::ResetHeightPID()
{
	m_heightPID.Reset();
}

void Elevator::PrintHeight()
{
	SmartDashboard::PutNumber("Elevator Height", GetHeight());
}

void Elevator::PrintHeightPIDError()
{
	SmartDashboard::PutNumber("Elevator Height PID Error", m_heightPID.GetPositionError());
}

// ---------- Limits ---------

bool Elevator::GetTopLimit()
{
	return m_limitSwitchTop.Get();
}

bool Elevator::GetBottomLimit()
{
	return m_limitSwitchBottom.Get();
}

void Elevator::PrintLimits()
{
	SmartDashboard::PutBoolean("Elevator Top Limit", GetTopLimit());
	SmartDashboard::PutBoolean("Elevator Bottom Limit", GetBottomLimit());
}

// --------- Safety ----------

void Elevator::SetLimitSafetyActive(bool active)
{
	m_limitSafety = active;
}

void Elevator::SetHeightSafetyActive(bool active)
{
	m_heightSafety = active;
}
