#include "commands/TimedLoad.h"

TimedLoad::TimedLoad(Shooter *shooter)
{
	m_shooter = shooter;
}

void TimedLoad::Initialize()
{
	m_timer.Reset();
	m_timer.Start();
}

void TimedLoad::Execute()
{
	m_shooter->SetMotor(1);
}

bool TimedLoad::IsFinished()
{
	return m_timer.Get().value() >= k_shooterLoadTime;
}
