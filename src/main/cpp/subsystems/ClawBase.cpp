/*------------------------------------------------------------
						&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& /&&&&,
					.&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& /&&&&&&&&%
				.&&&&/ &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& /&&&&&&&&&&&*
			.%&&&(      &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&% %&&&&&&&&&&&&&
		%&&&#     %#&&#           (&&&&&&&&&&&              %&&&&&&&&&&&&&
	*&&&#                          (&&&&&&&&&&&    /           %&&&&&&&&&&&
*&%  ,                           (&&&&&&&&&&&(&&&&(           &&&&&&&&&&&
& (,..                          (&&&&&&&&&&&&&&&&            %&&&&&&&&&&
	&*                             (&&&&&&&&&&&&&&&&            &&&&&&&&&&&
	&/                             (&&&&&&&&&&&&&&&&%          &&&&&&&&&&&(
	#&&    .&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#**(&&&&&&&&&&&&&#
	&#  (&                        ......... &&&&&&&&&&&&&&&&&&&&&&&&&&
	/&   &                                   .&&&&&&&&&&&&&&&&&&&&&&
		%&&* &*                                   ,%&&&&&&&&&&&&&%*

	Author: Esteban Padilla Cerdio
	Email: esteban37padilla@gmail.com
	URL: github.com/esteb37
		 github.com/tecdroid-3354
	Date: 12/04/2022
	Language: cpp
	Copyright (c) TecDroid 3354 and Esteban Padilla Cerdio
	Open Source Software; you can modify and/or share it under the terms of
*/

#include "subsystems/ClawBase.h"

using namespace TecDroid;

ClawBase::ClawBase()
{
	SetName("Claw");
}

ClawBase &ClawBase::GetInstance()
{
	static ClawBase instance;
	return instance;
}

void ClawBase::Initialize(unsigned int solenoidForward, unsigned int solenoidReverse)
{
	m_hand.SetName("Claw Hand");
	m_hand.Initialize(solenoidForward, solenoidReverse);
}

void ClawBase::Initialize(unsigned int handForward, unsigned int handReverse, unsigned int wristForward, unsigned int wristReverse)
{
	m_hand.SetName("Claw Hand");
	m_wrist.SetName("Claw Wrist");
	m_hand.Initialize(handForward, handReverse);
	m_wrist.Initialize(wristForward, wristReverse);
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