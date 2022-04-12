#pragma once

#include "Constants.h"
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

class MotorSubsystem : virtual public SubsystemBase
{

public:
	MotorSubsystem(MotorConfig, unsigned int);

	MotorSubsystem(MotorConfig, vector<unsigned int>);

	void Periodic() override;

	// ---------- Motor -----------

	/**
	 * @brief Sets the Motor speed
	 * @param speed Speed and direction to turn
	 */
	void SetMotor(double);

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

	void SetLimitPorts(unsigned int, unsigned int);

	void SetLimitSafety(bool);

	void PrimtLimits();

protected:
	CANSparkMax *m_motorSpark;

	VictorSPX *m_motorVictorCAN;

	VictorSP *m_motorVictorPWM;

	vector<CANSparkMax *> m_motorSparkList;

	vector<VictorSPX *> m_motorVictorCANList;

	vector<VictorSP *> m_motorVictorPWMList;

	MotorConfig m_motorConfig;

	double m_maxSpeed;

	DigitalInput *m_upperLimit;

	DigitalInput *m_lowerLimit;

	bool m_limitSafetyActive = false;

	bool m_motorCount = 0;
};
