#include "subsystems/FeederBase.h"

FeederBase::FeederBase(MotorConfig config, unsigned int motorPort) : MotorSubsystem(config, motorPort)
{
	SetName("Feeder");
}

FeederBase::FeederBase(MotorConfig config, vector<unsigned int> motorPorts) : MotorSubsystem(config, motorPorts)
{
	SetName("Feeder");
}

void FeederBase::Periodic()
{
}

void FeederBase::Feed()
{
	if (m_motorCount > 1)
	{
		vector<double> speeds(m_motorCount, 1.0);
		SetMotors(speeds);
	}
	else
	{
		SetMotor(1);
	}
}

void FeederBase::Unfeed()
{
	if (m_motorCount > 1)
	{
		vector<double> speeds(m_motorCount, -1.0);
		SetMotors(speeds);
	}
	else
	{
		SetMotor(-1);
	}
}