#include "commands/SpeedLoad.h"

SpeedLoad::SpeedLoad(Shooter *shooter)
{
	m_shooter = shooter;
}

void SpeedLoad::Initialize()
{
	m_shooter->ResetPID();
	m_shooter->ResetEncoder();

	m_targetRPM = m_shooter->CalculateRPM();
}

bool SpeedLoad::IsFinished()
{
	return m_shooter->ReachRPM(m_targetRPM);
}
