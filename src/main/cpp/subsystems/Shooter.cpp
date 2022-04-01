#include "subsystems/Shooter.h"

Shooter::Shooter()
{
	m_PIDController.SetTolerance(k_shooterPIDTolerance);
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

void Shooter::SetMotor(double speed)
{
	m_motor.Set(speed * k_shooterMaxSpeed);
}

double Shooter::GetMotor()
{
	return m_motor.Get();
}

void Shooter::InvertMotor(bool inverted)
{
	m_motor.SetInverted(inverted);
}

void Shooter::PrintMotor()
{
	SmartDashboard::PutNumber("Shooter Motor", GetMotor());
}

double Shooter::GetEncoder()
{
	return m_encoder.GetVelocity();

	// TODO : change if normal encoder
	// return m_encoder.GetRate()
}

void Shooter::ResetEncoder()
{
	m_encoder.SetPosition(0);

	// TODO : change if normal encoder
	// m_encoder.Reset();
}

void Shooter::InvertEncoder(bool inverted)
{
	m_encoder.SetInverted(inverted);

	// TODO : change if normal encoder
	// m_encoder.SetReverseDirection(inverted);
}

void Shooter::PrintEncoder()
{
	SmartDashboard::PutNumber("Shooter Encoder", GetEncoder());
}

bool Shooter::ReachRPM(double rpm)
{
	m_PIDController.SetSetpoint(rpm);

	double output = m_PIDController.Calculate(GetEncoder());

	SetMotor(std::clamp(output, -k_shooterMaxSpeed, k_shooterMaxSpeed));

	return m_PIDController.AtSetpoint();
}

double Shooter::CalculateRPM()
{
	return shooterRPMFromDistance(m_limelight.GetDistanceToTarget());
}

void Shooter::ResetPID()
{
	m_PIDController.Reset();
}

void Shooter::PrintPIDError()
{
	SmartDashboard::PutNumber("Shooter PID Error", m_PIDController.GetVelocityError());
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
	if (forward ^ m_solenoidsInverted)
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
