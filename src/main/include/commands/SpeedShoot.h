#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "commands/Feed.h"
#include "commands/SpeedLoad.h"

class SpeedShoot : public CommandHelper<SequentialCommandGroup, SpeedShoot>
{

public:
	SpeedShoot(Shooter *shooter, Feeder *feeder);
};