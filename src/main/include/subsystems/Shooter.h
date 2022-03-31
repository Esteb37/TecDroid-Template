#pragma once

#include "Constants.h"
#include <frc/DoubleSolenoid.h>
#include <frc/Servo.h>

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <subsystems/Limelight.h>

using namespace frc;
using namespace frc2;
using namespace rev;

template <typename MotorType, typename EncoderType>
class Shooter : public SubsystemBase
{

public:
	Shooter();

	void Periodic() override;

	void Reset();

	bool Shoot();

	// --------- Motor ---------

	void SetMotor(double);

	double GetMotor();

	void InvertMotor(bool);

	void ResetMotor();

	void PrintMotor();

	// --------- Encoder ---------

	virtual double GetEncoder();

	void ResetEncoder();

	virtual void InvertEncoder(bool);

	void PrintEncoder();

	// --------- PID ---------

	virtual bool ReachRPM(double);

	virtual double CalculateRPM();

	virtual void ResetPID();

	virtual void PrintPIDError();

	// --------- Angle with Servos --------

	void SetAngleServos(double);

	void SetServos(double);

	void ResetServos();

	double GetServos();

	double GetRightServo();

	double GetLeftServo();

	void PrintServos();

	void PrintRightServo();

	void PrintLeftServo();

	// --------- Angle with Solenoids ---------

	void SetAngleSolenoids(bool);

	void OpenSolenoids();

	void CloseSolenoids();

	void SolenoidsOff();

	bool GetRightSolenoid();

	bool GetLeftSolenoid();

	void PrintSolenoids();

private:
	// --------- Motor ---------

	MotorType m_motor;

	// -------- Angle actuators --------

	DoubleSolenoid m_rightSolenoid{PneumaticsModuleType::REVPH, pShooterRightSolenoidForward, pShooterRightSolenoidReverse};

	DoubleSolenoid m_rightSolenoid{PneumaticsModuleType::REVPH, pShooterLeftSolenoidForward, pShooterLeftSolenoidReverse};

	Servo m_rightServo{pShooterRightServo};

	Servo m_leftServo{pShooterLeftServo};

	// --------- Sensors -------------

	EncoderType m_encoder;

	Limelight limelight;

	int m_motorDirection = 1;

	int m_encoderDirection = 1;
};
