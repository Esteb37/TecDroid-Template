#pragma once

#include "Constants.h"
#include <any>
#include <frc/DoubleSolenoid.h>
#include <frc/Encoder.h>
#include <frc/Servo.h>
#include <frc/controller/PIDController.h>
#include <frc/motorcontrol/VictorSP.h>
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

	// ---------- Actions -----------

	void Reset();

	bool Shoot();

	// --------- Motor ---------

	virtual void SetMotor(double);

	virtual double GetMotor();

	virtual void InvertMotor(bool);

	void PrintMotor();

	// --------- Encoder ---------

	virtual double GetEncoder();

	virtual void ResetEncoder();

	virtual void InvertEncoder(bool);

	void PrintEncoder();

	// --------- PID ---------

	virtual bool ReachRPM(double);

	virtual double CalculateRPM();

	virtual void ResetPID();

	virtual void PrintPIDError();

	// --------- Angle with Servos --------

	void SetAngleServos(double);

	void ResetServos();

	double GetRightServo();

	double GetLeftServo();

	void PrintServos();

	// --------- Angle with Solenoids ---------

	void SetAngleSolenoids(bool);

	void InvertSolenoids();

	void SolenoidsOff();

	bool GetRightSolenoid();

	bool GetLeftSolenoid();

	void PrintSolenoids();

private:
	// --------- Motor ---------

	MotorType *m_motor;

	// --------- Encoder ---------

	EncoderType *m_encoder;

	PIDController m_PIDController{k_shooterP, k_shooterI, k_shooterD};

	// -------- Angle actuators --------

	DoubleSolenoid m_rightSolenoid{PneumaticsModuleType::REVPH, pShooterRightSolenoidForward, pShooterRightSolenoidReverse};

	DoubleSolenoid m_leftSolenoid{PneumaticsModuleType::REVPH, pShooterLeftSolenoidForward, pShooterLeftSolenoidReverse};

	Servo m_rightServo{pShooterRightServo};

	Servo m_leftServo{pShooterLeftServo};

	// --------- Sensors -------------

	Limelight m_limelight;

	// --------- Attributes -----------

	bool m_solenoidsInverted = false;
};
