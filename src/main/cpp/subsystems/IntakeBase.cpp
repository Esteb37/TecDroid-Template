#include "subsystems/IntakeBase.h"

using namespace TecDroid;

IntakeBase::IntakeBase(MotorConfig config, unsigned int port) : MotorSubsystem(config, port)
{
	SetName("Intake");
}

IntakeBase::IntakeBase(MotorConfig config, vector<unsigned int> ports) : MotorSubsystem(config, ports)
{
	SetName("Intake");
}

IntakeBase::IntakeBase(MotorConfig config, unsigned int port, unsigned int solenoidA, unsigned int solenoidB) : MotorSubsystem(config, port), SolenoidSubsystem(solenoidA, solenoidB)
{
	SetName("Intake");
}

IntakeBase::IntakeBase(MotorConfig config, vector<unsigned int> ports, unsigned int solenoidA, unsigned int solenoidB) : MotorSubsystem(config, ports), SolenoidSubsystem(solenoidA, solenoidB)
{
	SetName("Intake");
}

IntakeBase::IntakeBase(MotorConfig config, unsigned int port, unsigned int rightA, unsigned int rightB, unsigned int leftA, unsigned int leftB) : MotorSubsystem(config, port), SolenoidSubsystem(rightA, rightB, leftA, leftB)
{
	SetName("Intake");
}

IntakeBase::IntakeBase(MotorConfig config, vector<unsigned int> ports, unsigned int rightA, unsigned int rightB, unsigned int leftA, unsigned int leftB) : MotorSubsystem(config, ports), SolenoidSubsystem(rightA, rightB, leftA, leftB)
{
	SetName("Intake");
}

void IntakeBase::Periodic()
{
}

void IntakeBase::Take()
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

void IntakeBase::Spit()
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

void IntakeBase::Lower()
{
	OpenSolenoids();
}

void IntakeBase::Raise()
{
	CloseSolenoids();
}
