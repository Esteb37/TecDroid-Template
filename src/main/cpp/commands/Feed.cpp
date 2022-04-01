#include "commands/Feed.h"

Feed::Feed(Feeder *feeder)
{
	m_feeder = feeder;
}

void Feed::Initialize()
{
	m_timer.Reset();
	m_timer.Start();
}

void Feed::Execute()
{
	m_feeder->SetMotor(1);
}

bool Feed::IsFinished()
{
	return m_timer.Get().value() >= k_feederFeedTime;
}
