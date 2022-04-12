#pragma once
#include "Constants.h"
#include "subsystems/EncoderSubsystem.h"
#include "subsystems/Limelight.h"
#include <frc/DigitalInput.h>
#include <frc/Encoder.h>
#include <frc/controller/PIDController.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

using namespace frc;
using namespace frc2;
using namespace rev;

class Turret : public EncoderSubsystem
{
public:
	Turret(MotorConfig, EncoderConfig, unsigned int);

	Turret(MotorConfig, EncoderConfig, unsigned int, unsigned int, unsigned int);

	/**
	 * Will be called periodically whenever the CommandScheduler runs.
	 */
	void Periodic() override;

	// ---------- Actions -----------

	void Reset();

	void KeepStill(bool);

	/**
	 * @brief Turns the turret
	 * @param speed Speed and direction to turn
	 */
	void Turn(double);

	/**
	 * @brief Sets the turret to angle 0
	 */
	bool Center(bool);

	// ---------- Angle ---------

	/**
	 * @brief Sets the turret to a specific angle
	 * @return Has the turret reached the angle
	 */
	bool SetAngle(double, bool);

	/**
	 * @brief Gets the turret's current angle
	 * @return The turret's current angle
	 */
	double GetAngle();

	void PrintAngle();

	void PrintAnglePIDError();

	// --------- Align ---------

	/**
	 * @brief Aligns the turret to the target
	 * @return Has the turret reached the target
	 */
	bool Align(bool);

	/**
	 * @brief Resets the PID controller for aligning to target
	 */
	void ResetAlignPID();

	void ConfigureAlignPID(double, double, double, double);

	/**
	 * @brief Publishes the alignPID error on the SmartDashboard
	 */
	void PrintAlignPIDError();

	void SetFreedom(double);

	Limelight GetLimelight();

private:
	Limelight m_limelight;

	// ---------- PID ---------

	PIDController m_alignPID{0.1, 0, 0};

	// ---------- Attributes ----------

	double m_angle;

	bool m_keepingStill = false;

	bool m_limitSafety = false;

	bool m_angleSafety = false;

	double m_freedom = 360;
};
