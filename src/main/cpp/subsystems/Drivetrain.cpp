#include "subsystems/Drivetrain.h"

Drivetrain::Drivetrain()
{
	// Set position conversion factor for all encoders to be kDistancePerRotation
	
}

Drivetrain::~Drivetrain()
{
}

void Drivetrain::Periodic()
{

	// Put encoder values in smartdashboard
	SmartDashboard::PutNumber("Left Encoder", GetLeftEncoders());
	SmartDashboard::PutNumber("Right Encoder", GetRightEncoders());
	SmartDashboard::PutNumber("Encoder Average", GetEncoderAverage());
	SmartDashboard::PutNumber("Gyro", GetGyro());
}

// Reset that resets gyro and encoders
void Drivetrain::Reset()
{
	ResetGyro();
	ResetEncoders();
}

// Drive that gets x and y from controlers and uses chasis arcade drive
void Drivetrain::Drive()
{
	double x = m_controller.GetRightXAxis();
	double y = m_controller.GetRightYAxis();

	// Chasis arcade drive x and y
	m_chasis.ArcadeDrive(x, y);
}

// Drive that uses x and y to chasis arcade drive
void Drivetrain::Drive(double x, double y)
{
	// Chasis arcade drive x and y
	m_chasis.ArcadeDrive(x, y);
}

// Reset gyro
void Drivetrain::ResetGyro()
{
	// Reset gyro
	gyro.Reset();
}

// Reset encoders function that resets all encoders
void Drivetrain::ResetEncoders()
{
	
	// Set position of front and back encoders to 0
	frontLeftEncoder.SetPosition(0);
	frontRightEncoder.SetPosition(0);
	backLeftEncoder.SetPosition(0);
	backRightEncoder.SetPosition(0);

}

// Get encoder average
double Drivetrain::GetEncoderAverage()
{
	// average of getright and getleft
	return (GetRightEncoders() + GetLeftEncoders()) / 2;
}


// Read right encoder average
double Drivetrain::GetRightEncoders()
{
	// Get average of right encoders
	return -(frontRightEncoder.Get() + backRightEncoder.Get()) / 2;
}

// Read left encoder average
double Drivetrain::GetLeftEncoders()
{
	// Get average of left encoders
	return (frontLeftEncoder.Get() + backLeftEncoder.Get()) / 2;
}


// Read gyro
double Drivetrain::GetGyro()
{
	// Get gyro in degrees
	return -gyro.GetAngle().value();
}

// read gyro in radians
double Drivetrain::GetGyroRad()
{
	// Get gyro in radians
	return -gyro.GetAngle().value() * (M_PI / 180);
}	