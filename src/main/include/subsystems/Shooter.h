#pragma once

#include "Constants.h"
#include "subsystems/EncoderSubsystem.h"
#include "subsystems/SolenoidSubsystem.h"
#include <any>
#include <frc/DoubleSolenoid.h>
#include <frc/Encoder.h>
#include <frc/Servo.h>
#include <frc/Timer.h>
#include <frc/controller/PIDController.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <subsystems/Limelight.h>

using namespace frc;
using namespace frc2;
using namespace rev;

class Shooter : public EncoderSubsystem, public SolenoidSubsystem
{

public:
	/**
	 * @brief Construct a new Shooter object without encoder
	 *
	 * @param motorConfig The motor configuration
	 * @param motorPort The motor port
	 */
	Shooter(MotorConfig, unsigned int);

	/**
	 * @brief Construct a new Shooter object with REV encoder
	 *
	 * @param motorConfig The motor configuration
	 * @param encoderConfig The encoder configuration
	 * @param motorPort The motor port
	 */
	Shooter(MotorConfig, EncoderConfig, unsigned int);

	/**
	 * @brief Construct a new Shooter object with FRC encoder
	 *
	 * @param motorConfig The motor configuration
	 * @param encoderConfig The encoder configuration
	 * @param motorPort The motor port
	 * @param encoderA The encoder A port
	 * @param encoderB The encoder B port
	 */
	Shooter(MotorConfig, EncoderConfig, unsigned int, unsigned int, unsigned int);

	void Periodic() override;

	/**
	 * @brief Resets the encoder and speed PID
	 */
	void Reset();

	// ---------- Actions -----------

	/**
	 * @brief Sets shooter to full speed
	 */
	void Shoot();

	// --------- Angle with Servos --------

	/**
	 * @brief Sets the shooting angle by using servos
	 * @param angle The angle to set the shooter to
	 */
	void SetAngleServos(double);

	/**
	 * @brief Configure angle servo's ports
	 *
	 * @param rightServo The right servo port
	 * @param leftServo The left servo port
	 */
	void ConfigureServos(unsigned int, unsigned int);

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

	/**
	 * @brief Calculates the required RPM to shoot at the current distance
	 * @return The required RPM
	 */
	double CalculateRPM();

	/**
	 * @brief Sets the function that will be used to calculate rpm according to distance
	 *
	 * @param func The function to set
	 */
	void SetRPMCalculationFunction(double (*func)(double));

	// ---------- Components ----------

	Servo *m_rightServo;

	Servo *m_leftServo;

	Limelight m_limelight;

private:
	double (*m_rpmCalculationFunction)(double);
};