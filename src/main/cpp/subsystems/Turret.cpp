#include "subsystems/Turret.h"

using namespace std;

Turret::Turret()
{

	m_encoder.SetDistancePerPulse(k_turretDPR);

	// TODO : change if spark encoder

	// m_encoder.SetPositionConversionFactor(k_turretDPR);

	m_alignPID.SetTolerance(k_turretAlignPIDTolerance);

	m_anglePID.SetTolerance(k_turretAnglePIDTolerance);
}

void Turret::Periodic()
{
}

void Turret::Turn(double speed)
{
	SetMotor(speed);
}

void Turret::Reset()
{
	ResetEncoder();
	ResetAnglePID();
	ResetAlignPID();
}

void Turret::SetMotor(double speed)
{
	m_motor.Set(speed * k_turretMaxSpeed);
}

double Turret::GetMotor()
{
	return m_motor.Get();
}

void Turret::InvertMotor(bool inverted)
{
	m_motor.SetInverted(inverted);
}

void Turret::PrintMotor()
{
	SmartDashboard::PutNumber("Turret Motor", m_motor.Get());
}

double Turret::GetEncoder()
{

	// TODO : change if spark encoder

	// return m_encoder.GetPosition();

	return m_encoder.GetDistance();
}

void Turret::ResetEncoder()
{

	// TODO : change if spark encoder

	// m_encoder.SetPosition(0);

	m_encoder.Reset();
}

void Turret::InvertEncoder(bool invert)
{

	// TODO : change if spark encoder

	// m_encoder.SetInverted(invert);

	m_encoder.SetReverseDirection(invert);
}

void Turret::PrintEncoder()
{
	SmartDashboard::PutNumber("Turret Encoder", GetEncoder());
}

bool Turret::SetAngle(double angle)
{
	m_anglePID.SetSetpoint(angle);

	double output = m_anglePID.Calculate(GetEncoder());

	m_motor.Set(clamp(output, -k_turretMaxSpeed, k_turretMaxSpeed));

	return m_anglePID.AtSetpoint();
}

bool Turret::Align()
{
	m_alignPID.SetSetpoint(0);

	double output = m_alignPID.Calculate(-m_limelight.GetHorizontalAngle());

	m_motor.Set(clamp(output, -k_turretMaxSpeed, k_turretMaxSpeed));

	return m_alignPID.AtSetpoint();
}

void Turret::ResetAnglePID()
{
	m_anglePID.Reset();
}

void Turret::ResetAlignPID()
{
	m_alignPID.Reset();
}

void Turret::PrintAnglePIDError()
{
	SmartDashboard::PutNumber("Turret Angle PID Error", m_anglePID.GetPositionError());
}

void Turret::PrintAlignPIDError()
{
	SmartDashboard::PutNumber("Turret Align PID Error", m_alignPID.GetPositionError());
}