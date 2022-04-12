#include "subsystems/ShooterBase.h"

ShooterBase::ShooterBase(MotorConfig mconfig, unsigned int mport) : EncoderSubsystem(mconfig, mport), MotorSubsystem(mconfig, mport)
{
	SetName("Shooter");
}

ShooterBase::ShooterBase(MotorConfig mconfig, EncoderConfig econfig, unsigned int mport) : EncoderSubsystem(mconfig, econfig, mport), MotorSubsystem(mconfig, mport)
{
	SetName("Shooter");
}

ShooterBase::ShooterBase(MotorConfig mconfig, EncoderConfig econfig, unsigned int mport, unsigned int encoderA, unsigned int encoderB) : EncoderSubsystem(mconfig, econfig, mport, encoderA, encoderB), MotorSubsystem(mconfig, mport)
{
	SetName("Shooter");
}

void ShooterBase::Periodic()
{
}

void ShooterBase::Reset()
{
	ResetEncoder();
	ResetSpeedPID();
	ResetServos();
	SolenoidsOff();
}

double ShooterBase::CalculateRPM()
{
	return m_rpmCalculationFunction(m_limelight.GetDistanceToTarget());
}

void ShooterBase::SetAngleServos(double angle)
{
	m_rightServo->Set(angle);
	m_leftServo->Set(angle);
}

void ShooterBase::ResetServos()
{
	m_rightServo->Set(0);
	m_leftServo->Set(0);
}

void ShooterBase::ConfigureServos(unsigned int rightPort, unsigned int leftPort)
{
	m_rightServo = new Servo(rightPort);
	m_leftServo = new Servo(leftPort);
}

double ShooterBase::GetRightServo()
{
	return m_rightServo->Get();
}

double ShooterBase::GetLeftServo()
{
	return m_leftServo->Get();
}

void ShooterBase::PrintServos()
{
	SmartDashboard::PutNumber(GetName() + " Right Servo", GetRightServo());
	SmartDashboard::PutNumber(GetName() + " Left Servo", GetLeftServo());
}

void ShooterBase::Shoot()
{
	SetMotor(1);
}
