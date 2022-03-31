#include "subsystems/Shooter.h"

template <>
Shooter<CANSparkMax, SparkMaxRelativeEncoder>::Shooter()
{
	m_motor = new CANSparkMax(pShooterMotor, CANSparkMax::MotorType::kBrushless);

	m_encoder = new SparkMaxRelativeEncoder(m_motor->GetEncoder());

	m_PIDController.SetTolerance(k_shooterPIDTolerance);
}

template <>
Shooter<CANSparkMax, Encoder>::Shooter()
{
	m_motor = new CANSparkMax(pShooterMotor, CANSparkMax::MotorType::kBrushed);

	m_encoder = new Encoder(pShooterEncoderA, pShooterEncoderB, false, Encoder::EncodingType::k4X);

	m_PIDController.SetTolerance(k_shooterPIDTolerance);
}

template <>
Shooter<VictorSP, Encoder>::Shooter()
{
	m_motor = new VictorSP(pShooterMotor);

	m_encoder = new Encoder(pShooterEncoderA, pShooterEncoderB, false, Encoder::EncodingType::k4X);

	m_PIDController.SetTolerance(k_shooterPIDTolerance);
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
	SolenoidsOff();
}

template <typename MotorType, typename EncoderType>
bool Shooter<MotorType, EncoderType>::Shoot()
{
	if (ReachRPM(CalculateRPM()))
	{
		return true; // TODO feeder.feed
	}
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::SetMotor(double speed)
{
	m_motor->Set(speed * m_motorDirection);
}

template <typename MotorType, typename EncoderType>
double Shooter<MotorType, EncoderType>::GetMotor()
{
	return m_motor->Get();
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::InvertMotor(bool inverted)
{
	m_motor->SetInverted(inverted);
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::PrintMotor()
{
	SmartDashboard::PutNumber("Shooter Motor", GetMotor());
}

template <>
double Shooter<CANSparkMax, SparkMaxRelativeEncoder>::GetEncoder()
{
	return m_encoder->GetVelocity();
}

template <>
double Shooter<CANSparkMax, Encoder>::GetEncoder()
{
	return m_encoder->GetRate();
}

template <>
double Shooter<VictorSP, Encoder>::GetEncoder()
{
	return m_encoder->GetRate();
}

template <>
void Shooter<CANSparkMax, SparkMaxRelativeEncoder>::ResetEncoder()
{
	m_encoder->SetPosition(0);
}

template <>
void Shooter<CANSparkMax, Encoder>::ResetEncoder()
{
	m_encoder->Reset();
}

template <>
void Shooter<VictorSP, Encoder>::ResetEncoder()
{
	m_encoder->Reset();
}

template <>
void Shooter<CANSparkMax, SparkMaxRelativeEncoder>::InvertEncoder(bool inverted)
{
	m_encoder->SetInverted(inverted);
}

template <>
void Shooter<CANSparkMax, Encoder>::InvertEncoder(bool inverted)
{
	m_encoder->SetReverseDirection(inverted);
}

template <>
void Shooter<VictorSP, Encoder>::InvertEncoder(bool inverted)
{
	m_encoder->SetReverseDirection(inverted);
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::PrintEncoder()
{
	SmartDashboard::PutNumber("Shooter Encoder", GetEncoder());
}

template <typename MotorType, typename EncoderType>
bool Shooter<MotorType, EncoderType>::ReachRPM(double rpm)
{
	m_PIDController.SetSetpoint(rpm);

	double output = m_PIDController.Calculate(GetEncoder());

	SetMotor(std::clamp(output, -1.0, 1.0));

	return m_PIDController.AtSetpoint();
}

template <typename MotorType, typename EncoderType>
double Shooter<MotorType, EncoderType>::CalculateRPM()
{
	return shooterRPMFromDistance(m_limelight.GetDistanceToTarget());
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::ResetPID()
{
	m_PIDController.Reset();
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::PrintPIDError()
{
	SmartDashboard::PutNumber("Shooter PID Error", m_PIDController.GetVelocityError());
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::SetAngleServos(double angle)
{
	m_rightServo.Set(angle);
	m_leftServo.Set(angle);
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::ResetServos()
{
	m_rightServo.Set(0);
	m_leftServo.Set(0);
}

template <typename MotorType, typename EncoderType>
double Shooter<MotorType, EncoderType>::GetRightServo()
{
	return m_rightServo.Get();
}

template <typename MotorType, typename EncoderType>
double Shooter<MotorType, EncoderType>::GetLeftServo()
{
	return m_leftServo.Get();
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::PrintServos()
{
	SmartDashboard::PutNumber("Shooter Right Servo", GetRightServo());
	SmartDashboard::PutNumber("Shooter Left Servo", GetLeftServo());
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::SetAngleSolenoids(bool forward)
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

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::SolenoidsOff()
{
	m_rightSolenoid.Set(DoubleSolenoid::Value::kOff);
	m_leftSolenoid.Set(DoubleSolenoid::Value::kOff);
}

template <typename MotorType, typename EncoderType>
bool Shooter<MotorType, EncoderType>::GetRightSolenoid()
{
	return m_rightSolenoid.Get();
}

template <typename MotorType, typename EncoderType>
bool Shooter<MotorType, EncoderType>::GetLeftSolenoid()
{
	return m_leftSolenoid.Get();
}

template <typename MotorType, typename EncoderType>
void Shooter<MotorType, EncoderType>::PrintSolenoids()
{
	SmartDashboard::PutBoolean("Shooter Right Solenoid", GetRightSolenoid());
	SmartDashboard::PutBoolean("Shooter Left Solenoid", GetLeftSolenoid());
}