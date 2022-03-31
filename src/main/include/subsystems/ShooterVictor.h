#pragma once
#include "subsystems/Shooter.h"

class ShooterVictor : public Shooter
{

public:
	ShooterVictor();

	void Periodic() override;

	void SetMotor(double speed) override;

	double GetMotor() override;

	void InvertMotor(bool inverted) override;

	double GetEncoder() override;

	void ResetEncoder() override;

	void InvertEncoder(bool inverted) override;

private:
	VictorSP m_motor{pShooterMotor};

	Encoder m_encoder{pShooterEncoderA, pShooterEncoderB, false, Encoder::EncodingType::k4X};
};
