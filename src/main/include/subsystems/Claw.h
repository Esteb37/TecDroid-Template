#pragma once
#include "Constants.h"

#include "subsystems/SolenoidSubsystem.h";
#include <frc/smartdashboard/SmartDashboard.h>

using namespace frc;
using namespace frc2;

class Claw : public SubsystemBase
{

public:
	Claw();

	Claw(unsigned int, unsigned int);

	Claw(unsigned int, unsigned int, unsigned int, unsigned int);

	void Periodic() override;

	// ---------- Actions -----------

	/**
	 * @brief Opens the claw
	 */
	void OpenHand();

	/**
	 * @brief Closes the claw
	 */
	void CloseHand();

	/**
	 * @brief Toggles between open and closed claw
	 */
	void ToggleHand();

	/**
	 * @brief Lowers the claw
	 */
	void LowerWrist();

	/**
	 * @brief Raises the claw
	 */
	void RaiseWrist();

	/**
	 * @brief Toggles between low and up claw
	 */
	void ToggleWrist();

	// ---------- Hand Solenoid --------

	/**
	 * @brief Inverts open and close status
	 * @param invert True to invert, false to not
	 */
	void InvertHand(bool);

	/**
	 * @brief Turns the hand solenoid off
	 */
	void HandOff();

	/**
	 * @brief Get the hand solenoid status
	 * @return the solenoid status
	 */
	unsigned int GetHand();

	/**
	 * @brief Publishes the hand solenoid status to the dashboard
	 */
	void PrintHand();

	// ---------- Wrist Solenoid --------

	/**
	 * @brief Inverts low and up status
	 * @param invert True to invert, false to not
	 */
	void InvertWrist(bool);

	/**
	 * @brief Turns the wrist solenoid off
	 */
	void WristOff();

	/**
	 * @brief Get the wrist solenoid status
	 * @return the solenoid status
	 */
	unsigned int GetWrist();

	/**
	 * @brief Publishes the wrist solenoid status to the dashboard
	 */
	void PrintWrist();

private:
	SolenoidSubsystem m_hand;
	SolenoidSubsystem m_wrist;

	bool m_wristLowered = false;
	bool m_handOpen = false;
};
