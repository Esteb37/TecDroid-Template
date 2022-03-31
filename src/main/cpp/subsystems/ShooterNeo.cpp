#include <subsystems/ShooterNeo.h>

ShooterNeo::ShooterNeo()
{
}

double ShooterNeo::GetEncoder()
{
	return m_encoder.GetPosition();
}

void ShooterNeo::InvertEncoder(bool inverted)
{
	m_encoder.SetInverted(inverted)
}

bool ShooterNeo::ReachRPM(double rpm)
{
}

double ShooterNeo::CalculateRPM()
{
}

void ShooterNeo::ResetPID()
{
}

void ShooterNeo::PrintPIDError()
{
}
