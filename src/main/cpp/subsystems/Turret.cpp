#include "subsystems/Turret.h"

template <>
Turret<CANSparkMax, SparkMaxRelativeEncoder>::Turret()
{
	m_motor = new CANSparkMax(pTurretMotor, CANSparkMax::MotorType::kBrushless);

	m_encoder = new SparkMaxRelativeEncoder(m_motor->GetEncoder());

	m_encoder->SetPositionConversionFactor(k_turretDPR);

	m_alignPID.SetTolerance(k_turretAlignPIDTolerance);

	m_anglePID.SetTolerance(k_turretAnglePIDTolerance);
}

template <>
Turret<CANSparkMax, Encoder>::Turret()
{
	m_motor = new CANSparkMax(pTurretMotor, CANSparkMax::MotorType::kBrushed);

	m_encoder = new Encoder(pShooterEncoderA, pShooterEncoderB, false, Encoder::EncodingType::k4X);

	m_encoder->SetDistancePerPulse(k_turretDPR);

	m_alignPID.SetTolerance(k_turretAlignPIDTolerance);

	m_anglePID.SetTolerance(k_turretAnglePIDTolerance);
}

template <>
Turret<VictorSP, Encoder>::Turret()
{
	m_motor = new VictorSP(pShooterMotor);

	m_encoder = new Encoder(pShooterEncoderA, pShooterEncoderB, false, Encoder::EncodingType::k4X);

	m_encoder->SetDistancePerPulse(k_turretDPR);

	m_alignPID.SetTolerance(k_turretAlignPIDTolerance);

	m_anglePID.SetTolerance(k_turretAnglePIDTolerance);
}

template <typename MotorType, typename EncoderType>
void Turret<MotorType, EncoderType>::Periodic()
{
}

template <typename MotorType, typename EncoderType>
bool Turret<MotorType, EncoderType>::Turn(double speed)
{
	SetMotor(speed);
}

template <typename MotorType, typename EncoderType>
void Turret<MotorType, EncoderType>::Reset()
{
	ResetEncoder();
	ResetPID();
}

template <typename MotorType, typename EncoderType>
void Turret<MotorType, EncoderType>::SetMotor(double speed)
{
	m_motor.Set(speed * k_turretMaxSpeed);
}

template <typename MotorType, typename EncoderType>
double Turret<MotorType, EncoderType>::GetMotor()
{
	return m_motor.Get();
}

template <typename MotorType, typename EncoderType>
void Turret<MotorType, EncoderType>::InvertMotor(bool inverted)
{
	m_motor.SetInverted(inverted);
}

template <typename MotorType, typename EncoderType>
void Turret<MotorType, EncoderType>::PrintMotor()
{
	SmartDashboard::PutNumber("Turret Motor", m_motor.Get());
}

template <>
double Turret<CANSparkMax, SparkMaxRelativeEncoder>::GetEncoder()
{
	return m_encoder->GetPosition();
}

template <>
double Turret<CANSparkMax, Encoder>::GetEncoder()
{
	return m_encoder->GetDistance();
}

template <>
double Turret<VictorSP, Encoder>::GetEncoder()
{
	return m_encoder->GetDistance();
}

template <>
void Turret<CANSparkMax, SparkMaxRelativeEncoder>::ResetEncoder()
{
	m_encoder->SetPosition(0);
}

template <>
void Turret<CANSparkMax, Encoder>::ResetEncoder()
{
	m_encoder->Reset();
}

template <>
void Turret<VictorSP, Encoder>::ResetEncoder()
{
	m_encoder->Reset();
}

template <>
void Turret<CANSparkMax, SparkMaxRelativeEncoder>::InvertEncoder(bool invert)
{
	m_encoder->SetInverted(invert);
}

template <>
void Turret<CANSparkMax, Encoder>::InvertEncoder(bool invert)
{
	m_encoder->SetReverseDirection(invert);
}

template <>
void Turret<VictorSP, Encoder>::InvertEncoder(bool invert)
{
	m_encoder->SetReverseDirection(invert);
}

template <typename MotorType, typename EncoderType>
void Turret<MotorType, EncoderType>::PrintEncoder()
{
	SmartDashboard::PutNumber("Turret Encoder", GetEncoder());
}

template <typename MotorType, typename EncoderType>
bool Turret<MotorType, EncoderType>::SetAngle(double)
{
	m_anglePID.SetSetpoint(angle);

	double output = m_anglePID.Calculate(GetEncoder());

	m_motor.Set(clamp(output, -k_turretMaxSpeed, k_turretMaxSpeed));

	return m_anglePID.AtSetpoint();
}

template <typename MotorType, typename EncoderType>
bool Turret<MotorType, EncoderType>::Align()
{
	m_alignPID.SetSetpoint(0);

	double output = m_alignPID.Calculate(-m_limelight.GetHorizontalAngle());

	m_motor.Set(clamp(output, -kTurretMaxSpeed, kTurretMaxSpeed));

	return m_alignPID.AtSetpoint();
}

template <typename MotorType, typename EncoderType>
void Turret<MotorType, EncoderType>::ResetAnglePID()
{
	m_anglePID.Reset();
}

template <typename MotorType, typename EncoderType>
void Turret<MotorType, EncoderType>::ResetAlignPID()
{
	m_alignPID.Reset();
}

template <typename MotorType, typename EncoderType>
void Turret<MotorType, EncoderType>::PrintAnglePIDError()
{
	SmartDashboard::PutNumber("Turret Angle PID Error", m_anglePID.GetError());
}

template <typename MotorType, typename EncoderType>
void Turret<MotorType, EncoderType>::PrintAlignPIDError()
{
	SmartDashboard::PutNumber("Turret Align PID Error", m_alignPID.GetError());
}