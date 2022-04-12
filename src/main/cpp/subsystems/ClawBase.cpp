#include "subsystems/ClawBase.h"

using namespace TecDroid;

ClawBase::ClawBase()
{
	SetName("Claw");
}

ClawBase::ClawBase(unsigned int solenoidA, unsigned int solenoidB)
{
	m_hand.SetName("Claw Hand");
	m_hand.ConfigureSolenoid(solenoidA, solenoidB);
}

ClawBase::ClawBase(unsigned int handA, unsigned int handB, unsigned int wristA, unsigned int wristB)
{
	m_hand.SetName("Claw Hand");
	m_wrist.SetName("Claw Wrist");
	m_hand.ConfigureSolenoid(handA, handB);
	m_wrist.ConfigureSolenoid(wristA, wristB);
}

void ClawBase::Periodic()
{
}

void ClawBase::OpenHand()
{
	m_hand.OpenSolenoids();
}

void ClawBase::CloseHand()
{
	m_hand.CloseSolenoids();
}

void ClawBase::ToggleHand()
{
	m_hand.ToggleSolenoids();
}

void ClawBase::InvertHand(bool invert)
{
	m_hand.InvertSolenoids(invert);
}

void ClawBase::HandOff()
{
	m_hand.SolenoidsOff();
}

unsigned int ClawBase::GetHand()
{
	return m_hand.GetSolenoid();
}

void ClawBase::PrintHand()
{
	m_hand.PrintSolenoids();
}

void ClawBase::RaiseWrist()
{
	m_wrist.CloseSolenoids();
}

void ClawBase::LowerWrist()
{
	m_wrist.OpenSolenoids();
}

void ClawBase::ToggleWrist()
{
	m_wrist.ToggleSolenoids();
}

void ClawBase::InvertWrist(bool invert)
{
	m_wrist.InvertSolenoids(invert);
}

void ClawBase::WristOff()
{
	m_wrist.SolenoidsOff();
}

unsigned int ClawBase::GetWrist()
{
	return m_wrist.GetSolenoid();
}

void ClawBase::PrintWrist()
{
	m_wrist.PrintSolenoids();
}