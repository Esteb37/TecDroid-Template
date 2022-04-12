#pragma once

#include "Constants.h"

#include "subsystems/EncoderSubsystem.h"
#include <ctre/Phoenix.h>
#include <frc/DigitalInput.h>
#include <frc/Encoder.h>
#include <frc/controller/PIDController.h>
#include <frc/motorcontrol/VictorSP.h>
#include <rev/CANSparkMax.h>

using namespace frc;
using namespace frc2;
using namespace rev;

namespace TecDroid
{
	class ElevatorBase : public EncoderSubsystem
	{
	public:
		/**
		 * @brief Construct a new Elevator object with no encoder and a single motor
		 *
		 * @param motorConfig The motor configuration
		 * @param motorPort The motor port
		 */
		ElevatorBase(MotorConfig, unsigned int);

		/**
		 * @brief Construct a new Elevator object with no encoder and multiple motors
		 *
		 * @param motorConfig The motor configuration
		 * @param motorPorts The motor ports
		 */
		ElevatorBase(MotorConfig, vector<unsigned int>);

		/**
		 * @brief Construct a new Elevator object with a REV encoder and a single motor
		 *
		 * @param motorConfig The motor configuration
		 * @param encoderConfig The encoder configuration
		 * @param motorPort The motor port
		 */
		ElevatorBase(MotorConfig, EncoderConfig, unsigned int);

		/**
		 * @brief Construct a new Elevator object with a REV encoder and multiple motors
		 *
		 * @param motorConfig The motor configuration
		 * @param encoderConfig The encoder configuration
		 * @param motorPorts The motor ports
		 */
		ElevatorBase(MotorConfig, EncoderConfig, vector<unsigned int>);

		/**
		 * @brief Construct a new Elevator object with an FRC encoder and a single motor
		 *
		 * @param motorConfig The motor configuration
		 * @param encoderConfig The encoder configuration
		 * @param motorPort The motor port
		 * @param encoderA The A port of the encoder
		 * @param encoderB The B port of the encoder
		 */
		ElevatorBase(MotorConfig, EncoderConfig, unsigned int, unsigned int, unsigned int);

		/**
		 * @brief Construct a new Elevator object with an FRC encoder and multiple motors
		 *
		 * @param motorConfig The motor configuration
		 * @param encoderConfig The encoder configuration
		 * @param motorPorts The motor ports
		 * @param encoderA The A port of the encoder
		 * @param encoderB The B port of the encoder
		 */
		ElevatorBase(MotorConfig, EncoderConfig, vector<unsigned int>, unsigned int, unsigned int);

		void Periodic() override;

		// ---------- Actions -----------

		/**
		 * @brief Moves the elevator
		 * @param speed Speed and direction to move
		 */
		void Move(double);

		/**
		 * @brief Sets the offset of the elevator height relative to the floor
		 * @param height The height offset
		 */
		void SetHeightToFloor(double);

		/**
		 * @brief Gets the height of the elevator relative to itself
		 *
		 * @return The relative height
		 */
		double GetRelativeHeight();

		/**
		 * @brief Gets the height of the elevator relative to the floor
		 *
		 * @return The height of the elevator relative to the floor
		 */
		double GetAbsoluteHeight();

		/**
		 * @brief Sets the height of the elevator relative to itself
		 * @param height The height to set
		 * @param speed The speed to move at
		 * @return True if the elevator is at the specified height
		 */
		bool SetRelativeHeight(double, double);

		/**
		 * @brief Sets the height of the elevator relative to the floor
		 * @param height The height to set
		 * @param speed The speed to move at
		 * @return True if the elevator is at the specified height
		 */
		bool SetAbsoluteHeight(double, double);

		/**
		 * @brief Sets the minimum and maximum height for safety
		 * @param min The minimum height
		 * @param max The maximum height
		 */
		void SetMinMaxHeight(double, double);

	protected:
		double m_heightToFloor;
	};
}