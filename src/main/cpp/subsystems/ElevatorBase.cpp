#include "subsystems/ElevatorBase.h"

ElevatorBase::ElevatorBase(MotorConfig mconfig, unsigned int motorPort)
	: EncoderSubsystem(mconfig, motorPort), MotorSubsystem(mconfig, motorPort)
{
	SetName("Elevator");
}

ElevatorBase::ElevatorBase(MotorConfig mconfig, vector<unsigned int> motorPorts)
	: EncoderSubsystem(mconfig, motorPorts), MotorSubsystem(mconfig, motorPorts)
{
	SetName("Elevator");
}

ElevatorBase::ElevatorBase(MotorConfig mconfig, EncoderConfig econfig, unsigned int mport) : EncoderSubsystem(mconfig, econfig, mport), MotorSubsystem(mconfig, mport)
{
	SetName("Elevator");
}

ElevatorBase::ElevatorBase(MotorConfig mconfig, EncoderConfig econfig, vector<unsigned int> mports) : EncoderSubsystem(mconfig, econfig, mports), MotorSubsystem(mconfig, mports)
{
	SetName("Elevator");
}

ElevatorBase::ElevatorBase(MotorConfig mconfig, EncoderConfig econfig, unsigned int mport, unsigned int encoderA, unsigned int encoderB) : EncoderSubsystem(mconfig, econfig, mport, encoderA, encoderB), MotorSubsystem(mconfig, mport)
{
	SetName("Elevator");
}

ElevatorBase::ElevatorBase(MotorConfig mconfig, EncoderConfig econfig, vector<unsigned int> mports, unsigned int encoderA, unsigned int encoderB) : EncoderSubsystem(mconfig, econfig, mports, encoderA, encoderB), MotorSubsystem(mconfig, mports)
{
	SetName("Elevator");
}

void ElevatorBase::Periodic()
{
}

// ---------- Actions -----------

void ElevatorBase::Move(double speed)
{
	if (m_motorCount > 1)
	{
		vector<double> speeds(m_motorCount, speed);
		SetMotors(speeds);
	}

	else
		SetMotor(speed);
}

void ElevatorBase::SetHeightToFloor(double height)
{
	m_heightToFloor = height;
}

double ElevatorBase::GetRelativeHeight()
{
	return GetPosition();
}

double ElevatorBase::GetAbsoluteHeight()
{
	return GetPosition() + m_heightToFloor;
}

bool ElevatorBase::SetRelativeHeight(double height, bool inverted)
{
	return SetPosition(height, inverted);
}

bool ElevatorBase::SetAbsoluteHeight(double height, bool inverted)
{
	return SetPosition(height - m_heightToFloor, inverted);
}

void ElevatorBase::SetMinMaxHeight(double min, double max)
{
	return SetMinMaxPosition(min, max);
}