#pragma once

#include "Constants.h"
#include "subsystems/MotorSubsystem.h"
#include <frc/Encoder.h>
#include <frc/controller/PIDController.h>
#include <frc/smartdashboard/SmartDashboard.h>

using namespace frc2;
using namespace frc;

class EncoderSubsystem : virtual public MotorSubsystem
{
public:
	EncoderSubsystem(MotorConfig, EncoderConfig, unsigned int);

	EncoderSubsystem(MotorConfig, EncoderConfig, unsigned int, unsigned int, unsigned int);

	void Periodic() override;

	void SetMotor(double);

	void Reset();

	/**
	 * @brief Sets the encoder's value to 0
	 */
	void ResetEncoder();

	/**
	 * @brief Inverts the encoder's direction
	 * @param invert True to invert, false to not
	 */
	void InvertEncoder(bool);

	void SetEncoderPorts(unsigned int, unsigned int);

	// ---------- Position PID -----------

	bool SetPosition(double, bool);

	double GetPosition();

	void ConfigurePositionPID(double, double, double, double);

	void SetPositionConversionFactor(double);

	void ResetPositionPID();

	void PrintPosition();

	void PrintPositionError();

	void SetPositionSafety(bool);

	// ---------- Speed PID -----------

	bool SetSpeed(double, bool);

	double GetSpeed();

	void ConfigureSpeedPID(double, double, double, double);

	void SetSpeedConversionFactor(double);

	void ResetSpeedPID();

	void PrintSpeed();

	void PrintSpeedError();

protected:
	SparkMaxRelativeEncoder *m_encoderSpark;

	Encoder *m_encoder;

	EncoderConfig m_encoderConfig;

	PIDController *m_positionPID;

	PIDController *m_speedPID;

	double m_positionPIDSpeed;

	double m_speedPIDSpeed;

	double m_maxPosition;

	double m_minPosition;

	double m_maxRPM;

	double m_speedCF;

	bool m_keepingStill;

	bool m_speedSafetyActive = false;

	bool m_positionSafetyActive = false;
};
