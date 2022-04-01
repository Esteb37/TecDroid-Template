#pragma once
#include "Constants.h"
#include <frc/DoubleSolenoid.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

using namespace frc;
using namespace frc2;
using namespace rev;

class Intake : public SubsystemBase
{

public:
	Intake();

	void Periodic() override;

	// ---------- Actions -----------

	/**
	 * @brief Turns the intake inward
	 */
	void Take();

	/**
	 * @brief Turns the intake outward
	 */
	void Spit();

	/**
	 * @brief Lower the intake with solenoids
	 */
	void Lower();

	/**
	 * @brief Raise the intake with solenoids
	 */
	void Raise();

	// ---------- Motor -----------

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

	// ---------- Solenoids -----------

	/**
	 * @brief Invert which value is up or down
	 */
	void InvertSolenoids();

	/**
	 * @brief Sets the solenoids to kOFF
	 */
	void SolenoidsOff();

	/**
	 * @brief Get the right solenoid state
	 */
	unsigned int GetRightSolenoid();

	/**
	 * @brief Get the left solenoid state
	 */
	unsigned int GetLeftSolenoid();

	/**
	 * @brief Publishes the solenoids' value on the SmartDashboard
	 */
	void PrintSolenoids();

private:
	// ---------- Motor ----------

	VictorSP m_motor{pIntakeMotor};

	// TODO : define motor type

	// CANSparkMax m_motorSparkMax{pIntakeMotor, CANSparkMax::MotorType::kBrushed};

	// VictorSPX m_motor{pIntakeMotor};

	// ---------- Solenoids ---------

	DoubleSolenoid m_rightSolenoid{PneumaticsModuleType::REVPH, pIntakeRightSolenoidForward, pIntakeRightSolenoidReverse};

	DoubleSolenoid m_leftSolenoid{PneumaticsModuleType::REVPH, pIntakeLeftSolenoidForward, pIntakeLeftSolenoidReverse};

	// ---------- Attributes ----------

	bool m_solenoidsInverted = false;
};
