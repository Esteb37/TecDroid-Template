#include "subsystems/Feeder.h"

Feeder::Feeder()
{
}

void Feeder::Periodic()
{
}

void Feeder::SetMotor(double speed)
{
	motor.Set(speed * k_feederMaxSpeed);
}

double Feeder::GetMotor()
{
	return motor.Get();
}

void Feeder::InvertMotor(bool inverted)
{
	motor.SetInverted(inverted);
}

void Feeder::PrintMotor()
{
	SmartDashboard::PutNumber("Feeder Motor", GetMotor());
}
