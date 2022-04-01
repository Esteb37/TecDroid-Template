#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Shooter.h"

using namespace frc2;

class SpeedLoad
	: public CommandHelper<frc2::CommandBase, SpeedLoad>
{
public:
	explicit SpeedLoad(Shooter *shooter);

	void Initialize() override;

	bool IsFinished() override;

private:
	Shooter *m_shooter;

	double m_targetRPM;
};