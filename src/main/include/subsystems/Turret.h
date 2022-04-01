#pragma once
#include "Constants.h"
#include <frc/Encoder.h>
#include <frc/controller/PIDController.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <subsystems/Limelight.h>

using namespace frc;
using namespace frc2;
using namespace rev;

template <typename MotorType, typename EncoderType>
class Turret : public SubsystemBase
{
public:
	Turret();

	void Periodic() override;

	// ---------- Actions -----------

	bool Turn(double);

	bool KeepStill();

	void Reset();

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

	// --------- PID ---------

	bool SetAngle(double);

	bool Align();

	void ResetAlignPID();

	void ResetAnglePID();

	void PrintAlignPIDError();

	void PrintAnglePIDError();

private:
	// ---------- Motor ----------

	MotorType *m_motor;

	// ---------- Sensors ---------

	EncoderType *m_encoder;

	Limelight m_limelight;

	// ---------- PID ---------

	PIDController m_alignPID{k_turretAlignP, k_turretAlignI, k_turretAlignD};

	PIDController m_anglePID{k_turretAngleP, k_turretAngleI, k_turretAngleD};
};
