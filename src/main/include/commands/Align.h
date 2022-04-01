#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Turret.h"

using namespace frc2;

class Align
	: public CommandHelper<CommandBase, Align>
{
public:
	explicit Align(Turret *turret);

	bool IsFinished() override;

private:
	Turret *m_turret;
};