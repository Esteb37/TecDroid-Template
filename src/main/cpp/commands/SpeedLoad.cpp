#include "commands/SpeedLoad.h"

SpeedLoad::SpeedLoad(Shooter *shooter)
{
	m_shooter = shooter;
}

void SpeedLoad::Initialize()
{
	m_shooter->ResetSpeedPID();
	m_shooter->ResetEncoder();

	m_targetRPM = m_shooter->CalculateRPM();
}

bool SpeedLoad::IsFinished()
{
	return m_shooter->SetSpeed(m_targetRPM, false);
}
