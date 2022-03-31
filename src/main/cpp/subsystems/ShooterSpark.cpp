#include "subsystems/ShooterSpark.h"

ShooterSpark::ShooterSpark()
{
}

void ShooterSpark::Periodic()
{
}

void ShooterSpark::SetMotor(double speed)
{
	m_motor.Set(speed);
}

double ShooterSpark::GetMotor()
{
	return m_motor.Get();
}

void ShooterSpark::InvertMotor(bool inverted)
{
	m_motor.SetInverted(inverted);
}

double ShooterSpark::GetEncoder()
{
	return m_encoder.GetDirection();
}

void ShooterSpark::ResetEncoder()
{
	m_encoder.Reset();
}

void ShooterSpark::InvertEncoder(bool inverted)
{
	m_encoder.SetReverseDirection(inverted);
}
