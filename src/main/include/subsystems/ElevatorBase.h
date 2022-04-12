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

class ElevatorBase : public EncoderSubsystem
{
public:
	ElevatorBase(MotorConfig, unsigned int);

	ElevatorBase(MotorConfig, vector<unsigned int>);

	ElevatorBase(MotorConfig, EncoderConfig, unsigned int);

	ElevatorBase(MotorConfig, EncoderConfig, vector<unsigned int>);

	ElevatorBase(MotorConfig, EncoderConfig, unsigned int, unsigned int, unsigned int);

	ElevatorBase(MotorConfig, EncoderConfig, vector<unsigned int>, unsigned int, unsigned int);

	void Periodic() override;

	// ---------- Actions -----------

	/**
	 * @brief Moves the elevator
	 * @param speed Speed and direction to move
	 */
	void Move(double);

	void SetHeightToFloor(double);

	double GetRelativeHeight();

	double GetAbsoluteHeight();

	bool SetRelativeHeight(double, bool);

	bool SetAbsoluteHeight(double, bool);

	void SetMinMaxHeight(double, double);

private:
	double m_heightToFloor;
};
