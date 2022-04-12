#pragma once
#include "Constants.h"
#include "subsystems/MotorSubsystem.h"
#include <frc/DoubleSolenoid.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

using namespace frc;
using namespace frc2;
using namespace rev;

class SolenoidSubsystem : virtual public SubsystemBase
{

public:
	SolenoidSubsystem();

	SolenoidSubsystem(unsigned int, unsigned int);

	SolenoidSubsystem(unsigned int, unsigned int, unsigned int, unsigned int);

	void Periodic() override;

	// ---------- Solenoids -----------

	void ConfigureSolenoid(unsigned int, unsigned int);

	void ConfigureSolenoids(unsigned int, unsigned int, unsigned int, unsigned int);

	/**
	 * @brief Invert which value is up or down
	 */
	void InvertSolenoids(bool invert);

	/**
	 * @brief Sets the solenoids to kOFF
	 */
	void SolenoidsOff();

	void OpenSolenoids();

	void CloseSolenoids();

	void ToggleSolenoids();

	/**
	 * @brief Get the right solenoid state
	 */
	unsigned int GetRightSolenoid();

	/**
	 * @brief Get the left solenoid state
	 */
	unsigned int GetLeftSolenoid();

	unsigned int GetSolenoid();

	/**
	 * @brief Publishes the solenoids' value on the SmartDashboard
	 */
	void PrintSolenoids();

private:
	DoubleSolenoid *m_rightSolenoid;

	DoubleSolenoid *m_leftSolenoid;

	bool m_isDoubleSolenoid = false;

	bool m_solenoidsInverted = false;

	bool m_isOpen = false;
};
