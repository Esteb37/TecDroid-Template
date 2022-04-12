#include "subsystems/MotorSubsystem.h"

MotorSubsystem::MotorSubsystem(MotorConfig config, unsigned int motorPort)
{
	m_motorConfig = config;
	m_motorPort = motorPort;

	switch (config)
	{
	case MotorConfig::kNeo:
		m_motorSpark = new CANSparkMax(m_motorPort, CANSparkMaxLowLevel::MotorType::kBrushless);
		break;
	case MotorConfig::kSpark:
		m_motorSpark = new CANSparkMax(m_motorPort, CANSparkMaxLowLevel::MotorType::kBrushless);
		break;
	case MotorConfig::kVictorCAN:
		m_motorVictorCAN = new VictorSPX(m_motorPort);
		break;
	case MotorConfig::kVictorPWM:
		m_motorVictorPWM = new VictorSP(m_motorPort);
		break;
	}

	SetName("MotorSubsystem");
}

void MotorSubsystem::Periodic()
{
}

void MotorSubsystem::SetMotor(double speed)
{
	if (m_limitSafetyActive)
	{
		if (GetUpperLimit())
		{
			speed = fmin(speed, 0);
		}
		else if (GetLowerLimit())
		{
			speed = fmax(speed, 0);
		}
	}

	switch (m_motorConfig)
	{
	case MotorConfig::kNeo:
	case MotorConfig::kSpark:
		m_motorSpark->Set(std::clamp(speed, -m_maxSpeed, m_maxSpeed));
		break;

	case MotorConfig::kVictorCAN:
		m_motorVictorCAN->Set(VictorSPXControlMode::PercentOutput, std::clamp(speed, -m_maxSpeed, m_maxSpeed));
		break;

	case MotorConfig::kVictorPWM:
		m_motorVictorPWM->Set(std::clamp(speed, -m_maxSpeed, m_maxSpeed));
		break;
	}
}

double MotorSubsystem::GetMotor()
{
	switch (m_motorConfig)
	{
	case MotorConfig::kNeo:
	case MotorConfig::kSpark:
		return m_motorSpark->Get();
		break;

	case MotorConfig::kVictorCAN:
		return m_motorVictorCAN->GetMotorOutputPercent();
		break;

	case MotorConfig::kVictorPWM:
		return m_motorVictorPWM->Get();
		break;
	}
}

void MotorSubsystem::InvertMotor(bool inverted)
{
	switch (m_motorConfig)
	{
	case MotorConfig::kNeo:
	case MotorConfig::kSpark:
		m_motorSpark->SetInverted(inverted);
		break;

	case MotorConfig::kVictorCAN:
		m_motorVictorCAN->SetInverted(inverted);
		break;

	case MotorConfig::kVictorPWM:
		m_motorVictorPWM->SetInverted(inverted);
		break;
	}
}

void MotorSubsystem::PrintMotor()
{
	SmartDashboard::PutNumber(GetName() + " Motor", GetMotor());
}

bool MotorSubsystem::GetUpperLimit()
{
	return m_upperLimit->Get();
}

bool MotorSubsystem::GetLowerLimit()
{
	return m_lowerLimit->Get();
}

void MotorSubsystem::SetLimitPorts(unsigned int upperLimitPort, unsigned int lowerLimitPort)
{
	m_upperLimit = new DigitalInput(upperLimitPort);
	m_lowerLimit = new DigitalInput(lowerLimitPort);
}

void MotorSubsystem::SetLimitSafety(bool active)
{
	m_limitSafetyActive = active;
}

// print limits
void MotorSubsystem::PrimtLimits()
{
	SmartDashboard::PutBoolean(GetName() + " Upper Limit", GetUpperLimit());
	SmartDashboard::PutBoolean(GetName() + " Lower Limit", GetLowerLimit());
}