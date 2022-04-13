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

#pragma once

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableValue.h"
#include "wpi/span.h"
#include <frc/smartdashboard/smartdashboard.h>

using namespace frc;

namespace TecDroid
{
	class Limelight
	{
	private:
		std::shared_ptr<nt::NetworkTable> limelight;

	public:
		Limelight();

		// ---------- Actions ----------

		double GetDistanceToTarget();

		// ---------- Getters ----------

		double GetHorizontalAngle();

		double GetVerticalAngle();

		double GetArea();

		double GetSkew();

		double GetPipeline();

		double GetValid();

		double GetTarget();

		// ---------- Setters ----------

		void SetPipeline(int);

		void SetLED(int);

		void SetCamMode(int);

		void SetStream(int);

		void SetSnapshot(int);

		void SetLight(int);

		void SetLEDMode(int);

		void SetLEDFrequency(int);

		void SetLEDIntensity(int);

		void SetLEDState(int);

		void SetLEDOff();

		void SetLEDOn();

		// ---------- Printers ----------

		void PrintHorizontalAngle();

		void PrintVerticalAngle();

		void PrintDistanceToTarget();

		void PrintArea();

		void PrintSkew();
	};
}