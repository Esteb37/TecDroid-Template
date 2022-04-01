#include "subsystems/Turret.h"

using namespace std;

Turret::Turret()
{

	m_encoder.SetDistancePerPulse(k_turretDPR);

	// TODO : change if spark encoder

	// m_encoder.SetPositionConversionFactor(k_turretDPR);

	m_alignPID.SetTolerance(k_turretAlignPIDTolerance);

	m_anglePID.SetTolerance(k_turretAnglePIDTolerance);
}

void Turret::Periodic()
{

	if (!m_keepingStill)
	{
		m_angle = GetAngle();
	}

	m_keepingStill = false;
}

void Turret::Turn(double speed)
{
	SetMotor(speed);
}

void Turret::Reset()
{
	ResetEncoder();
	ResetAnglePID();
	ResetAlignPID();
}

void Turret::KeepStill()
{
	m_keepingStill = true;

	SetAngle(m_angle);
}

bool Turret::Center()
{
	return SetAngle(0);
}

void Turret::SetMotor(double speed)
{

	if (m_limitSafety)
	{
		if (m_limitSwitchRight.Get())
		{
			speed = fmin(speed, 0);
		}
		else if (m_limitSwitchLeft.Get())
		{
			speed = fmax(speed, 0);
		}
	}

	if (m_encoderSafety)
	{
		if (GetAngle() >= k_turretMaxAngle)
		{
			speed = fmin(speed, 0);
		}
		else if (GetAngle() <= k_turretMinAngle)
		{
			speed = fmax(speed, 0);
		}
	}

	m_motor.Set(speed * k_turretMaxSpeed);
}

double Turret::GetMotor()
{
	return m_motor.Get();
}

void Turret::InvertMotor(bool inverted)
{
	m_motor.SetInverted(inverted);
}

void Turret::PrintMotor()
{
	SmartDashboard::PutNumber("Turret Motor", m_motor.Get());
}

double Turret::GetEncoder()
{

	// TODO : change if spark encoder

	// return m_encoder.GetPosition();

	return m_encoder.GetDistance();
}

void Turret::ResetEncoder()
{

	// TODO : change if spark encoder

	// m_encoder.SetPosition(0);

	m_encoder.Reset();
}

void Turret::InvertEncoder(bool invert)
{

	// TODO : change if spark encoder

	// m_encoder.SetInverted(invert);

	m_encoder.SetReverseDirection(invert);
}

void Turret::PrintEncoder()
{
	SmartDashboard::PutNumber("Turret Encoder", GetEncoder());
}

bool Turret::SetAngle(double angle)
{

	if (angle < k_turretMaxAngle && angle > k_turretMinAngle)
	{
		m_anglePID.SetSetpoint(angle);

		double output = m_anglePID.Calculate(GetAngle());

		m_motor.Set(clamp(output, -k_turretMaxSpeed, k_turretMaxSpeed));

		return m_anglePID.AtSetpoint();
	}
	else
	{
		return false;
	}
}

double Turret::GetAngle()
{
	return GetEncoder() * 360;
}

void Turret::ResetAnglePID()
{
	m_anglePID.Reset();
}

void Turret::PrintAngle()
{
	SmartDashboard::PutNumber("Turret Angle", GetAngle());
}

void Turret::PrintAnglePIDError()
{
	SmartDashboard::PutNumber("Turret Angle PID Error", m_anglePID.GetPositionError());
}

bool Turret::Align()
{
	m_alignPID.SetSetpoint(0);

	double output = m_alignPID.Calculate(-m_limelight.GetHorizontalAngle());

	m_motor.Set(clamp(output, -k_turretMaxSpeed, k_turretMaxSpeed));

	return m_alignPID.AtSetpoint();
}

void Turret::ResetAlignPID()
{
	m_alignPID.Reset();
}

void Turret::PrintAlignPIDError()
{
	SmartDashboard::PutNumber("Turret Align PID Error", m_alignPID.GetPositionError());
}