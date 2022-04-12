#pragma once

#include "Constants.h"
#include "subsystems/MotorSubsystem.h"
#include <ctre/Phoenix.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <rev/CANSParkMax.h>

using namespace frc;
using namespace frc2;
using namespace rev;

class Feeder : public MotorSubsystem
{

public:
	Feeder(MotorConfig, unsigned int);

	void Periodic() override;

	// ---------- Actions -----------

	void Feed();

	void Unfeed();
};
