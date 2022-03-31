#include "subsystems/Shooter.h"

template <typename MotorType, typename EncoderType>
Shooter<MotorType, EncoderType>::Shooter()
{
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::Periodic()
{
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::Reset()
{

	ResetEncoder();
	ResetServos();
	ResetSolenoids();
}

template <typename MotorType, typename EncoderType>
bool Shooter<MotorType, EncoderType>::Shoot()
{
	return false;
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::SetMotor(double speed)
{
	m_motor.Set(speed);
}

template <typename MotorType, typename EncoderType>
double Shooter<MotorType, EncoderType>::GetMotor()
{
	m_motor.Get();
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::InvertMotor(bool inverted)
{
	m_motor.SetInverted(inverted);
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::ResetMotor()
{
	m_motor.Reset();
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::PrintMotor()
{
	SmartDashboard::PutNumber("Shooter Motor", GetMotor());
}

template <typename MotorType, typename EncoderType>
double Shooter<MotorType, EncoderType>::GetEncoder()
{
	return 0;
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::ResetEncoder()
{
	m_encoder.Reset();
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::InvertEncoder(bool inverted)
{
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::PrintEncoder()
{
	SmartDashboard::PutNumber("Shooter Encoder", GetEncoder());
}

template <typename MotorType, typename EncoderType>
bool Shooter<MotorType, EncoderType>::ReachRPM(double rpm)
{
	return false;
}

template <typename MotorType, typename EncoderType>
double Shooter<MotorType, EncoderType>::CalculateRPM()
{
	return 0;
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::ResetPID()
{
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::PrintPIDError()
{
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::SetAngleServos(double angle)
{
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::SetServos(double angle)
{
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::ResetServos()
{
}

template <typename MotorType, typename EncoderType>
double Shooter<MotorType, EncoderType>::GetServos()
{
	return 0;
}

template <typename MotorType, typename EncoderType>
double Shooter<MotorType, EncoderType>::GetRightServo()
{
	return 0;
}

template <typename MotorType, typename EncoderType>
double Shooter<MotorType, EncoderType>::GetLeftServo()
{
	return 0;
}
template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::PrintRightServo()
{
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::PrintLeftServo()
{
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::PrintServos()
{
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::SetAngleSolenoids(bool forward)
{
}

template <typename MotorType, typename EncoderType>
bool Shooter<MotorType, EncoderType>::GetRightSolenoid()
{
	return false;
}

template <typename MotorType, typename EncoderType>
bool Shooter<MotorType, EncoderType>::GetLeftSolenoid()
{
	return false;
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::PrintSolenoids()
{
}
