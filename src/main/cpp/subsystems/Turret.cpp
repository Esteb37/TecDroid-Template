#include "subsystems/Turret.h"

using namespace std;

Turret::Turret(MotorConfig mconfig, EncoderConfig econfig, unsigned int mport) : EncoderSubsystem(mconfig, econfig, mport), MotorSubsystem(mconfig, mport)
{
	SetName("Turret");
}

Turret::Turret(MotorConfig mconfig, EncoderConfig econfig, unsigned int mport, unsigned int encoderA, unsigned int encoderB) : EncoderSubsystem(mconfig, econfig, mport, encoderA, encoderB), MotorSubsystem(mconfig, mport)
{
	SetName("Turret");
}

void Turret::Periodic()
{

	if (!m_keepingStill)
	{
		m_angle = GetAngle();
	}

	m_keepingStill = false;
}

void Turret::Turn(double speed)
{
	SetMotor(speed);
}

void Turret::Reset()
{
	ResetEncoder();
	ResetPositionPID();
	ResetAlignPID();
}

void Turret::KeepStill(bool inverted)
{
	m_keepingStill = true;

	SetAngle(m_angle, inverted);
}

bool Turret::Center(bool inverted)
{
	return SetAngle(0, inverted);
}

bool Turret::SetAngle(double angle, bool invert)
{

	if (angle > m_freedom / 2 && angle < -m_freedom / 2)
	{
		throw std::invalid_argument("Turret angle must be within " + to_string(m_freedom / 2) + " degrees of the center");
	}
	else
	{
		return SetPosition(angle, invert);
	}
}

double Turret::GetAngle()
{
	return GetPosition();
}

void Turret::PrintAngle()
{
	SmartDashboard::PutNumber(GetName() + " Angle", GetAngle());
}

void Turret::PrintAnglePIDError()
{
	SmartDashboard::PutNumber(GetName() + " Angle PID Error", m_positionPID->GetPositionError());
}

bool Turret::Align(bool inverted)
{
	m_alignPID.SetSetpoint(0);

	double output = m_alignPID.Calculate(-m_limelight.GetHorizontalAngle());

	SetMotor((inverted ? -1 : 1) * output);

	return m_alignPID.AtSetpoint();
}

void Turret::ConfigureAlignPID(double p, double i, double d, double tolerance)
{
	m_alignPID.SetPID(p, i, d);
	m_alignPID.SetTolerance(tolerance);
}

void Turret::ResetAlignPID()
{
	m_alignPID.Reset();
}

void Turret::PrintAlignPIDError()
{
	SmartDashboard::PutNumber(GetName() + " Align PID Error", m_alignPID.GetPositionError());
}

Limelight Turret::GetLimelight()
{
	return m_limelight;
}

void Turret::SetFreedom(double freedom)
{
	m_freedom = freedom;
	SetMinMaxPosition(-freedom / 2, freedom / 2);
}