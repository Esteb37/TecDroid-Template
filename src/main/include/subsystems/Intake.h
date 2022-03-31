#pragma once
#include "Constants.h"
#include <frc/DoubleSolenoid.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

using namespace frc;
using namespace frc2;
using namespace rev;

template <typename MotorType>
class Intake : public SubsystemBase
{

public:
	Intake();

	void Periodic() override;

	void Take();

	void Spit();

	void SetMotor(double);

	double GetMotor();

	void InvertMotor(bool);

	void PrintMotor();

	void Lower();

	void Raise();

	void InvertSolenoids();

	void SolenoidsOff();

	bool GetRightSolenoid();

	bool GetLeftSolenoid();

	void PrintSolenoids();

private:
	MotorType *m_motor;

	DoubleSolenoid m_rightSolenoid{PneumaticsModuleType::REVPH, pIntakeRightSolenoidForward, pIntakeRightSolenoidReverse};

	DoubleSolenoid m_leftSolenoid{PneumaticsModuleType::REVPH, pIntakeLeftSolenoidForward, pIntakeLeftSolenoidReverse};

	bool m_solenoidsInverted = false;
};
