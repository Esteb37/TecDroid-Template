#include "subsystems/Drivetrain.h"

Drivetrain::Drivetrain()
{
	// Set position conversion factor for all encoders to be kDistancePerRotation
}

Drivetrain::~Drivetrain()
{
}

// Add definitions to all Drivetrain class functions

// --------------------- Control ----------------------

void Drivetrain::Drive(double x, double y)
{
	// Set the speed of the left and right motors based on the inputs
}

void Drivetrain::Reset()
{
	// Set all motors to 0
}

void Drivetrain::InvertSpeed(bool invert)
{
	// Set the speed inversion to the input
}

void Drivetrain::InvertRotation(bool invert)
{
	// Set the rotation inversion to the input
}

void Drivetrain::SetSafetyEnabled(bool enabled)
{
	// Set the safety to the input
}

// ---------------------- Motors ----------------------

void Drivetrain::ResetMotors()
{
	// Set all motors to 0
}

void Drivetrain::InvertRight(bool invert)
{
	// Set the right motor inversion to the input
}

void Drivetrain::InvertLeft(bool invert)
{
	// Set the left motor inversion to the input
}

void Drivetrain::PrintFrontRight()
{
	// Print the front right motor's current position
}

void Drivetrain::PrintFrontLeft()
{
	// Print the front left motor's current position
}

void Drivetrain::PrintBackRight()
{
	// Print the back right motor's current position
}

void Drivetrain::PrintBackLeft()
{
	// Print the back left motor's current position
}

void Drivetrain::PrintRight()
{
	// Print the right motor's current position
}

void Drivetrain::PrintLeft()
{
	// Print the left motor's current position
}

void Drivetrain::PrintMotors()
{
	// Print all motor positions
}

// --------------------- Encoders ---------------------

double Drivetrain::GetRightEncoders()
{
	// Return the right motor's current position
}

double Drivetrain::GetLeftEncoders()
{
	// Return the left motor's current position
}

double Drivetrain::GetEncoderAverage()
{
	// Return the average of the left and right motor's current positions
}

void Drivetrain::ResetEncoders()
{
	// Set all encoders to 0
}

void Drivetrain::InvertRightEncoders(bool invert)
{
	// Set the right encoder inversion to the input
}

void Drivetrain::InvertLeftEncoders(bool invert)
{
	// Set the left encoder inversion to the input
}

void Drivetrain::PrintFrontRightEncoder()
{
	// Print the front right encoder's current position
}

void Drivetrain::PrintFrontLeftEncoder()
{
	// Print the front left encoder's current position
}

void Drivetrain::PrintBackRightEncoder()
{
	// Print the back right encoder's current position
}

void Drivetrain::PrintBackLeftEncoder()
{
	// Print the back left encoder's current position
}

void Drivetrain::PrintRightEncoders()
{
	// Print the right encoder's current position
}

void Drivetrain::PrintLeftEncoders()
{
	// Print the left encoder's current position
}

void Drivetrain::PrintEncoders()
{
	// Print all encoder positions
}

// ----------------------- Gyro -----------------------

double Drivetrain::GetGyro()
{
	// Return the gyro's current position
}

double Drivetrain::GetGyroRad()
{
	// Return the gyro's current position in radians
}

void Drivetrain::ResetGyro()
{
	// Reset the gyro to 0
}

void Drivetrain::InvertGyro(bool invert)
{
	// Set the gyro inversion to the input
}

void Drivetrain::PrintGyro()
{
	// Print the gyro's current position
}

void Drivetrain::PrintGyroRad()
{
	// Print the gyro's current position in radians
}

// ----------------------- Auto -----------------------

bool Drivetrain::Move(double distance, double speed)
{
	// Move the robot forward a certain distance at a certain speed
}

bool Drivetrain::Turn(double angle, double speed)
{
	// Turn the robot a certain angle at a certain speed
}

bool Drivetrain::MoveTo(double x, double y, double speed, double turnSpeed)
{
	// Move the robot to a certain position at a certain speed
}

bool Drivetrain::AlignWithTarget(double speed)
{
}
