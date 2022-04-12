#include "subsystems/Claw.h"

Claw::Claw()
{
	SetName("Claw");
}

Claw::Claw(unsigned int solenoidA, unsigned int solenoidB)
{
	m_hand.SetName("Claw Hand");
	m_hand.ConfigureSolenoid(solenoidA, solenoidB);
}

Claw::Claw(unsigned int handA, unsigned int handB, unsigned int wristA, unsigned int wristB)
{
	m_hand.SetName("Claw Hand");
	m_wrist.SetName("Claw Wrist");
	m_hand.ConfigureSolenoid(handA, handB);
	m_wrist.ConfigureSolenoid(wristA, wristB);
}

void Claw::Periodic()
{
}

void Claw::OpenHand()
{
	m_hand.OpenSolenoids();
}

void Claw::CloseHand()
{
	m_hand.CloseSolenoids();
}

void Claw::ToggleHand()
{
	m_hand.ToggleSolenoids();
}

void Claw::InvertHand(bool invert)
{
	m_hand.InvertSolenoids(invert);
}

void Claw::HandOff()
{
	m_hand.SolenoidsOff();
}

unsigned int Claw::GetHand()
{
	return m_hand.GetSolenoid();
}

void Claw::PrintHand()
{
	m_hand.PrintSolenoids();
}

void Claw::RaiseWrist()
{
	m_wrist.CloseSolenoids();
}

void Claw::LowerWrist()
{
	m_wrist.OpenSolenoids();
}

void Claw::ToggleWrist()
{
	m_wrist.ToggleSolenoids();
}

void Claw::InvertWrist(bool invert)
{
	m_wrist.InvertSolenoids(invert);
}

void Claw::WristOff()
{
	m_wrist.SolenoidsOff();
}

unsigned int Claw::GetWrist()
{
	return m_wrist.GetSolenoid();
}

void Claw::PrintWrist()
{
	m_wrist.PrintSolenoids();
}