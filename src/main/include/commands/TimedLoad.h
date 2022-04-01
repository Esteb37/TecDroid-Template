#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Shooter.h"

using namespace frc2;

class TimedLoad
	: public CommandHelper<CommandBase, TimedLoad>
{
public:
	explicit TimedLoad(Shooter *);

	void Initialize() override;

	void Execute() override;

	bool IsFinished() override;

private:
	Shooter *m_shooter;

	Timer m_timer;
};