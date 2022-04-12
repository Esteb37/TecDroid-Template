#include "subsystems/EncoderSubsystem.h"

EncoderSubsystem::EncoderSubsystem(MotorConfig mconfig, EncoderConfig econfig, unsigned int motorPort)
	: MotorSubsystem(mconfig, motorPort)
{
	m_config = econfig;

	if (mconfig == MotorConfig::kNeo && econfig == EncoderConfig::kRev)
	{
		m_encoderSpark = new SparkMaxRelativeEncoder(m_motor->GetEncoder());
	}
	else
	{
		throw std::invalid_argument("Encoder must be Spark and Motor must be Neo");
	}
}

EncoderSubsystem::EncoderSubsystem(MotorConfig mconfig, EncoderConfig econfig, unsigned int motorPort, unsigned int encoderA, unsigned int encoderB)
	: MotorSubsystem(mconfig, motorPort)
{
	m_config = econfig;

	m_encoder = new Encoder(encoderA, encoderB, false, Encoder::EncodingType::k4X);
}

double EncoderSubsystem::GetEncoder()
{
	switch (m_config)
	{
	case EncoderConfig::kRev:
		return m_encoderSpark->GetPosition();
		break;
	case EncoderConfig::kFrc:
		return m_encoder->Get();
		break;
	}
}

void EncoderSubsystem::ResetEncoder()
{
	switch (m_config)
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
	switch (m_config)
	{
	case EncoderConfig::kRev:
		m_encoderSpark->SetInverted(invert);
		break;
	case EncoderConfig::kFrc:
		m_encoder->SetReverseDirection(invert);
		break;
	}
}

void EncoderSubsystem::PrintEncoder()
{
	SmartDashboard::PutNumber("EncoderSubsystem Encoder", GetEncoder());
}