#include "subsystems/MotorSubsystem.h"

MotorSubsystem::MotorSubsystem(MotorConfig config, unsigned int motorPort)
{
	m_config = config;
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
}

void MotorSubsystem::Periodic()
{
}

void MotorSubsystem::SetMotor(double speed)
{
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

double MotorSubsystem::GetMotor()
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

void MotorSubsystem::InvertMotor(bool inverted)
{
	switch (m_config)
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
	SmartDashboard::PutNumber("MotorSubsystem Motor", GetMotor());
}
