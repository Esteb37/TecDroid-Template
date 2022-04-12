#pragma once

#include "Constants.h"

#include "subsystems/MotorSubsystem.h"
#include <ctre/Phoenix.h>
#include <frc/DigitalInput.h>
#include <frc/Encoder.h>
#include <frc/controller/PIDController.h>
#include <frc/motorcontrol/VictorSP.h>
#include <rev/CANSparkMax.h>

using namespace frc;
using namespace frc2;
using namespace rev;

class Elevator : public EncoderSubsystem
{
public:
	Elevator(MotorConfig, unsigned int);

	void Periodic() override;

	// ---------- Actions -----------

	/**
	 * @brief Resets sensors and PIDs
	 */
	void Reset();

	/**
	 * @brief Moves the elevator
	 * @param speed Speed and direction to move
	 */
	void Move(double);

	/**
	 * @brief Keeps the elevator at the current position
	 */
	void KeepStill();

	// ---------- Limits ---------

	/**
	 * @brief Checks if the elevator is at the top
	 * @return If the elevator is at the top
	 */
	bool GetTopLimit();

	/**
	 * @brief Checks if the elevator is at the bottom
	 * @return If the elevator is at the bottom
	 */
	bool GetBottomLimit();

	/**
	 * @brief Publishes the limits to the dashboard
	 */
	void PrintLimits();

	// --------- Safety ----------

	/**
	 * @brief Enable safety with limit switches
	 * @param enable True to enable, false to not
	 */
	void SetLimitSafetyActive(bool);

private:
	PIDController m_heightPID{k_elevatorHeightP, k_elevatorHeightI, k_elevatorHeightD};

	// ---------- Limits ----------

	DigitalInput m_limitSwitchTop{pElevatorLimitTop};

	DigitalInput m_limitSwitchBottom{pElevatorLimitBottom};

	// ---------- Safety ----------

	double m_height;

	bool m_keepingStill = false;

	bool m_limitSafety = false;

	bool m_heightSafety = false;

	MotorConfig m_config;
};
