#pragma once
#include "subsystems/Shooter.h"

// Create ShooterNEo class that inherits from Shooter
class ShooterNeo : public Shooter
{

public:
	ShooterNeo();

	void Periodic() override;

	void SetMotor(double speed) override;

	double GetMotor() override;

	void InvertMotor(bool inverted) override;

	void ResetMotor();

	double GetEncoder() override;

	void ResetEncoder() override;

	void InvertEncoder(bool inverted) override;

private:
	CANSparkMax m_motor{pShooterMotor, CANSparkMax::MotorType::kBrushless};

	SparkMaxRelativeEncoder m_encoder{m_motor.GetEncoder()};
};
