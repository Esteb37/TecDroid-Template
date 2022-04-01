#pragma once
#include "Constants.h"
#include <frc/DoubleSolenoid.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/SubsystemBase.h>

using namespace frc;
using namespace frc2;

class Claw : public SubsystemBase
{

public:
	Claw();

	void Periodic() override;

	// ---------- Actions -----------

	void OpenHand();

	void CloseHand();

	void ToggleHand();

	void LowerWrist();

	void RaiseWrist();

	void ToggleWrist();

	// ---------- Hand Solenoid --------

	void InvertHand(bool);

	void HandOff();

	unsigned int GetHand();

	void PrintHand();

	// ---------- Wrist Solenoid --------

	void InvertWrist(bool);

	void WristOff();

	unsigned int GetWrist();

	void PrintWrist();

private:
	// ---------- Solenoids ---------

	DoubleSolenoid m_hand{PneumaticsModuleType::REVPH, pClawHandSolenoidForward, pClawHandSolenoidReverse};

	DoubleSolenoid m_wrist{PneumaticsModuleType::REVPH, pClawWristSolenoidForward, pClawWristSolenoidReverse};

	// ---------- Attributes ----------

	bool m_handInverted = false;

	bool m_wristInverted = false;

	bool m_handOpen = false;

	bool m_wristLowered = false;
};
