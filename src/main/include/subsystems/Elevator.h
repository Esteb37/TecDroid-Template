#pragma once

#include "Constants.h"
#include <frc/DigitalInput.h>
#include <frc/Encoder.h>
#include <frc/controller/PIDController.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

using namespace frc;
using namespace frc2;
using namespace rev;

class Elevator : public SubsystemBase
{
public:
	Elevator();

	void Periodic() override;

	// ---------- Actions -----------

	/**
	 * @brief Resets sensors and PIDs
	 */
	void Reset();

	/**
	 * @brief Moves the elevator
	 * @param speed Speed and direction to move
	 */
	void Move(double);

	/**
	 * @brief Keeps the elevator at the current position
	 */
	void KeepStill();

	// --------- Motor ---------

	/**
	 * @brief Sets the Motor speed
	 * @param speed Speed and direction to turn
	 */
	void SetMotor(double);

	/**
	 * @brief Gets the Motor speed
	 */
	double GetMotor();

	/**
	 * @brief Invert motor direction
	 * @param invert True to invert, false to not
	 */
	void InvertMotor(bool);

	/**
	 * @brief Publishes the motor speed to the dashboard
	 */
	void PrintMotor();

	// --------- Encoder ---------

	/**
	 * @brief Get the Encoder value
	 * @return double
	 */
	double GetEncoder();

	/**
	 * @brief Sets the encoder's value to 0
	 */
	void ResetEncoder();

	/**
	 * @brief Inverts the encoder's direction
	 * @param invert True to invert, false to not
	 */
	void InvertEncoder(bool);

	/**
	 * @brief Publishes the Encoder value to the dashboard
	 */
	void PrintEncoder();

	// ---------- Height ---------

	/**
	 * @brief Set the elevator to a specific height
	 * @param height The height to set the elevator to in meters
	 * @return If the elevator has reached the height
	 */
	bool SetHeight(double);

	/**
	 * @brief Get the elevator's height
	 * @return The elevator's height in meters
	 */
	double GetHeight();

	/**
	 * @brief Resets the height PID
	 */
	void ResetHeightPID();

	/**
	 * @brief Publishes the elevator's height to the dashboard
	 */
	void PrintHeight();

	/**
	 * @brief Publishes the height PID error to the dashboard
	 */
	void PrintHeightPIDError();

	// ---------- Limits ---------

	/**
	 * @brief Checks if the elevator is at the top
	 * @return If the elevator is at the top
	 */
	bool GetTopLimit();

	/**
	 * @brief Checks if the elevator is at the bottom
	 * @return If the elevator is at the bottom
	 */
	bool GetBottomLimit();

	/**
	 * @brief Publishes the limits to the dashboard
	 */
	void PrintLimits();

	// --------- Safety ----------

	/**
	 * @brief Enable safety with limit switches
	 * @param enable True to enable, false to not
	 */
	void SetLimitSafetyActive(bool);

	/**
	 * @brief Enable safety with encoder
	 * @param enable True to enable, false to not
	 */
	void SetHeightSafetyActive(bool);

private:
	// ---------- Motor ----------

	CANSparkMax m_motor{pElevatorMotor, CANSparkMax::MotorType::kBrushed};

	// VictorSP m_motor{pElevatorMotor};

	// VictorSPX m_motor{pElevatorMotor};

	// ---------- Encoder ----------

	Encoder m_encoder{pElevatorEncoderA, pElevatorEncoderB, false, Encoder::EncodingType::k4X};

	// ---------- PID ----------

	PIDController m_heightPID{k_elevatorHeightP, k_elevatorHeightI, k_elevatorHeightD};

	// ---------- Limits ----------

	DigitalInput m_limitSwitchTop{pElevatorLimitTop};

	DigitalInput m_limitSwitchBottom{pElevatorLimitBottom};

	// ---------- Safety ----------

	double m_height;

	bool m_keepingStill = false;

	bool m_limitSafety = false;

	bool m_heightSafety = false;
};
