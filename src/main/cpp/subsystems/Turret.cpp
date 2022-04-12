#include "subsystems/Turret.h"

using namespace std;

Turret::Turret(MotorConfig motorConfig, EncoderConfig encoderConfig, unsigned int motorPort) : EncoderSubsystem(motorConfig, encoderConfig, motorPort), MotorSubsystem(motorConfig, motorPort)
{
	SetName("Turret");
}

Turret::Turret(MotorConfig motorConfig, EncoderConfig encoderConfig, unsigned int motorPort, unsigned int encoderA, unsigned int encoderB) : EncoderSubsystem(motorConfig, encoderConfig, motorPort, encoderA, encoderB), MotorSubsystem(motorConfig, motorPort)
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

void Turret::KeepStill(double speed)
{
	m_keepingStill = true;

	SetAngle(m_angle, speed);
}

bool Turret::Center(double speed)
{
	return SetAngle(0, speed);
}

bool Turret::SetAngle(double angle, double speed)
{

	if (angle > m_freedom / 2 && angle < -m_freedom / 2)
	{
		throw std::invalid_argument("Turret angle must be within " + to_string(m_freedom / 2) + " degrees of the center");
	}
	else
	{
		return SetPosition(angle, speed);
	}
}

double Turret::GetAngle()
{
	return GetPosition();
}

void Turret::ConfigureAnglePID(double p, double i, double d, double tolerance, bool inverted)
{
	ConfigurePositionPID(p, i, d, tolerance, inverted);
}

void Turret::PrintAngle()
{
	SmartDashboard::PutNumber(GetName() + " Angle", GetAngle());
}

void Turret::PrintAnglePIDError()
{
	SmartDashboard::PutNumber(GetName() + " Angle PID Error", m_positionPID->GetPositionError());
}

bool Turret::Align(double speed)
{
	m_alignPID.SetSetpoint(0);

	double output = m_alignPID.Calculate(m_limelight.GetHorizontalAngle() * m_alignPIDDirection);

	SetMotor(output * speed);

	return m_alignPID.AtSetpoint();
}

void Turret::ConfigureAlignPID(double p, double i, double d, double tolerance, bool inverted)
{
	m_alignPID.SetPID(p, i, d);
	m_alignPID.SetTolerance(tolerance);
	m_alignPIDDirection = inverted ? -1 : 1;
}

void Turret::ResetAlignPID()
{
	m_alignPID.Reset();
}

void Turret::PrintAlignPIDError()
{
	SmartDashboard::PutNumber(GetName() + " Align PID Error", m_alignPID.GetPositionError());
}

void Turret::SetFreedom(double freedom)
{
	m_freedom = freedom;
	SetMinMaxPosition(-freedom / 2, freedom / 2);
}