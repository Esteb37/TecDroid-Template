#include "commands/SpeedShoot.h"

SpeedShoot::SpeedShoot(Shooter *shooter, Feeder *feeder)
{
	AddCommands(SpeedLoad(shooter), Feed(feeder));
}