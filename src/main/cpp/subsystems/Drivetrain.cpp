#include "subsystems/Drivetrain.h"

using namespace std;

Drivetrain::Drivetrain()
{
	m_frontRightEncoder.SetPositionConversionFactor(k_drivetrainDPR);
	m_frontLeftEncoder.SetPositionConversionFactor(k_drivetrainDPR);
	m_backRightEncoder.SetPositionConversionFactor(k_drivetrainDPR);
	m_backLeftEncoder.SetPositionConversionFactor(k_drivetrainDPR);

	SetName("DT");
}

void Drivetrain::Periodic()
{
}

// --------------------- Control ----------------------

void Drivetrain::Drive(double speed, double rotation)
{
	m_drive.ArcadeDrive(speed * m_speedDirection * k_drivetrainMaxSpeed, rotation * m_rotationDirection * k_drivetrainMaxRotation);
}

void Drivetrain::Reset()
{

	ResetGyro();
	ResetEncoders();

	m_drive.SetSafetyEnabled(true);

	m_speedDirection = 1;
	m_rotationDirection = 1;
}

void Drivetrain::InvertSpeed(bool invert)
{
	m_speedDirection = invert ? -1 : 1;
}

void Drivetrain::InvertRotation(bool invert)
{
	m_rotationDirection = invert ? -1 : 1;
}

void Drivetrain::SetSafetyEnabled(bool enabled)
{
	m_drive.SetSafetyEnabled(enabled);
}

// ---------------------- Motors ----------------------

void Drivetrain::ResetMotors()
{
	m_frontRight.RestoreFactoryDefaults();
	m_frontLeft.RestoreFactoryDefaults();
	m_backRight.RestoreFactoryDefaults();
	m_backLeft.RestoreFactoryDefaults();
}

void Drivetrain::InvertRight(bool invert)
{
	m_right.SetInverted(invert);
}

void Drivetrain::InvertLeft(bool invert)
{
	m_left.SetInverted(invert);
}

void Drivetrain::PrintMotors()
{
	SmartDashboard::PutNumber(GetName() + " FR Motor", m_frontRight.Get());
	SmartDashboard::PutNumber(GetName() + " FL Motor", m_frontLeft.Get());
	SmartDashboard::PutNumber(GetName() + " BR Motor", m_backRight.Get());
	SmartDashboard::PutNumber(GetName() + " BL Motor", m_backLeft.Get());
}

// --------------------- Encoders ---------------------

double Drivetrain::GetRightEncoders()
{
	return (m_frontRightEncoder.GetPosition() + m_backRightEncoder.GetPosition()) / 2;
}

double Drivetrain::GetLeftEncoders()
{
	return (m_frontLeftEncoder.GetPosition() + m_backLeftEncoder.GetPosition()) / 2;
}

double Drivetrain::GetEncoderAverage()
{
	return (GetRightEncoders() + GetLeftEncoders()) / 2;
}

void Drivetrain::ResetEncoders()
{
	m_frontRightEncoder.SetPosition(0);
	m_frontLeftEncoder.SetPosition(0);
	m_backRightEncoder.SetPosition(0);
	m_backLeftEncoder.SetPosition(0);
}

void Drivetrain::InvertRightEncoders(bool invert)
{
	m_frontRightEncoder.SetInverted(invert);
	m_backRightEncoder.SetInverted(invert);
}

void Drivetrain::InvertLeftEncoders(bool invert)
{
	m_frontLeftEncoder.SetInverted(invert);
	m_backLeftEncoder.SetInverted(invert);
}

void Drivetrain::PrintEncoders()
{
	SmartDashboard::PutNumber(GetName() + " FR Encoder", m_frontRightEncoder.GetPosition());
	SmartDashboard::PutNumber(GetName() + " FL Encoder", m_frontLeftEncoder.GetPosition());
	SmartDashboard::PutNumber(GetName() + " BR Encoder", m_backRightEncoder.GetPosition());
	SmartDashboard::PutNumber(GetName() + " BL Encoder", m_backLeftEncoder.GetPosition());
}

// ----------------------- Gyro -----------------------

double Drivetrain::GetGyro()
{
	return m_gyro.GetAngle().value() * m_gyroDirection;
}

double Drivetrain::GetGyroRad()
{
	return GetGyro() * (M_PI / 180);
}

void Drivetrain::ResetGyro()
{
	m_gyro.Reset();
}

void Drivetrain::InvertGyro(bool invert)
{
	m_gyroDirection = invert ? -1 : 1;
}

void Drivetrain::PrintGyro()
{
	SmartDashboard::PutNumber(GetName() + " Gyro", GetGyro());
}

void Drivetrain::PrintGyroRad()
{
	SmartDashboard::PutNumber(GetName() + "Gyro Rad", GetGyroRad());
}

// ----------------------- Auto -----------------------

bool Drivetrain::Move(double distance, double speed)
{
	m_movePIDController.SetSetpoint(distance);
	m_movePIDController.SetTolerance(k_movePIDTolerance);
	double output = m_movePIDController.Calculate(-GetEncoderAverage());
	output = clamp(output, -speed, speed);
	Drive(output * speed, 0);
	return m_movePIDController.AtSetpoint();
}

bool Drivetrain::Turn(double angle, double speed)
{
	m_turnPIDController.SetSetpoint(angle);
	m_turnPIDController.SetTolerance(k_turnPIDTolerance);
	double output = m_turnPIDController.Calculate(GetGyro());
	output = clamp(output, -speed, speed);
	Drive(0, output * speed);
	return m_turnPIDController.AtSetpoint();
}

bool Drivetrain::MoveTo(double x, double y, double speed, double turnSpeed)
{
	double targetX = x - m_currentX;
	double targetY = y - m_currentY;

	double angle = GetAbsoluteAngle(targetX, targetY);

	if (Turn(angle, turnSpeed))
	{
		double distance = sqrt(pow(targetX, 2) + pow(targetY, 2));

		if (Move(distance, speed))
		{
			ResetEncoders();
			m_currentX = x;
			m_currentY = y;
			return true;
		}

		return false;
	}

	return false;
}

bool Drivetrain::AlignWithTarget(double speed)
{
	m_alignPIDController.SetSetpoint(0);
	m_alignPIDController.SetTolerance(k_alignPIDTolerance);
	double output = m_alignPIDController.Calculate(m_limelight.GetHorizontalAngle());
	output = clamp(output, -speed, speed);
	Drive(0, output * speed);
	return m_alignPIDController.AtSetpoint();
}

bool Drivetrain::SetDistanceWithTarget(double distance, double speed)
{
	m_distancePIDController.SetSetpoint(distance);
	double output = m_distancePIDController.Calculate(m_limelight.GetDistanceToTarget());
	output = clamp(output, -speed, speed);
	Drive(output * speed, 0);
	return m_distancePIDController.AtSetpoint();
}

bool Drivetrain::SetAngleWithTarget(double angle, double speed)
{
	m_alignPIDController.SetSetpoint(angle);
	double output = m_alignPIDController.Calculate(m_limelight.GetHorizontalAngle());
	output = clamp(output, -speed, speed);
	Drive(0, output * speed);
	return m_alignPIDController.AtSetpoint();
}

void Drivetrain::ResetMovePIDController()
{
	m_movePIDController.Reset();
}

void Drivetrain::ResetTurnPIDController()
{
	m_turnPIDController.Reset();
}

void Drivetrain::ResetAlignPIDController()
{
	m_alignPIDController.Reset();
}

void Drivetrain::ResetDistancePIDController()
{
	m_distancePIDController.Reset();
}

void Drivetrain::ResetPIDControllers()
{
	ResetMovePIDController();
	ResetTurnPIDController();
	ResetAlignPIDController();
	ResetDistancePIDController();
}

void Drivetrain::PrintMoveError()
{
	SmartDashboard::PutNumber(GetName() + " Move Error", m_movePIDController.GetPositionError());
}

void Drivetrain::PrintTurnError()
{
	SmartDashboard::PutNumber(GetName() + " Turn Error", m_turnPIDController.GetPositionError());
}

void Drivetrain::PrintMoveToError()
{
	PrintMoveError();
	PrintTurnError();
}

void Drivetrain::PrintAlignError()
{
	SmartDashboard::PutNumber(GetName() + " Align Error", m_alignPIDController.GetPositionError());
}

void Drivetrain::PrintSetDistanceError()
{
	SmartDashboard::PutNumber(GetName() + " Set Distance Error", m_distancePIDController.GetPositionError());
}

double Drivetrain::GetAbsoluteAngle(double x, double y)
{
	float relAngle = atan(y / (x == 0 ? 0.01 : x));

	if (x < 0)
		relAngle += M_PI;

	else if (y < 0)
		relAngle += 2 * M_PI;

	return (relAngle)*180 / M_PI;
}

void Drivetrain::PrintCurrentPosition()
{
	SmartDashboard::PutNumber(GetName() + " Current X", m_currentX);
	SmartDashboard::PutNumber(GetName() + " Current Y", m_currentY);
}
