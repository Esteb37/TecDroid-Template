#pragma once

#include "Constants.h"
#include "subsystems/MotorSubsystem.h"
#include <ctre/Phoenix.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <rev/CANSParkMax.h>

using namespace frc;
using namespace frc2;
using namespace rev;

namespace TecDroid
{
	class FeederBase : public MotorSubsystem
	{

	public:
		/**
		 * @brief Construct a new Feeder object with a single motor
		 *
		 * @param motorConfig The motor configuration
		 * @param motorPort The motor port
		 */
		FeederBase(MotorConfig, unsigned int);

		/**
		 * @brief Construct a new Feeder object with multiple motors
		 *
		 * @param motorConfig The motor configuration
		 * @param motorPorts The motor ports
		 */
		FeederBase(MotorConfig, vector<unsigned int>);

		void Periodic() override;

		// ---------- Actions -----------

		/**
		 * @brief Move the feeder inwards
		 */
		void Feed();

		/**
		 * @brief Move the feeder outwards
		 */
		void Unfeed();
	};
}