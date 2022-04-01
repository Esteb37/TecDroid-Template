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

	void Take();

	void Spit();

	void Lower();

	void Raise();

	// ---------- Motor -----------

	void SetMotor(double);

	double GetMotor();

	void InvertMotor(bool);

	void PrintMotor();

	// ---------- Encoder -----------

	void InvertSolenoids();

	void SolenoidsOff();

	bool GetRightSolenoid();

	bool GetLeftSolenoid();

	void PrintSolenoids();

private:
	// ---------- Motor ----------

	VictorSP m_motor{pIntakeMotor};

	// TODO : change if sparkmax

	// CANSparkMax m_motorSparkMax{pIntakeMotor, CANSparkMax::MotorType::kBrushed};

	// ---------- Solenoids ---------

	DoubleSolenoid m_rightSolenoid{PneumaticsModuleType::REVPH, pIntakeRightSolenoidForward, pIntakeRightSolenoidReverse};

	DoubleSolenoid m_leftSolenoid{PneumaticsModuleType::REVPH, pIntakeLeftSolenoidForward, pIntakeLeftSolenoidReverse};

	// ---------- Attributes ----------

	bool m_solenoidsInverted = false;
};
