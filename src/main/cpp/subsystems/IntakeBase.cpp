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

#include "subsystems/IntakeBase.h"

using namespace TecDroid;

IntakeBase::IntakeBase()
{
	SetName("Intake");
}

IntakeBase &IntakeBase::GetInstance()
{
	static IntakeBase instance;
	return instance;
}

void IntakeBase::Configure(MotorConfig config, unsigned int port, unsigned int solenoidForward, unsigned int solenoidReverse)
{
	MotorSubsystem::Configure(config, port);
	SolenoidSubsystem::Configure(solenoidForward, solenoidReverse);
}

void IntakeBase::Configure(MotorConfig config, vector<unsigned int> ports, unsigned int solenoidForward, unsigned int solenoidReverse)
{
	MotorSubsystem::Configure(config, ports);
	SolenoidSubsystem::Configure(solenoidForward, solenoidReverse);
}

void IntakeBase::Configure(MotorConfig config, unsigned int port, unsigned int rightForward, unsigned int rightReverse, unsigned int leftForward, unsigned int leftReverse)
{
	MotorSubsystem::Configure(config, port);
	SolenoidSubsystem::Configure(rightForward, rightReverse, leftForward, leftReverse);
}

void IntakeBase::Configure(MotorConfig config, vector<unsigned int> ports, unsigned int rightForward, unsigned int rightReverse, unsigned int leftForward, unsigned int leftReverse)
{
	MotorSubsystem::Configure(config, ports);
	SolenoidSubsystem::Configure(rightForward, rightReverse, leftForward, leftReverse);
}

void IntakeBase::Periodic()
{
}

void IntakeBase::Take()
{
	if (m_motorCount > 1)
	{
		vector<double> speeds(m_motorCount, 1.0);
		SetMotors(speeds);
	}
	else
	{
		SetMotor(1);
	}
}

void IntakeBase::Spit()
{
	if (m_motorCount > 1)
	{
		vector<double> speeds(m_motorCount, -1.0);
		SetMotors(speeds);
	}
	else
	{
		SetMotor(-1);
	}
}

void IntakeBase::Lower()
{
	OpenSolenoids();
}

void IntakeBase::Raise()
{
	CloseSolenoids();
}
