#include "subsystems/Claw.h"

Claw::Claw()
{
}

void Claw::OpenHand()
{
	if (m_wristInverted)
	{
		m_wrist.Set(DoubleSolenoid::Value::kReverse);
	}
	else
	{
		m_wrist.Set(DoubleSolenoid::Value::kForward);
	}

	m_handOpen = true;
}

void Claw::CloseHand()
{
	if (m_wristInverted)
	{
		m_wrist.Set(DoubleSolenoid::Value::kForward);
	}
	else
	{
		m_wrist.Set(DoubleSolenoid::Value::kReverse);
	}

	m_handOpen = false;
}

void Claw::ToggleHand()
{
	if (m_handOpen)
	{
		CloseHand();
	}
	else
	{
		OpenHand();
	}
}

void Claw::InvertHand(bool invert)
{
	m_handInverted = invert;
}

void Claw::HandOff()
{
	m_hand.Set(DoubleSolenoid::Value::kOff);
}

unsigned int Claw::GetHand()
{
	m_hand.Get();
}

void Claw::PrintHand()
{
	SmartDashboard::PutNumber("Claw Hand", GetHand());
}

void Claw::RaiseWrist()
{
	if (m_wristInverted)
	{
		m_wrist.Set(DoubleSolenoid::Value::kForward);
	}
	else
	{
		m_wrist.Set(DoubleSolenoid::Value::kReverse);
	}

	m_wristLowered = false;
}

void Claw::LowerWrist()
{
	if (m_wristInverted)
	{
		m_wrist.Set(DoubleSolenoid::Value::kReverse);
	}
	else
	{
		m_wrist.Set(DoubleSolenoid::Value::kForward);
	}

	m_wristLowered = true;
}

void Claw::ToggleWrist()
{
	if (m_wristLowered)
	{
		RaiseWrist();
	}
	else
	{
		LowerWrist();
	}
}

void Claw::InvertWrist(bool invert)
{
	m_wristInverted = invert;
}

void Claw::WristOff()
{
	m_wrist.Set(DoubleSolenoid::Value::kOff);
}

unsigned int Claw::GetWrist()
{
	m_wrist.Get();
}

void Claw::PrintWrist()
{
	SmartDashboard::PutNumber("Claw Wrist", GetWrist());
}