#include "subsystems/Shooter.h"

Shooter::Shooter()
{
}

void Shooter::Periodic()
{
}

void Shooter::Reset()
{
	ResetEncoder();
	ResetServos();
	SolenoidsOff();
}

bool Shooter::Shoot()
{
	return false;
}

void Shooter::SetMotor(double speed)
{
}

double Shooter::GetMotor()
{
	return 0;
}

void Shooter::InvertMotor(bool inverted)
{
}

void Shooter::PrintMotor()
{
	SmartDashboard::PutNumber("Shooter Motor", GetMotor());
}

double Shooter::GetEncoder()
{
	return 0;
}

void Shooter::ResetEncoder()
{
}

void Shooter::InvertEncoder(bool inverted)
{
}

void Shooter::PrintEncoder()
{
	SmartDashboard::PutNumber("Shooter Encoder", GetEncoder());
}

bool Shooter::ReachRPM(double rpm)
{
	return false;
}

double Shooter::CalculateRPM()
{
	return 0;
}

void Shooter::ResetPID()
{
}

void Shooter::PrintPIDError()
{
}

void Shooter::SetAngleServos(double angle)
{
	m_rightServo.Set(angle);
	m_leftServo.Set(angle);
}

void Shooter::ResetServos()
{
	m_rightServo.Set(0);
	m_leftServo.Set(0);
}

double Shooter::GetRightServo()
{
	return m_rightServo.Get();
}

double Shooter::GetLeftServo()
{
	return m_leftServo.Get();
}

void Shooter::PrintServos()
{
	SmartDashboard::PutNumber("Shooter Right Servo", GetRightServo());
	SmartDashboard::PutNumber("Shooter Left Servo", GetLeftServo());
}

void Shooter::SetAngleSolenoids(bool forward)
{
	if (forward)
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

void Shooter::SolenoidsOff()
{
	m_rightSolenoid.Set(DoubleSolenoid::Value::kOff);
	m_leftSolenoid.Set(DoubleSolenoid::Value::kOff);
}

bool Shooter::GetRightSolenoid()
{
	return m_rightSolenoid.Get();
}

bool Shooter::GetLeftSolenoid()
{
	return m_leftSolenoid.Get();
}

void Shooter::PrintSolenoids()
{
	SmartDashboard::PutBoolean("Shooter Right Solenoid", GetRightSolenoid());
	SmartDashboard::PutBoolean("Shooter Left Solenoid", GetLeftSolenoid());
}
