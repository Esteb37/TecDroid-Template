#pragma once

#include "Constants.h"
#include "subsystems/MotorSubsystem.h"
#include <frc/Encoder.h>
#include <frc/controller/PIDController.h>
#include <frc/smartdashboard/SmartDashboard.h>

using namespace frc2;
using namespace frc;

class EncoderSubsystem : public MotorSubsystem
{
public:
	EncoderSubsystem(MotorConfig, EncoderConfig, unsigned int);

	EncoderSubsystem(MotorConfig, EncoderConfig, unsigned int, unsigned int, unsigned int);

	void Periodic() override;

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

	// ---------- Position PID -----------

	bool SetPosition(double);

	double GetPosition();

	void ResetPositionPID();

	void PrintPosition();

	void PrintPositionError();

	void SetMaxPosition()

		// ---------- Speed PID -----------

		bool SetSpeed(double);

	double GetSpeed();

	void ResetSpeedPID();

	void PrintSpeed();

	void PrintSpeedError();

private:
	SparkMaxRelativeEncoder *m_encoderSpark;

	Encoder *m_encoder;

	EncoderConfig m_config;

	PIDController m_positionPID;

	PIDController m_speedPID;

	double m_positionPIDSpeed;

	double m_speedPIDSpeed;

	double m_maxPosition;

	double m_minPosition;

	bool m_safetyActive = false;
};
