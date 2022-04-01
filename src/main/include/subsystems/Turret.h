#pragma once
#include "Constants.h"
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

class Turret : public SubsystemBase
{
public:
	Turret();

	void Periodic() override;

	// ---------- Actions -----------

	void Reset();

	void Turn(double);

	void KeepStill();

	bool Center();

	// --------- Motor ---------

	void SetMotor(double);

	double GetMotor();

	void InvertMotor(bool);

	void PrintMotor();

	// --------- Encoder ---------

	double GetEncoder();

	void ResetEncoder();

	void InvertEncoder(bool);

	void PrintEncoder();

	// ---------- Angle ---------

	bool SetAngle(double);

	double GetAngle();

	void ResetAnglePID();

	void PrintAngle();

	void PrintAnglePIDError();

	// --------- Align ---------

	bool Align();

	void ResetAlignPID();

	void PrintAlignPIDError();

	// --------- Limits ----------

	bool GetRightLimit();

	bool GetLeftLimit();

	void PrintLimits();

	// --------- Safety ----------

	void SetLimitSafetyActive(bool);

	void SetAngleSafetyActive(bool);

private:
	// ---------- Motor ----------

	CANSparkMax m_motor{pTurretMotor, CANSparkMax::MotorType::kBrushed};

	// TODO : define motor type

	// VictorSP m_motor{pTurretMotor};

	// VictorSPX m_motor{pTurretMotor};

	// ---------- Sensors ---------

	Encoder m_encoder{pTurretEncoderA, pTurretEncoderB};

	// TODO : define encoder type

	// SparkMaxRelativeEncoder m_encoder{m_motor.GetEncoder()};

	Limelight m_limelight;

	DigitalInput m_limitSwitchRight{pTurretLimitSwitchRight};

	DigitalInput m_limitSwitchLeft{pTurretLimitLeft};

	// ---------- PID ---------

	PIDController m_alignPID{k_turretAlignP, k_turretAlignI, k_turretAlignD};

	PIDController m_anglePID{k_turretAngleP, k_turretAngleI, k_turretAngleD};

	// ---------- Attributes ----------

	double m_angle;

	bool m_keepingStill = false;

	bool m_limitSafety = false;

	bool m_angleSafety = false;
};
