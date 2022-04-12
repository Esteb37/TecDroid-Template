#pragma once
#include "Constants.h"
#include "subsystems/MotorSubsystem.h"
#include "subsystems/SolenoidSubsystem.h"
#include <frc/DoubleSolenoid.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

using namespace frc;
using namespace frc2;
using namespace rev;

class Intake : public MotorSubsystem, public SolenoidSubsystem
{

public:
	Intake(MotorConfig, unsigned int);

	Intake(MotorConfig, unsigned int, unsigned int, unsigned int);

	Intake(MotorConfig, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

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

private:
};
