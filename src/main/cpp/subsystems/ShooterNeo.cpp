#include "subsystems/ShooterNeo.h"

ShooterNeo::ShooterNeo()
{
}

void ShooterNeo::Periodic()
{
}

void ShooterNeo::SetMotor(double speed)
{
	m_motor.Set(speed);
}

double ShooterNeo::GetMotor()
{
	return m_motor.Get();
}

void ShooterNeo::InvertMotor(bool inverted)
{
	m_motor.SetInverted(inverted);
}

void ShooterNeo::ResetMotor()
{
	m_motor.RestoreFactoryDefaults();
}

double ShooterNeo::GetEncoder()
{
	return m_encoder.GetPosition();
}

void ShooterNeo::ResetEncoder()
{
	m_encoder.SetPosition(0);
}

void ShooterNeo::InvertEncoder(bool inverted)
{
	m_encoder.SetInverted(inverted);
}
