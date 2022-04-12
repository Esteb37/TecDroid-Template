#pragma once

#include "Constants.h"
#include <frc/ADIS16448_IMU.h>
#include <frc/XboxController.h>
#include <frc/controller/PIDController.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <subsystems/Limelight.h>

using namespace frc2;
using namespace frc;
using namespace rev;
using namespace std;

namespace TecDroid
{
	class Drivetrain : public SubsystemBase
	{
	public:
		/**
		 * @brief Construct a new Drivetrain object
		 * @param frontRight The CAN ID of the front right motor
		 * @param frontLeft The CAN ID of the front left motor
		 * @param backRight The CAN ID of the back right motor
		 * @param backLeft The CAN ID of the back left motor
		 */
		Drivetrain(unsigned int, unsigned int, unsigned int, unsigned int);

		void Periodic() override;

		// --------------------- Actions ----------------------

		/**
		 * @brief Use drivetrain ArcadeDrive to move the chasis
		 * @param speed Speed and direction to move
		 * @param rotation Rotation to turn
		 */
		void Drive(double, double);
		/**
		 * @brief Reset all systems
		 */
		void Reset();

		/**
		 * @brief Set maximum move and turn speed
		 * @param moveSpeed Maximum speed to move
		 * @param turnSpeed Maximum speed to turn
		 */
		void SetMaxSpeeds(double, double);

		/**
		 * @brief Invert the direction of movement
		 *
		 * @param invert True to invert, false to not
		 */
		void InvertMove(bool);

		/**
		 * @brief Invert the direction of rotation
		 * @param invert True to invert, false to not
		 */
		void InvertRotation(bool);

		/**
		 * @brief Enable drivetrain safety
		 * @param enable True to enable, false to not
		 */
		void SetSafetyEnabled(bool);

		// ---------------------- Motors ----------------------

		/**
		 * @brief Resets motor factory default
		 * @warning Use only once and before everything else
		 */
		void ResetMotors();

		/**
		 * @brief Invert direction of the right motor group
		 * @param invert True to invert, false to not
		 */
		void InvertRight(bool);

		/**
		 * @brief Invert direction of the left motor group
		 * @param invert True to invert, false to not
		 */
		void InvertLeft(bool);

		/**
		 * @brief Publishes all motors to the dashboard
		 *
		 */
		void PrintMotors();

		// --------------------- Encoders ---------------------

		/**
		 * @brief Gets the average of the right encoders
		 * @return double average
		 */
		double GetRightEncoders();

		/**
		 * @brief Gets the average of the left encoders
		 * @return double average
		 */
		double GetLeftEncoders();

		/**
		 * @brief Gets the average of the all encoders
		 * @return double average
		 */
		double GetEncoderAverage();

		/**
		 * @brief Resets the encoders to 0
		 */
		void ResetEncoders();

		/**
		 * @brief Invert the direction of the right encoders
		 * @param invert True to invert, false to not
		 */
		void InvertRightEncoders(bool);

		/**
		 * @brief Invert the direction of the left encoders
		 * @param invert True to invert, false to not
		 */
		void InvertLeftEncoders(bool);

		/**
		 * @brief Publish the value of the encoders to the dashboard
		 */
		void PrintEncoders();

		/**
		 * @brief Sets the encoders' distance per revolution
		 * @param pcf Position conversion factor
		 */
		void SetPositionConversionFactor(double);

		// ----------------------- Gyro -----------------------

		/**
		 * @brief Gets the current angle of the gyro in degrees
		 * @return double angle
		 */
		double GetGyro();

		/**
		 * @brief Get the gyro angle in radians
		 * @return double angle radians
		 */
		double GetGyroRad();

		/**
		 * @brief Resets the angle to 0
		 */
		void ResetGyro();

		/**
		 * @brief Invert the direction of the gyro
		 * @param invert True to invert, false to not
		 */
		void InvertGyro(bool);

		/**
		 * @brief Publish the value of the gyro to the dashboard
		 */
		void PrintGyro();

		/**
		 * @brief Publish the angle in radians to the dashboard
		 */
		void PrintGyroRad();

		// ----------------------- Auto -----------------------

		/**
		 * @brief Sets the drivetrain to a given heading.
		 * @param distance The desired heading in meters.
		 * @param speed The speed at which to drive.
		 * @return Wether or not the drivetrain is at the desired heading.
		 */
		bool Move(double, double);

		/**
		 * @brief Prints the move PID error to the dashboard
		 */
		void PrintMoveError();

		/**
		 * @brief Resets the Move PID
		 */
		void ResetMovePIDController();

		/**
		 * @brief Configures move auto PID values and tolerance
		 * @param p The proportional value
		 * @param i The integral value
		 * @param d The derivative value
		 * @param tolerance The tolerance value
		 * @param inverted Invert output calculation
		 */
		void ConfigureMovePID(double, double, double, double, bool = false);

		/**
		 * @brief Turns the drievtrain to a given angle.
		 * @param angle The desired angle in degrees.
		 * @param speed The speed at which to turn.
		 * @return Whether or not the drivetrain has reached the desired angle
		 */
		bool Turn(double, double);

		/**
		 * @brief Prints the turn PID error to the dashboard
		 */
		void PrintTurnError();

		/**
		 * @brief Resets the Turn PID
		 */
		void ResetTurnPIDController();

		/**
		 * @brief Configures turn auto PID values and tolerance
		 * @param p The proportional value
		 * @param i The integral value
		 * @param d The derivative value
		 * @param tolerance The tolerance value
		 * @param inverted Invert output calculation
		 */
		void ConfigureTurnPID(double, double, double, double, bool = false);

		/**
		 * @brief Moves the drivetrain to a given coordinate in meters
		 * @param x The desired x coordinate.
		 * @param y The desired y coordinate.
		 * @param speed The speed at which to drive.
		 * @param turnSpeed The speed at which to turn.
		 * @return Whether or not the drivetrain has reached the desired coordinate.
		 */
		bool MoveTo(double, double, double, double);

		/**
		 * @brief Prints the move to PID error to the dashboard
		 */
		void PrintMoveToError();

		/**
		 * @brief Prints the current coordinates to the dashboard
		 */
		void PrintCurrentPosition();

		/**
		 * @brief Set drivetrain to a specific angle from the target
		 * @param angle The angle to the target in degrees.
		 * @param speed The speed at which to drive.
		 * @return Whether or not the drivetrain has reached the desired angle
		 */
		bool SetAngleWithTarget(double, double);

		/**
		 * @brief Align chasis to target
		 * @param speed The speed at which to drive.
		 * @return Whether or not the drivetrain has aligned to the target.
		 */
		bool AlignWithTarget(double);

		/**
		 * @brief Prints the align PID error to the dashboard
		 */
		void PrintAlignError();

		/**
		 * @brief Resets the Align with target PID
		 */
		void ResetAlignPIDController();

		/**
		 * @brief Configures align PID values, tolerance and direction
		 * @param p The proportional value
		 * @param i The integral value
		 * @param d The derivative value
		 * @param tolerance The tolerance value
		 * @param inverted Invert output calculation
		 */
		void ConfigureAlignPID(double, double, double, double, bool = false);

		/**
		 * @brief Set drivetrain to a specific distance from the target
		 * @param distance The distance to the target in meters.
		 * @param speed The speed at which to drive.
		 * @return Whether or not the drivetrain has reached the desired distance
		 */
		bool SetDistanceWithTarget(double, double);

		/**
		 * @brief Prints the distance PID error to the dashboard
		 */
		void PrintSetDistanceError();

		/**
		 * @brief Resets the Distance to target PID
		 */
		void ResetDistancePIDController();

		/**
		 * @brief Configures distance PID values and tolerance
		 * @param p The proportional value
		 * @param i The integral value
		 * @param d The derivative value
		 * @param tolerance The tolerance value
		 * @param inverted Invert output calculation
		 */
		void ConfigureDistancePID(double, double, double, double, bool = false);

		/**
		 * @brief Get the absolute angle from a coordinate independent of quadrant
		 * @param x The x coordinate
		 * @param y The y coordinate
		 * @return double the angle
		 */
		double GetAbsoluteAngle(double, double);

		/**
		 * @brief Resets all PID controllers
		 */
		void ResetPIDControllers();

		// ----- Motors -----

		CANSparkMax *m_frontLeft;

		CANSparkMax *m_frontRight;

		CANSparkMax *m_backLeft;

		CANSparkMax *m_backRight;

		// ----- Motor controller groups-----

		MotorControllerGroup m_right{*m_frontRight, *m_backRight};

		MotorControllerGroup m_left{*m_frontLeft, *m_backLeft};

		// ----- Chasis drive object -----

		DifferentialDrive m_drive{m_left, m_right};

		// ----- Sensors -----

		SparkMaxRelativeEncoder m_frontRightEncoder{m_frontRight->GetEncoder()};

		SparkMaxRelativeEncoder m_frontLeftEncoder{m_frontLeft->GetEncoder()};

		SparkMaxRelativeEncoder m_backRightEncoder{m_backRight->GetEncoder()};

		SparkMaxRelativeEncoder m_backLeftEncoder{m_backLeft->GetEncoder()};

		ADIS16448_IMU m_gyro;

		Limelight m_limelight;

		// ----- Auto -----

		PIDController m_movePIDController{0.1, 0, 0};

		PIDController m_turnPIDController{0.1, 0, 0};

		PIDController m_alignPIDController{0.1, 0, 0};

		PIDController m_distancePIDController{0.1, 0, 0};

	private:
		// ----- Attributes -----

		int m_gyroDirection = 1;

		int m_moveDirection = 1;

		int m_rotationDirection = 1;

		int m_movePIDDirection = 1;

		int m_turnPIDDirection = 1;

		int m_alignPIDDirection = 1;

		int m_distancePIDDirection = 1;

		double m_currentX = 0;

		double m_currentY = 0;

		double m_maxMoveSpeed = 1;

		double m_maxTurnSpeed = 1;
	};
}