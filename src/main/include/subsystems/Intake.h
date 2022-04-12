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
	/**
	 * @brief Construct a new Intake object with a single motor
	 *
	 * @param motorConfig The motor configuration
	 * @param motorPort The motor port
	 */
	Intake(MotorConfig, unsigned int);

	/**
	 * @brief Construct a new Intake object with multiple motors
	 *
	 * @param motorConfig The motor configuration
	 * @param motorPorts The motor ports
	 */
	Intake(MotorConfig, vector<unsigned int>);

	/**
	 * @brief Construct a new Intake object with a single motor and a single solenoid
	 *
	 * @param motorConfig The motor configuration
	 * @param motorPort The motor port
	 * @param solenoidForward The solenoid forward port
	 * @param solenoidReverse The solenoid reverse port
	 */
	Intake(MotorConfig, unsigned int, unsigned int, unsigned int);

	/**
	 * @brief Construct a new Intake object with multiple motors and a single solenoid
	 *
	 * @param motorConfig The motor configuration
	 * @param motorPorts The motor ports
	 * @param solenoidForward The solenoid forward port
	 * @param solenoidReverse The solenoid reverse port
	 */
	Intake(MotorConfig, vector<unsigned int>, unsigned int, unsigned int);

	/**
	 * @brief Construct a new Intake object with a single motor and multiple solenoids
	 *
	 * @param motorConfig The motor configuration
	 * @param motorPort The motor port
	 * @param rightSolenoidForward The right solenoid forward port
	 * @param rightSolenoidReverse The right solenoid reverse port
	 * @param leftSolenoidForward The left solenoid forward port
	 * @param leftSolenoidReverse The left solenoid reverse port
	 */
	Intake(MotorConfig, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

	/**
	 * @brief Construct a new Intake object with multiple motors and multiple solenoids
	 *
	 * @param motorConfig The motor configuration
	 * @param motorPorts The motor ports
	 * @param rightSolenoidForward The right solenoid forward port
	 * @param rightSolenoidReverse The right solenoid reverse port
	 * @param leftSolenoidForward The left solenoid forward port
	 * @param leftSolenoidReverse The left solenoid reverse port
	 */
	Intake(MotorConfig, vector<unsigned int>, unsigned int, unsigned int, unsigned int, unsigned int);

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
