#include "subsystems/Feeder.h"

Feeder::Feeder(MotorConfig config, unsigned int motorPort) : MotorSubsystem(config, motorPort)
{
}

void Feeder::Periodic()
{
}

void Feeder::Feed()
{
	SetMotor(k_feederMaxSpeed);
}

void Feeder::Unfeed()
{
	SetMotor(-k_feederMaxSpeed);
}