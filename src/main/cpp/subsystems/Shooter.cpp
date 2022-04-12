#include "subsystems/Shooter.h"

Shooter::Shooter(MotorConfig mconfig, unsigned int mport) : EncoderSubsystem(mconfig, mport), MotorSubsystem(mconfig, mport)
{
	SetName("Shooter");
}

Shooter::Shooter(MotorConfig mconfig, EncoderConfig econfig, unsigned int mport) : EncoderSubsystem(mconfig, econfig, mport), MotorSubsystem(mconfig, mport)
{
	SetName("Shooter");
}

Shooter::Shooter(MotorConfig mconfig, EncoderConfig econfig, unsigned int mport, unsigned int encoderA, unsigned int encoderB) : EncoderSubsystem(mconfig, econfig, mport, encoderA, encoderB), MotorSubsystem(mconfig, mport)
{
	SetName("Shooter");
}

void Shooter::Periodic()
{
}

void Shooter::Reset()
{
	ResetEncoder();
	ResetSpeedPID();
	ResetServos();
	SolenoidsOff();
}

double Shooter::CalculateRPM()
{
	return shooterRPMFromDistance(m_limelight.GetDistanceToTarget());
}

void Shooter::SetAngleServos(double angle)
{
	m_rightServo->Set(angle);
	m_leftServo->Set(angle);
}

void Shooter::ResetServos()
{
	m_rightServo->Set(0);
	m_leftServo->Set(0);
}

void Shooter::ConfigureServos(unsigned int rightPort, unsigned int leftPort)
{
	m_rightServo = new Servo(rightPort);
	m_leftServo = new Servo(leftPort);
}

double Shooter::GetRightServo()
{
	return m_rightServo->Get();
}

double Shooter::GetLeftServo()
{
	return m_leftServo->Get();
}

void Shooter::PrintServos()
{
	SmartDashboard::PutNumber(GetName() + " Right Servo", GetRightServo());
	SmartDashboard::PutNumber(GetName() + " Left Servo", GetLeftServo());
}

void Shooter::Shoot()
{
	SetMotor(1);
}

Limelight Shooter::GetLimelight()
{
	return m_limelight;
}
