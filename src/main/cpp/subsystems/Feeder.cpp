#include "subsystems/Feeder.h"

Feeder::Feeder(MotorConfig config, unsigned int motorPort) : MotorSubsystem(config, motorPort)
{
	SetName("Feeder");
}

void Feeder::Periodic()
{
}

void Feeder::Feed()
{
	SetMotor(1);
}

void Feeder::Unfeed()
{
	SetMotor(-1);
}