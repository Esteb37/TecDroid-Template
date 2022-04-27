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

#include <ctre/Phoenix.h>
#include <frc/DigitalInput.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSParkMax.h>

using namespace frc;
using namespace frc2;
using namespace rev;
using namespace std;

namespace TecDroid
{
	enum class MotorConfig
	{
		kNeo,
		kSpark,
		kVictorPWM,
		kVictorCAN,
	};

	class MotorSubsystem : virtual public SubsystemBase
	{

	public:
		MotorSubsystem();

		static MotorSubsystem &GetInstance();

		void Initialize(MotorConfig, unsigned int);

		void Initialize(MotorConfig, vector<unsigned int>);

		void Periodic() override;

		// ---------- Motor -----------

		/**
		 * @brief Sets the Motor speed
		 * @param speed Speed and direction to turn
		 */
		void SetMotor(double);

		void SetMotors(double);

		void SetMotors(vector<double>);

		void SetMaxSpeed(double);

		/**
		 * @brief Gets the Motor speed
		 */
		double GetMotor();

		vector<double> GetMotors();

		/**
		 * @brief Invert motor direction
		 * @param invert True to invert, false to not
		 */
		void InvertMotor(bool);

		void InvertMotors(vector<bool>);

		/**
		 * @brief Publishes the motor speed to the dashboard
		 */
		void PrintMotor();

		void PrintMotors();

		bool GetUpperLimit();

		bool GetLowerLimit();

		void ConfigureLimitSwitches(unsigned int, unsigned int);

		void SetLimitSafety(bool);

		void PrintLimits();

		// ---------- Components -----------

		CANSparkMax *m_motorSpark;

		VictorSPX *m_motorVictorCAN;

		VictorSP *m_motorVictorPWM;

		vector<CANSparkMax *> m_motorSparkList;

		vector<VictorSPX *> m_motorVictorCANList;

		vector<VictorSP *> m_motorVictorPWMList;

		DigitalInput *m_upperLimit;

		DigitalInput *m_lowerLimit;

	protected:
		MotorConfig m_motorConfig;

		double m_maxSpeed;

		bool m_limitSafetyActive = false;

		unsigned int m_motorCount = 1;
	};
}