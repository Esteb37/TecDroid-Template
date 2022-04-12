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
	Shooter(MotorConfig, unsigned int);

	Shooter(MotorConfig, EncoderConfig, unsigned int);

	Shooter(MotorConfig, EncoderConfig, unsigned int, unsigned int, unsigned int);

	void Periodic() override;

	void Reset();

	// ---------- Actions -----------

	void Shoot();

	// --------- Angle with Servos --------

	/**
	 * @brief Sets the shooting angle by using servos
	 * @param angle The angle to set the shooter to
	 */
	void SetAngleServos(double);

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

	double CalculateRPM();

	Limelight GetLimelight();

private:
	Servo *m_rightServo;

	Servo *m_leftServo;

	Limelight m_limelight;

	Timer m_timer;

	bool m_timerStarted;
};