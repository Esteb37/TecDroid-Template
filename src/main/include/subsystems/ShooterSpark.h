#pragma once
#include "subsystems/Shooter.h"

class ShooterSpark : public Shooter
{

public:
	ShooterSpark();

	void Periodic() override;

	void SetMotor(double speed) override;

	double GetMotor() override;

	void InvertMotor(bool inverted) override;

	double GetEncoder() override;

	void ResetEncoder() override;

	void InvertEncoder(bool inverted) override;

private:
	CANSparkMax m_motor{pShooterMotor, CANSparkMax::MotorType::kBrushed};

	Encoder m_encoder{pShooterEncoderA, pShooterEncoderB, false, Encoder::EncodingType::k4X};
};
