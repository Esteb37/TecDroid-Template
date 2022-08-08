/*------------------------------------------------------------
						&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& /&&&&,
					.&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& /&&&&&&&&%
				.&&&&/ &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& /&&&&&&&&&&&*
			.%&&&(      &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&% %&&&&&&&&&&&&&
		%&&&#     %#&&#           (&&&&&&&&&&&              %&&&&&&&&&&&&&
	*&&&#                          (&&&&&&&&&&&    /           %&&&&&&&&&&&
*&%  ,                           (&&&&&&&&&&&(&&&&(           &&&&&&&&&&&
& (,..                          (&&&&&&&&&&&&&&&&            %&&&&&&&&&&
	&*                             (&&&&&&&&&&&&&&&&            &&&&&&&&&&&
	&/                             (&&&&&&&&&&&&&&&&%          &&&&&&&&&&&(
	#&&    .&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#**(&&&&&&&&&&&&&#
	&#  (&                        ......... &&&&&&&&&&&&&&&&&&&&&&&&&&
	/&   &                                   .&&&&&&&&&&&&&&&&&&&&&&
		%&&* &*                                   ,%&&&&&&&&&&&&&%*

	Author: Esteban Padilla Cerdio
	Email: esteban37padilla@gmail.com
	URL: github.com/esteb37
		 github.com/tecdroid-3354
	Date: 12/04/2022
	Language: cpp
	Copyright (c) TecDroid 3354 and Esteban Padilla Cerdio
	Open Source Software; you can modify and/or share it under the terms of
*/

#include "subsystems/EncoderSubsystem.h"

using namespace TD;

EncoderSubsystem::EncoderSubsystem()
{
	SetName("EncoderSubsystem");
}

EncoderSubsystem &EncoderSubsystem::GetInstance()
{
	static EncoderSubsystem instance;
	return instance;
}

void EncoderSubsystem::Initialize(MotorConfig motorConfig, unsigned int motorPort)
{
	MotorSubsystem::Initialize(motorConfig, motorPort);
	SetName("EncoderSubsystem");
}

void EncoderSubsystem::Initialize(MotorConfig motorConfig, vector<unsigned int> motorPorts)
{
	MotorSubsystem::Initialize(motorConfig, motorPorts);
	SetName("EncoderSubsystem");
}

void EncoderSubsystem::Initialize(MotorConfig motorConfig, EncoderConfig encoderConfig, unsigned int motorPort)
{
	MotorSubsystem::Initialize(motorConfig, motorPort);

	m_encoderConfig = encoderConfig;

	if (motorConfig == MotorConfig::NEO && encoderConfig == EncoderConfig::REV)
	{
		m_encoderSpark = new SparkMaxRelativeEncoder(m_motorSpark->GetEncoder());
	}
	else
	{
		throw std::invalid_argument("Encoder must be Spark and Motor must be Neo");
	}

	SetName("EncoderSubsystem");
}

void EncoderSubsystem::Initialize(MotorConfig motorConfig, EncoderConfig encoderConfig, vector<unsigned int> motorPorts)
{

	MotorSubsystem::Initialize(motorConfig, motorPorts);

	m_encoderConfig = encoderConfig;

	if (motorConfig == MotorConfig::NEO && encoderConfig == EncoderConfig::REV)
	{
		m_encoderSpark = new SparkMaxRelativeEncoder(m_motorSparkList[0]->GetEncoder());
	}
	else
	{
		throw std::invalid_argument("Encoder must be Spark and Motor must be Neo");
	}

	SetName("EncoderSubsystem");
}

void EncoderSubsystem::Initialize(MotorConfig motorConfig, EncoderConfig encoderConfig, unsigned int motorPort, unsigned int encoderA, unsigned int encoderB)
{

	MotorSubsystem::Initialize(motorConfig, motorPort);

	if (encoderConfig == EncoderConfig::REV)
	{
		throw std::invalid_argument("Encoder must be FRC");
	}

	m_encoderConfig = encoderConfig;

	m_encoder = new Encoder(encoderA, encoderB, false, Encoder::EncodingType::k4X);

	SetName("EncoderSubsystem");
}

void EncoderSubsystem::Initialize(MotorConfig motorConfig, EncoderConfig encoderConfig, vector<unsigned int> motorPorts, unsigned int encoderA, unsigned int encoderB)
{

	MotorSubsystem::Initialize(motorConfig, motorPorts);

	if (encoderConfig == EncoderConfig::REV)
	{
		throw std::invalid_argument("Encoder must be FRC");
	}

	m_encoderConfig = encoderConfig;

	m_encoder = new Encoder(encoderA, encoderB, false, Encoder::EncodingType::k4X);

	SetName("EncoderSubsystem");
}

void EncoderSubsystem::Periodic()
{
}

void EncoderSubsystem::Reset()
{
	ResetEncoder();
	ResetPositionPID();
	ResetRPMPID();
}

void EncoderSubsystem::SetMotor(double speed)
{

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

	MotorSubsystem::SetMotor(speed);
}

void EncoderSubsystem::SetMotors(double speed)
{

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

	MotorSubsystem::SetMotors(speed);
}

void EncoderSubsystem::SetMotors(vector<double> speeds)
{
	for (unsigned i = 0; i < speeds.size(); i++)
	{
		if (m_positionSafetyActive)
		{
			if (GetPosition() >= m_maxPosition)
			{
				speeds[i] = fmin(speeds[i], 0);
			}
			else if (GetPosition() <= m_minPosition)
			{
				speeds[i] = fmax(speeds[i], 0);
			}
		}
	}

	MotorSubsystem::SetMotors(speeds);
}

void EncoderSubsystem::ResetEncoder()
{
	switch (m_encoderConfig)
	{
	case EncoderConfig::REV:
		m_encoderSpark->SetPosition(0);
		break;
	case EncoderConfig::FRC:
	default:
		m_encoder->Reset();
		break;
	}
}

void EncoderSubsystem::InvertEncoder(bool invert)
{
	switch (m_encoderConfig)
	{
	case EncoderConfig::REV:
		if (m_motorSpark->GetMotorType() == CANSparkMaxLowLevel::MotorType::kBrushless)
		{
			m_encoderDirection = invert ? -1 : 1;
		}
		else
		{
			m_encoderDirection = 1;
			m_encoderSpark->SetInverted(invert);
		}

		break;
	case EncoderConfig::FRC:
	default:
		m_encoder->SetReverseDirection(invert);
		break;
	}
}

void EncoderSubsystem::SetEncoderPorts(unsigned int A, unsigned int B)
{
	switch (m_encoderConfig)
	{
	case EncoderConfig::REV:
		throw std::invalid_argument("This function cannot be used with REV encoder.");
		break;

	case EncoderConfig::FRC:
	default:
		m_encoder = new Encoder(A, B, false, Encoder::EncodingType::k4X);
		break;
	}
}

bool EncoderSubsystem::SetPosition(double position, double speed)
{

	m_positionPID.SetSetpoint(position);

	double output = m_positionPID.Calculate(GetPosition() * m_positionPIDDirection);

	SetMotor(output * speed);

	return m_positionPID.AtSetpoint();
}

double EncoderSubsystem::GetPosition()
{
	switch (m_encoderConfig)
	{
	case EncoderConfig::REV:
		return m_encoderSpark->GetPosition() * m_encoderDirection;
		break;

	case EncoderConfig::FRC:
	default:
		return m_encoder->Get();
		break;
	}
}

void EncoderSubsystem::ConfigurePositionPID(double p, double i, double d, double tolerance, bool inverted)
{
	m_positionPID.SetPID(p, i, d);
	m_positionPID.SetTolerance(tolerance);
	m_positionPIDDirection = inverted ? -1 : 1;
}

void EncoderSubsystem::SetPositionConversionFactor(double conversionFactor)
{
	switch (m_encoderConfig)
	{
	case EncoderConfig::REV:
		m_encoderSpark->SetPositionConversionFactor(conversionFactor);
		break;

	case EncoderConfig::FRC:
	default:
		m_encoder->SetDistancePerPulse(conversionFactor);
		break;
	}
}

void EncoderSubsystem::ResetPositionPID()
{
	m_positionPID.Reset();
}

void EncoderSubsystem::PrintPosition()
{
	SmartDashboard::PutNumber(GetName() + " Encoder Position", GetPosition());
}

void EncoderSubsystem::PrintPositionError()
{
	SmartDashboard::PutNumber(GetName() + " Encoder Position Error", m_positionPID.GetPositionError());
}

void EncoderSubsystem::SetPositionSafety(bool active)
{
	m_positionSafetyActive = active;
}

bool EncoderSubsystem::SetRPM(double speed, double acceleration)
{
	m_RPMPID.SetSetpoint(speed);

	double output = m_RPMPID.Calculate(GetPosition() * m_RPMPIDDirection);

	SetMotor(output * acceleration);

	return m_positionPID.AtSetpoint();
}

double EncoderSubsystem::GetRPM()
{
	switch (m_encoderConfig)
	{
	case EncoderConfig::REV:
		return m_encoderSpark->GetVelocity() * m_encoderDirection;
		break;

	case EncoderConfig::FRC:
	default:
		return m_encoder->GetRate() * m_RPMConversionFactor;
		break;
	}
}

void EncoderSubsystem::ConfigureRPMPID(double p, double i, double d, double tolerance, bool inverted)
{
	m_RPMPID.SetPID(p, i, d);
	m_RPMPID.SetTolerance(tolerance);
	m_RPMPIDDirection = inverted ? -1 : 1;
}

void EncoderSubsystem::SetRPMConversionFactor(double conversionFactor)
{
	switch (m_encoderConfig)
	{
	case EncoderConfig::REV:
		m_encoderSpark->SetVelocityConversionFactor(conversionFactor);
		break;

	case EncoderConfig::FRC:
	default:
		m_RPMConversionFactor = conversionFactor;
		break;
	}
}

void EncoderSubsystem::ResetRPMPID()
{
	m_RPMPID.Reset();
}

void EncoderSubsystem::PrintRPM()
{
	SmartDashboard::PutNumber(GetName() + " Encoder Speed", GetRPM());
}

void EncoderSubsystem::PrintRPMError()
{
	SmartDashboard::PutNumber(GetName() + " Encoder Speed Error", m_RPMPID.GetPositionError());
}

void EncoderSubsystem::SetMinMaxPosition(double min, double max)
{
	m_minPosition = min;
	m_maxPosition = max;
}