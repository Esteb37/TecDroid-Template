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

	void Reset();

	void Move(double);

	void KeepStill();

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

	// ---------- Height ---------

	bool SetHeight(double);

	double GetHeight();

	void ResetHeightPID();

	void PrintHeight();

	void PrintHeightPIDError();

	// ---------- Limits ---------

	bool GetTopLimit();

	bool GetBottomLimit();

	void PrintLimits();

	// --------- Safety ----------

	void SetLimitSafetyActive(bool);

	void SetHeightSafetyActive(bool);

private:
	// ---------- Motor ----------

	CANSparkMax m_motor{pElevatorMotor, rev::CANSparkMax::MotorType::kBrushed};

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
