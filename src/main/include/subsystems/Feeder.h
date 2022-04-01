#pragma once

#include "Constants.h"
#include <frc/motorcontrol/VictorSP.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSParkMax.h>

using namespace frc;
using namespace frc2;
using namespace rev;

class Feeder : public SubsystemBase
{

public:
	Feeder();

	void Periodic() override;

	void SetMotor(double);

	double GetMotor();

	void InvertMotor(bool);

	void PrintMotor();

private:
	VictorSP motor{pFeederMotor};

	// TODO : define motor type

	// CANSparkMax m_motor{pFeederMotor, CANSparkMax::MotorType::kBrushed};

	// VictorSPX m_motor{pFeederMotor};
};
