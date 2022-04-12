#include "subsystems/EncoderSubsystem.h"

EncoderSubsystem::EncoderSubsystem(MotorConfig motorConfig, unsigned int motorPort)
	: MotorSubsystem(motorConfig, motorPort)
{
	SetName("EncoderSubsystem");
}

EncoderSubsystem::EncoderSubsystem(MotorConfig motorConfig, vector<unsigned int> motorPorts)
	: MotorSubsystem(motorConfig, motorPorts)
{
	SetName("EncoderSubsystem");
}

EncoderSubsystem::EncoderSubsystem(MotorConfig motorConfig, EncoderConfig encoderConfig, unsigned int motorPort)
	: MotorSubsystem(motorConfig, motorPort)
{
	m_encoderConfig = encoderConfig;

	if (motorConfig == MotorConfig::kNeo && encoderConfig == EncoderConfig::kRev)
	{
		m_encoderSpark = new SparkMaxRelativeEncoder(m_motorSpark->GetEncoder());
	}
	else
	{
		throw std::invalid_argument("Encoder must be Spark and Motor must be Neo");
	}

	SetName("EncoderSubsystem");
}

EncoderSubsystem::EncoderSubsystem(MotorConfig motorConfig, EncoderConfig encoderConfig, vector<unsigned int> motorPorts)
	: MotorSubsystem(motorConfig, motorPorts)
{
	m_encoderConfig = encoderConfig;

	if (motorConfig == MotorConfig::kNeo && encoderConfig == EncoderConfig::kRev)
	{
		m_encoderSpark = new SparkMaxRelativeEncoder(m_motorSparkList[0]->GetEncoder());
	}
	else
	{
		throw std::invalid_argument("Encoder must be Spark and Motor must be Neo");
	}

	SetName("EncoderSubsystem");
}

EncoderSubsystem::EncoderSubsystem(MotorConfig motorConfig, EncoderConfig encoderConfig, unsigned int motorPort, unsigned int encoderA, unsigned int encoderB)
	: MotorSubsystem(motorConfig, motorPort)
{
	if (encoderConfig == EncoderConfig::kRev)
	{
		throw std::invalid_argument("Encoder must be FRC");
	}

	m_encoderConfig = encoderConfig;

	m_encoder = new Encoder(encoderA, encoderB, false, Encoder::EncodingType::k4X);

	SetName("EncoderSubsystem");
}

EncoderSubsystem::EncoderSubsystem(MotorConfig motorConfig, EncoderConfig encoderConfig, vector<unsigned int> motorPorts, unsigned int encoderA, unsigned int encoderB)
	: MotorSubsystem(motorConfig, motorPorts)
{

	if (encoderConfig == EncoderConfig::kRev)
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
	ResetSpeedPID();
}

void EncoderSubsystem::SetMotor(double speed)
{

	if (m_motorCount > 1)
	{
		throw std::invalid_argument("EncoderSubsystem: SetMotor() does not support multiple motors.");
	}

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

void EncoderSubsystem::SetMotors(vector<double> speeds)
{

	if (m_motorCount != speeds.size())
	{
		throw std::invalid_argument("EncoderSubsystem: Speed vector must be the same size as the number of motors.");
	}
	else if (m_motorCount <= 1)
	{
		throw std::invalid_argument("EncoderSubsystem: This subsystem has only one motor. Use SetMotor() instead.");
	}

	for (int i = 0; i < speeds.size(); i++)
	{
		double speed = speeds[i];
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
				speeds[i] = fmin(speed, 0);
			}
			else if (GetPosition() <= m_minPosition)
			{
				speeds[i] = fmax(speed, 0);
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

bool EncoderSubsystem::SetPosition(double position, double speed)
{

	m_positionPID->SetSetpoint(position);

	double output = m_positionPID->Calculate(GetPosition() * m_positionPIDDirection);

	SetMotor(output * speed);

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

void EncoderSubsystem::ConfigurePositionPID(double p, double i, double d, double tolerance, bool inverted)
{
	m_positionPID->SetPID(p, i, d);
	m_positionPID->SetTolerance(tolerance);
	m_positionPIDDirection = inverted ? -1 : 1;
}

void EncoderSubsystem::SetPositionConversionFactor(double conversionFactor)
{
	switch (m_encoderConfig)
	{
	case EncoderConfig::kRev:
		m_encoderSpark->SetPositionConversionFactor(conversionFactor);
		break;

	case EncoderConfig::kFrc:
		m_encoder->SetDistancePerPulse(conversionFactor);
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

bool EncoderSubsystem::SetSpeed(double speed, double acceleration)
{
	m_speedPID->SetSetpoint(speed);

	double output = m_speedPID->Calculate(GetPosition() * m_speedPIDDirection);

	SetMotor(output * acceleration);

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
		return m_encoder->GetRate() * m_speedConversionFactor;
		break;
	}
}

void EncoderSubsystem::ConfigureSpeedPID(double p, double i, double d, double tolerance, bool inverted)
{
	m_speedPID->SetPID(p, i, d);
	m_speedPID->SetTolerance(tolerance);
	m_speedPIDDirection = inverted ? -1 : 1;
}

void EncoderSubsystem::SetSpeedConversionFactor(double conversionFactor)
{
	switch (m_encoderConfig)
	{
	case EncoderConfig::kRev:
		m_encoderSpark->SetVelocityConversionFactor(conversionFactor);
		break;

	case EncoderConfig::kFrc:
		m_speedConversionFactor = conversionFactor;
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

void EncoderSubsystem::SetMinMaxPosition(double min, double max)
{
	m_minPosition = min;
	m_maxPosition = max;
}