#pragma once
#include "Constants.h"
#include "subsystems/EncoderSubsystem.h"
#include "subsystems/Limelight.h"
#include <frc/DigitalInput.h>
#include <frc/Encoder.h>
#include <frc/controller/PIDController.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

using namespace frc;
using namespace frc2;
using namespace rev;

namespace TecDroid
{
	class TurretBase : public EncoderSubsystem
	{
	public:
		/**
		 * @brief Construct a new Turret object with a REV encoder
		 *
		 * @param motorConfig The motor configuration
		 * @param encoderConfig The encoder configuration
		 * @param motorPort The motor port
		 */
		TurretBase(MotorConfig, EncoderConfig, unsigned int);

		/**
		 * @brief Construct a new Turret object with an FRC encoder
		 *
		 * @param motorConfig The motor configuration
		 * @param encoderConfig The encoder configuration
		 * @param motorPort The motor port
		 * @param encoderA The encoder A port
		 * @param encoderB The encoder B port
		 */
		TurretBase(MotorConfig, EncoderConfig, unsigned int, unsigned int, unsigned int);

		void Periodic() override;

		// ---------- Actions -----------

		/**
		 * @brief Resets encoder and PID controllers
		 */
		void Reset();

		/**
		 * @brief Keeps the turret at the last angle
		 */
		void KeepStill(double);

		/**
		 * @brief Turns the turret
		 * @param speed Speed and direction to turn
		 */
		void Turn(double);

		/**
		 * @brief Sets the turret to angle 0
		 * @param speed Speed and direction to turn
		 * @return True if the turret is centered
		 */
		bool Center(double);

		// ---------- Angle ---------

		/**
		 * @brief Sets the turret to a specific angle
		 * @param angle The angle to set the turret to
		 * @param speed The speed to turn the turret at
		 * @return Has the turret reached the angle
		 */
		bool SetAngle(double, double);

		/**
		 * @brief Gets the turret's current angle
		 * @return The turret's current angle
		 */
		double GetAngle();

		/**
		 * @brief Configure angle auto PID's values, tolerance and direction
		 * @param p The proportional value
		 * @param i The integral value
		 * @param d The derivative value
		 * @param tolerance The tolerance value
		 * @param inverted Is the PID inverted
		 */
		void ConfigureAnglePID(double, double, double, double, bool = false);

		/**
		 * @brief Prints the turret's angle
		 */
		void PrintAngle();

		/**
		 * @brief Prints the turret's angle PID error
		 */
		void PrintAnglePIDError();

		// --------- Align ---------

		/**
		 * @brief Aligns the turret to the target
		 * @param speed The speed to turn the turret at
		 * @return Has the turret reached the target
		 */
		bool Align(double);

		/**
		 * @brief Resets the PID controller for aligning to target
		 */
		void ResetAlignPID();

		/**
		 * @brief Configure align PID's values, tolerance and direction
		 * @param p The proportional value
		 * @param i The integral value
		 * @param d The derivative value
		 * @param tolerance The tolerance value
		 * @param inverted Is the PID inverted
		 */
		void ConfigureAlignPID(double, double, double, double, bool = false);

		/**
		 * @brief Publishes the alignPID error on the SmartDashboard
		 */
		void PrintAlignPIDError();

		/**
		 * @brief Sets the turret's freedom of revolution
		 *
		 */
		void SetFreedom(double);

		// ---------- Components ----------

		Limelight m_limelight;

		PIDController m_alignPID{0.1, 0, 0};

	private:
		// ---------- Attributes ----------

		double m_angle;

		bool m_keepingStill = false;

		bool m_limitSafety = false;

		bool m_angleSafety = false;

		double m_freedom = 360;

		int m_anglePIDDirection = 1;

		int m_alignPIDDirection = 1;
	};
}