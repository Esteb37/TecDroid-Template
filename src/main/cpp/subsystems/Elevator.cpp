#include "subsystems/Elevator.h"
#include <frc/smartdashboard/SmartDashboard.h>

Elevator::Elevator(MotorConfig config, unsigned int port) : MotorSubsystem(config, port)
{
	m_config = config;

	switch (config)
	{
	case MotorConfig::kNeo:
		m_motorSpark = new CANSparkMax(pElevatorMotor, CANSparkMaxLowLevel::MotorType::kBrushless);
		m_encoderSpark = new SparkMaxRelativeEncoder(m_motorSpark->GetEncoder());
		break;
	case MotorConfig::kSpark:
		m_motorSpark = new CANSparkMax(pElevatorMotor, CANSparkMaxLowLevel::MotorType::kBrushless);
		m_encoder = new Encoder(pElevatorEncoderA, pElevatorEncoderB, false, Encoder::EncodingType::k4X);
		break;

	case MotorConfig::kVictorCAN:
		m_motorVictorCAN = new VictorSPX(pElevatorMotor);
		m_encoder = new Encoder(pElevatorEncoderA, pElevatorEncoderB, false, Encoder::EncodingType::k4X);
		break;

	case MotorConfig::kVictorPWM:
		m_motorVictorPWM = new VictorSP(pElevatorMotor);
		m_encoder = new Encoder(pElevatorEncoderA, pElevatorEncoderB, false, Encoder::EncodingType::k4X);
		break;
	}
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

	switch (m_config)
	{
	case MotorConfig::kNeo:
	case MotorConfig::kSpark:
		m_motorSpark->Set(speed);
		break;

	case MotorConfig::kVictorCAN:
		m_motorVictorCAN->Set(VictorSPXControlMode::PercentOutput, speed);
		break;

	case MotorConfig::kVictorPWM:
		m_motorVictorPWM->Set(speed);
		break;
	}
}

double Elevator::GetMotor()
{
	switch (m_config)
	{
	case MotorConfig::kNeo:
	case MotorConfig::kSpark:
		m_motorSpark->Get();
		break;

	case MotorConfig::kVictorCAN:
		m_motorVictorCAN->GetMotorOutputPercent();
		break;

	case MotorConfig::kVictorPWM:
		m_motorVictorPWM->Get();
		break;
	}
}

void Elevator::InvertMotor(bool invert)
{
	switch (m_config)
	{
	case MotorConfig::kNeo:
	case MotorConfig::kSpark:
		m_motorSpark->SetInverted(invert);
		break;

	case MotorConfig::kVictorCAN:
		m_motorVictorCAN->SetInverted(invert);
		break;

	case MotorConfig::kVictorPWM:
		m_motorVictorPWM->SetInverted(invert);
		break;
	}
}

void Elevator::PrintMotor()
{
	SmartDashboard::PutNumber("Elevator Motor", GetMotor());
}

// --------- Encoder ---------

double Elevator::GetEncoder()
{
	switch (m_config)
	{
	case MotorConfig::kNeo:
		return m_encoderSpark->GetPosition();
		break;
	case MotorConfig::kSpark:
	case MotorConfig::kVictorCAN:
	case MotorConfig::kVictorPWM:
		return m_encoder->GetDistance();
		break;
	}
}
void Elevator::ResetEncoder()
{
	switch (m_config)
	{
	case MotorConfig::kNeo:
		m_encoderSpark->SetPosition(0);
		break;
	case MotorConfig::kSpark:
	case MotorConfig::kVictorCAN:
	case MotorConfig::kVictorPWM:
		m_encoder->Reset();
		break;
	}
}

void Elevator::InvertEncoder(bool invert)
{
	switch (m_config)
	{
	case MotorConfig::kNeo:
		m_encoderSpark->SetInverted(invert);
		break;
	case MotorConfig::kSpark:
	case MotorConfig::kVictorCAN:
	case MotorConfig::kVictorPWM:
		m_encoder->SetReverseDirection(invert);
		break;
	}
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
