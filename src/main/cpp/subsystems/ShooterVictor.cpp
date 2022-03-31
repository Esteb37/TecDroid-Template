#include "subsystems/ShooterVictor.h"

ShooterVictor::ShooterVictor()
{
}

void ShooterVictor::Periodic()
{
}

void ShooterVictor::SetMotor(double speed)
{
	m_motor.Set(speed);
}

double ShooterVictor::GetMotor()
{
	return m_motor.Get();
}

void ShooterVictor::InvertMotor(bool inverted)
{
	m_motor.SetInverted(inverted);
}

double ShooterVictor::GetEncoder()
{
	return m_encoder.GetDirection();
}

void ShooterVictor::ResetEncoder()
{
	m_encoder.Reset();
}

void ShooterVictor::InvertEncoder(bool inverted)
{
	m_encoder.SetReverseDirection(inverted);
}
