#include "subsystems/Intake.h"
#include <frc/smartdashboard/SmartDashboard.h>

using namespace frc;

template <>
Intake<CANSparkMax>::Intake()
{

	m_motor = new CANSparkMax(pIntakeMotor, CANSparkMax::MotorType::kBrushed);
}

template <>
Intake<VictorSP>::Intake()
{
	m_motor = new VictorSP(pIntakeMotor);
}

template <typename MotorType>
void Intake<MotorType>::Periodic()
{
}

template <typename MotorType>
void Intake<MotorType>::SetMotor(double speed)
{
	m_motor->Set(speed * k_intakeMaxSpeed);
}

template <typename MotorType>
double Intake<MotorType>::GetMotor()
{
	return m_motor->Get();
}

template <typename MotorType>
void Intake<MotorType>::InvertMotor(bool inverted)
{
	m_motor->SetInverted(inverted);
}

template <typename MotorType>
void Intake<MotorType>::PrintMotor()
{
	SmartDashboard::PutNumber("Intake Motor", GetMotor());
}

template <typename MotorType>
void Intake<MotorType>::Take()
{
	SetMotor(1);
}

template <typename MotorType>
void Intake<MotorType>::Spit()
{
	SetMotor(-1);
}

template <typename MotorType>
void Intake<MotorType>::Lower()
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

template <typename MotorType>
void Intake<MotorType>::Raise()
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

template <typename MotorType>
void Intake<MotorType>::SolenoidsOff()
{
	m_rightSolenoid.Set(DoubleSolenoid::Value::kOff);
	m_leftSolenoid.Set(DoubleSolenoid::Value::kOff);
}

template <typename MotorType>
bool Intake<MotorType>::GetRightSolenoid()
{
	return m_rightSolenoid.Get();
}

template <typename MotorType>
bool Intake<MotorType>::GetLeftSolenoid()
{
	return m_leftSolenoid.Get();
}

template <typename MotorType>
void Intake<MotorType>::PrintSolenoids()
{
	SmartDashboard::PutBoolean("Intake Right Solenoid", GetRightSolenoid());
	SmartDashboard::PutBoolean("Intake Left Solenoid", GetLeftSolenoid());
}
