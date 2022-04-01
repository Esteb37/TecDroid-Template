#pragma once

#include "Constants.h"
#include <any>
#include <frc/DoubleSolenoid.h>
#include <frc/Encoder.h>
#include <frc/Servo.h>
#include <frc/controller/PIDController.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <subsystems/Limelight.h>

using namespace frc;
using namespace frc2;
using namespace rev;

class Shooter : public SubsystemBase
{

public:
	Shooter();

	void Periodic() override;

	// ---------- Actions -----------

	/**
	 * @brief Resets systems
	 */
	void Reset();

	// --------- Motor ---------

	/**
	 * @brief Sets the Motor speed
	 * @param speed Speed and direction to turn
	 */
	void SetMotor(double);

	/**
	 * @brief Gets the Motor speed
	 */
	double GetMotor();

	/**
	 * @brief Invert motor direction
	 * @param invert True to invert, false to not
	 */
	void InvertMotor(bool);

	/**
	 * @brief Publishes the motor speed to the dashboard
	 */
	void PrintMotor();

	// --------- Encoder ---------

	/**
	 * @brief Get the Encoder value
	 * @return double
	 */
	double GetEncoder();

	/**
	 * @brief Sets the encoder's value to 0
	 */
	void ResetEncoder();

	/**
	 * @brief Inverts the encoder's direction
	 * @param invert True to invert, false to not
	 */
	void InvertEncoder(bool);

	/**
	 * @brief Publishes the Encoder value to the dashboard
	 */
	void PrintEncoder();

	// --------- PID ---------

	/**
	 * @brief Sets the shooter's motor to a specified RPM
	 * @param rpm The RPM to set the motor to
	 * @return If the motor has reached the RPM
	 */
	bool ReachRPM(double);

	/**
	 * @brief Calculates the required RPM depending on distance to target
	 *
	 * @return The required RPM
	 */
	double CalculateRPM();

	/**
	 * @brief Resets RPM PID
	 */
	void ResetPID();

	/**
	 * @brief Prints RPM PID error to the dashboard
	 */
	void PrintPIDError();

	// --------- Angle with Servos --------

	/**
	 * @brief Sets the shooting angle by using servos
	 * @param angle The angle to set the shooter to
	 */
	void SetAngleServos(double);

	/**
	 * @brief Resets the angle servos to 0
	 */
	void ResetServos();

	/**
	 * @brief Gets the length of the right servo
	 * @return The length of the right servo
	 */
	double GetRightServo();

	/**
	 * @brief Gets the length of the left servo
	 * @return The length of the left servo
	 */
	double GetLeftServo();

	/**
	 * @brief Prints the length of the servos to the dashboard
	 */
	void PrintServos();

	// --------- Angle with Solenoids ---------

	/**
	 * @brief Sets the shooting angle by using solenoids
	 * @param up True to set the shooter to up, false to set it to down
	 */

	void SetAngleSolenoids(bool);

	/**
	 * @brief Inverts which value is open and closed
	 */
	void InvertSolenoids();

	/**
	 * @brief Set the solenoids to kOff
	 */
	void SolenoidsOff();

	/**
	 * @brief Gets the state of the right solenoid
	 */
	int GetRightSolenoid();

	/**
	 * @brief Gets the state of the left solenoid
	 */
	int GetLeftSolenoid();

	/**
	 * @brief Prints the state of the solenoids to the dashboard
	 */
	void PrintSolenoids();

private:
	// --------- Motor ---------

	CANSparkMax m_motor{pShooterMotor, CANSparkMax::MotorType::kBrushless};

	// TODO : define motor type

	// VictorSP m_motor{pShooterMotor};

	// VictorSPX m_motor{pShooterMotor};

	// --------- Encoder ---------

	SparkMaxRelativeEncoder m_encoder{m_motor.GetEncoder()};

	// TODO : define encoder type

	//	Encoder m_encoder{k_shooterEncoderA, k_shooterEncoderB, false, Encoder::EncodingType::k4X};

	PIDController m_PIDController{k_shooterP, k_shooterI, k_shooterD};

	// -------- Angle actuators --------

	DoubleSolenoid m_rightSolenoid{PneumaticsModuleType::REVPH, pShooterRightSolenoidForward, pShooterRightSolenoidReverse};

	DoubleSolenoid m_leftSolenoid{PneumaticsModuleType::REVPH, pShooterLeftSolenoidForward, pShooterLeftSolenoidReverse};

	Servo m_rightServo{pShooterRightServo};

	Servo m_leftServo{pShooterLeftServo};

	// --------- Sensors -------------

	Limelight m_limelight;

	// --------- Attributes -----------

	bool m_solenoidsInverted = false;
};