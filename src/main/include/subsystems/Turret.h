#pragma once
#include "Constants.h"
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

class Turret : public SubsystemBase
{
public:
	Turret();

	/**
	 * Will be called periodically whenever the CommandScheduler runs.
	 */
	void Periodic() override;

	// ---------- Actions -----------

	void Reset();

	/**
	 * @brief Turns the turret
	 * @param speed Speed and direction to turn
	 */
	void Turn(double);

	/**
	 * @brief Keeps the turret at the current angle
	 */
	void KeepStill();

	/**
	 * @brief Sets the turret to angle 0
	 */
	bool Center();

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
	 * @brief Publishes the motor's value on the SmartDashboard
	 */
	void PrintMotor();

	// --------- Encoder ---------

	/**
	 * @brief Gets the encoder value
	 */
	double GetEncoder();

	/**
	 * @brief Sets the current encoder value to 0
	 */
	void ResetEncoder();

	/**
	 * @brief Invert encoder direction
	 * @param invert True to invert, false to not
	 */
	void InvertEncoder(bool);

	/**
	 * @brief Publishes the encoder's value on the SmartDashboard
	 */
	void PrintEncoder();

	// ---------- Angle ---------

	/**
	 * @brief Sets the turret to a specific angle
	 * @return Has the turret reached the angle
	 */
	bool SetAngle(double);

	/**
	 * @brief Gets the turret's current angle
	 * @return The turret's current angle
	 */
	double GetAngle();

	/**
	 * @brief Resets the PID controller for setting angle
	 */
	void ResetAnglePID();

	/**
	 * @brief Publishes the turret's current angle on the SmartDashboard
	 */
	void PrintAngle();

	/**
	 * @brief Publishes the anglepid error on the SmartDashboard
	 */
	void PrintAnglePIDError();

	// --------- Align ---------

	/**
	 * @brief Aligns the turret to the target
	 * @return Has the turret reached the target
	 */
	bool Align();

	/**
	 * @brief Resets the PID controller for aligning to target
	 */
	void ResetAlignPID();

	/**
	 * @brief Publishes the alignPID error on the SmartDashboard
	 */
	void PrintAlignPIDError();

	// --------- Limits ----------

	/**
	 * @brief Checks if the turret is at the right limit
	 * @return True if the turret is at the right limit, false if not
	 */
	bool GetRightLimit();

	/**
	 * @brief Checks if the turret is at the left limit
	 * @return True if the turret is at the left limit, false if not
	 */
	bool GetLeftLimit();

	/**
	 * @brief Publish limit values to the SmartDashboard
	 */
	void PrintLimits();

	// --------- Safety ----------

	/**
	 * @brief Enables safety with limits
	 */
	void SetLimitSafetyActive(bool);

	/**
	 * @brief Enables safety with encoder
	 */
	void SetAngleSafetyActive(bool);

private:
	// ---------- Motor ----------

	CANSparkMax m_motor{pTurretMotor, CANSparkMax::MotorType::kBrushed};

	// TODO : define motor type

	// VictorSP m_motor{pTurretMotor};

	// VictorSPX m_motor{pTurretMotor};

	// ---------- Sensors ---------

	Encoder m_encoder{pTurretEncoderA, pTurretEncoderB};

	// TODO : define encoder type

	// SparkMaxRelativeEncoder m_encoder{m_motor.GetEncoder()};

	Limelight m_limelight;

	DigitalInput m_limitSwitchRight{pTurretLimitSwitchRight};

	DigitalInput m_limitSwitchLeft{pTurretLimitLeft};

	// ---------- PID ---------

	PIDController m_alignPID{k_turretAlignP, k_turretAlignI, k_turretAlignD};

	PIDController m_anglePID{k_turretAngleP, k_turretAngleI, k_turretAngleD};

	// ---------- Attributes ----------

	double m_angle;

	bool m_keepingStill = false;

	bool m_limitSafety = false;

	bool m_angleSafety = false;
};
