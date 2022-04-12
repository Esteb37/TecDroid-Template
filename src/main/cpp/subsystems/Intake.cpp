#include "subsystems/Intake.h"

using namespace frc;

Intake::Intake(MotorConfig config, unsigned int port) : MotorSubsystem(config, port)
{
	SetName("Intake");
}

Intake::Intake(MotorConfig config, unsigned int port, unsigned int solenoidA, unsigned int solenoidB) : MotorSubsystem(config, port), SolenoidSubsystem(solenoidA, solenoidB)
{
	SetName("Intake");
}

Intake::Intake(MotorConfig config, unsigned int port, unsigned int rightA, unsigned int rightB, unsigned int leftA, unsigned int leftB) : MotorSubsystem(config, port), SolenoidSubsystem(rightA, rightB, leftA, leftB)
{
	SetName("Intake");
}

void Intake::Periodic()
{
}

void Intake::Take()
{
	SetMotor(1);
}

void Intake::Spit()
{
	SetMotor(-1);
}

void Intake::Lower()
{
	OpenSolenoids();
}

void Intake::Raise()
{
	CloseSolenoids();
}
