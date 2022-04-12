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

class Elevator : public EncoderSubsystem
{
public:
	Elevator(MotorConfig, unsigned int);

	Elevator(MotorConfig, vector<unsigned int>);

	Elevator(MotorConfig, EncoderConfig, unsigned int);

	Elevator(MotorConfig, EncoderConfig, vector<unsigned int>);

	Elevator(MotorConfig, EncoderConfig, unsigned int, unsigned int, unsigned int);

	Elevator(MotorConfig, EncoderConfig, vector<unsigned int>, unsigned int, unsigned int);

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

private:
	double m_heightToFloor;
};
