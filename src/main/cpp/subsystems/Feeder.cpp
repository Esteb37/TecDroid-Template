#include "subsystems/Feeder.h"

Feeder::Feeder(MotorConfig config, unsigned int motorPort) : MotorSubsystem(config, motorPort)
{
	SetName("Feeder");
}

Feeder::Feeder(MotorConfig config, vector<unsigned int> motorPorts) : MotorSubsystem(config, motorPorts)
{
	SetName("Feeder");
}

void Feeder::Periodic()
{
}

void Feeder::Feed()
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

void Feeder::Unfeed()
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