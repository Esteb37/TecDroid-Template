#include "subsystems/Elevator.h"

Elevator::Elevator(MotorConfig mconfig, EncoderConfig econfig, unsigned int mport) : EncoderSubsystem(mconfig, econfig, mport), MotorSubsystem(mconfig, mport)
{
	SetName("Elevator");
}

Elevator::Elevator(MotorConfig mconfig, EncoderConfig econfig, unsigned int mport, unsigned int encoderA, unsigned int encoderB) : EncoderSubsystem(mconfig, econfig, mport, encoderA, encoderB), MotorSubsystem(mconfig, mport)
{
	SetName("Elevator");
}

void Elevator::Periodic()
{
}

// ---------- Actions -----------

void Elevator::Move(double speed)
{
	SetMotor(speed);
}

void Elevator::SetHeightToFloor(double height)
{
	m_heightToFloor = height;
}

double Elevator::GetRelativeHeight()
{
	return GetPosition();
}

double Elevator::GetAbsoluteHeight()
{
	return GetPosition() + m_heightToFloor;
}

bool Elevator::SetRelativeHeight(double height, bool inverted)
{
	return SetPosition(height, inverted);
}

bool Elevator::SetAbsoluteHeight(double height, bool inverted)
{
	return SetPosition(height - m_heightToFloor, inverted);
}