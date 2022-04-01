#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Feeder.h"

using namespace frc2;

class Feed
	: public CommandHelper<CommandBase, Feed>
{
public:
	explicit Feed(Feeder *feeder);

	void Initialize() override;

	void Execute() override;

	bool IsFinished() override;

private:
	Feeder *m_feeder;

	Timer m_timer;
};