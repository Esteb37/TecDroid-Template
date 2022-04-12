#include "commands/Align.h"

Align::Align(Turret *turret)
{
	m_turret = turret;
}

bool Align::IsFinished()
{
	return m_turret->Align(false);
}
