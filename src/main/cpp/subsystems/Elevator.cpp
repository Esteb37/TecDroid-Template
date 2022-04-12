#include "subsystems/Elevator.h"

Elevator::Elevator(MotorConfig mconfig, unsigned int motorPort)
	: EncoderSubsystem(mconfig, motorPort), MotorSubsystem(mconfig, motorPort)
{
	SetName("Elevator");
}

Elevator::Elevator(MotorConfig mconfig, vector<unsigned int> motorPorts)
	: EncoderSubsystem(mconfig, motorPorts), MotorSubsystem(mconfig, motorPorts)
{
	SetName("Elevator");
}

Elevator::Elevator(MotorConfig mconfig, EncoderConfig econfig, unsigned int mport) : EncoderSubsystem(mconfig, econfig, mport), MotorSubsystem(mconfig, mport)
{
	SetName("Elevator");
}

Elevator::Elevator(MotorConfig mconfig, EncoderConfig econfig, vector<unsigned int> mports) : EncoderSubsystem(mconfig, econfig, mports), MotorSubsystem(mconfig, mports)
{
	SetName("Elevator");
}

Elevator::Elevator(MotorConfig mconfig, EncoderConfig econfig, unsigned int mport, unsigned int encoderA, unsigned int encoderB) : EncoderSubsystem(mconfig, econfig, mport, encoderA, encoderB), MotorSubsystem(mconfig, mport)
{
	SetName("Elevator");
}

Elevator::Elevator(MotorConfig mconfig, EncoderConfig econfig, vector<unsigned int> mports, unsigned int encoderA, unsigned int encoderB) : EncoderSubsystem(mconfig, econfig, mports, encoderA, encoderB), MotorSubsystem(mconfig, mports)
{
	SetName("Elevator");
}

void Elevator::Periodic()
{
}

// ---------- Actions -----------

void Elevator::Move(double speed)
{
	if (m_motorCount > 1)
	{
		vector<double> speeds(m_motorCount, speed);
		SetMotors(speeds);
	}

	else
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