#include "subsystems/Intake.h"

using namespace frc;

Intake::Intake()
{
}

void Intake::Periodic()
{
}

void Intake::SetMotor(double speed)
{
	m_motor.Set(speed * k_intakeMaxSpeed);
}

double Intake::GetMotor()
{
	return m_motor.Get();
}

void Intake::InvertMotor(bool inverted)
{
	m_motor.SetInverted(inverted);
}

void Intake::PrintMotor()
{
	SmartDashboard::PutNumber("Intake Motor", GetMotor());
}

void Intake::Take()
{
	SetMotor(1);
}

void Intake::Spit()
{
	SetMotor(-1);
}

void Intake::Lower()
{
	if (m_solenoidsInverted)
	{
		m_rightSolenoid.Set(DoubleSolenoid::Value::kForward);
		m_leftSolenoid.Set(DoubleSolenoid::Value::kForward);
	}
	else
	{
		m_rightSolenoid.Set(DoubleSolenoid::Value::kReverse);
		m_leftSolenoid.Set(DoubleSolenoid::Value::kReverse);
	}
}

void Intake::Raise()
{
	if (!m_solenoidsInverted)
	{
		m_rightSolenoid.Set(DoubleSolenoid::Value::kForward);
		m_leftSolenoid.Set(DoubleSolenoid::Value::kForward);
	}
	else
	{
		m_rightSolenoid.Set(DoubleSolenoid::Value::kReverse);
		m_leftSolenoid.Set(DoubleSolenoid::Value::kReverse);
	}
}

void Intake::SolenoidsOff()
{
	m_rightSolenoid.Set(DoubleSolenoid::Value::kOff);
	m_leftSolenoid.Set(DoubleSolenoid::Value::kOff);
}

unsigned int Intake::GetRightSolenoid()
{
	return m_rightSolenoid.Get();
}

unsigned int Intake::GetLeftSolenoid()
{
	return m_leftSolenoid.Get();
}

void Intake::PrintSolenoids()
{
	SmartDashboard::PutNumber("Intake Right Solenoid", GetRightSolenoid());
	SmartDashboard::PutNumber("Intake Left Solenoid", GetLeftSolenoid());
}
