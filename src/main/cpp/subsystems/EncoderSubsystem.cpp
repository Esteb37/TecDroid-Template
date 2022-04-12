#include "subsystems/EncoderSubsystem.h"

EncoderSubsystem::EncoderSubsystem(MotorConfig mconfig, unsigned int motorPort)
	: MotorSubsystem(mconfig, motorPort)
{
}

EncoderSubsystem::EncoderSubsystem(MotorConfig mconfig, EncoderConfig econfig, unsigned int motorPort)
	: MotorSubsystem(mconfig, motorPort)
{
	m_encoderConfig = econfig;

	if (mconfig == MotorConfig::kNeo && econfig == EncoderConfig::kRev)
	{
		m_encoderSpark = new SparkMaxRelativeEncoder(m_motorSpark->GetEncoder());
	}
	else
	{
		throw std::invalid_argument("Encoder must be Spark and Motor must be Neo");
	}

	SetName("EncoderSubsystem");
}

EncoderSubsystem::EncoderSubsystem(MotorConfig mconfig, EncoderConfig econfig, unsigned int motorPort, unsigned int encoderA, unsigned int encoderB)
	: MotorSubsystem(mconfig, motorPort)
{
	m_encoderConfig = econfig;

	m_encoder = new Encoder(encoderA, encoderB, false, Encoder::EncodingType::k4X);

	SetName("EncoderSubsystem");
}

void EncoderSubsystem::Periodic()
{
}

void EncoderSubsystem::SetMotor(double speed)
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

	if (m_positionSafetyActive)
	{
		if (GetPosition() >= m_maxPosition)
		{
			speed = fmin(speed, 0);
		}
		else if (GetPosition() <= m_minPosition)
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

void EncoderSubsystem::Reset()
{

	ResetEncoder();
	ResetPositionPID();
	ResetSpeedPID();
}

void EncoderSubsystem::ResetEncoder()
{
	switch (m_encoderConfig)
	{
	case EncoderConfig::kRev:
		m_encoderSpark->SetPosition(0);
		break;
	case EncoderConfig::kFrc:
		m_encoder->Reset();
		break;
	}
}

void EncoderSubsystem::InvertEncoder(bool invert)
{
	switch (m_encoderConfig)
	{
	case EncoderConfig::kRev:
		m_encoderSpark->SetInverted(invert);
		break;
	case EncoderConfig::kFrc:
		m_encoder->SetReverseDirection(invert);
		break;
	}
}

void EncoderSubsystem::SetEncoderPorts(unsigned int A, unsigned int B)
{
	switch (m_encoderConfig)
	{
	case EncoderConfig::kRev:
		throw std::invalid_argument("This function cannot be used with REV encoder.");
		break;

	case EncoderConfig::kFrc:
		m_encoder = new Encoder(A, B, false, Encoder::EncodingType::k4X);
		break;
	}
}

bool EncoderSubsystem::SetPosition(double position, bool inverted)
{

	m_positionPID->SetSetpoint(position);

	double output = m_positionPID->Calculate((inverted ? -1 : 1) * GetPosition());

	SetMotor(output);

	return m_positionPID->AtSetpoint();
}

double EncoderSubsystem::GetPosition()
{
	switch (m_encoderConfig)
	{
	case EncoderConfig::kRev:
		return m_encoderSpark->GetPosition();
		break;

	case EncoderConfig::kFrc:
		return m_encoder->Get();
		break;
	}
}

void EncoderSubsystem::ConfigurePositionPID(double p, double i, double d, double tolerance)
{
	m_positionPID->SetPID(p, i, d);
	m_positionPID->SetTolerance(tolerance);
}

void EncoderSubsystem::SetPositionConversionFactor(double factor)
{
	switch (m_encoderConfig)
	{
	case EncoderConfig::kRev:
		m_encoderSpark->SetPositionConversionFactor(factor);
		break;

	case EncoderConfig::kFrc:
		m_encoder->SetDistancePerPulse(factor);
		break;
	}
}

void EncoderSubsystem::ResetPositionPID()
{
	m_positionPID->Reset();
}

void EncoderSubsystem::PrintPosition()
{
	SmartDashboard::PutNumber(GetName() + " Encoder Position", GetPosition());
}

void EncoderSubsystem::PrintPositionError()
{
	SmartDashboard::PutNumber(GetName() + " Encoder Position Error", m_positionPID->GetPositionError());
}

void EncoderSubsystem::SetPositionSafety(bool active)
{
	m_positionSafetyActive = active;
}

bool EncoderSubsystem::SetSpeed(double speed, bool inverted)
{
	m_speedPID->SetSetpoint(speed);

	double output = m_speedPID->Calculate((inverted ? -1 : 1) * GetPosition());

	SetMotor(output);

	return m_positionPID->AtSetpoint();
}

double EncoderSubsystem::GetSpeed()
{
	switch (m_encoderConfig)
	{
	case EncoderConfig::kRev:
		return m_encoderSpark->GetVelocity();
		break;

	case EncoderConfig::kFrc:
		return m_encoder->GetRate() * m_speedCF;
		break;
	}
}

void EncoderSubsystem::ConfigureSpeedPID(double p, double i, double d, double tolerance)
{
	m_speedPID->SetPID(p, i, d);
	m_speedPID->SetTolerance(tolerance);
}

void EncoderSubsystem::SetSpeedConversionFactor(double factor)
{
	switch (m_encoderConfig)
	{
	case EncoderConfig::kRev:
		m_encoderSpark->SetVelocityConversionFactor(factor);
		break;

	case EncoderConfig::kFrc:
		m_speedCF = factor;
		break;
	}
}

void EncoderSubsystem::ResetSpeedPID()
{
	m_speedPID->Reset();
}

void EncoderSubsystem::PrintSpeed()
{
	SmartDashboard::PutNumber(GetName() + " Encoder Speed", GetSpeed());
}

void EncoderSubsystem::PrintSpeedError()
{
	SmartDashboard::PutNumber(GetName() + " Encoder Speed Error", m_speedPID->GetPositionError());
}
