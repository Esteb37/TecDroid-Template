#include "Constants.h"
#include <rev/CANSparkMax.h>
#include <rev/SparkMaxRelativeEncoder.h>
#include <subsystems/Shooter.h>

using namespace frc;
using namespace rev;

class ShooterNeo : public Shooter<CANSparkMax, SparkMaxRelativeEncoder>
{

public:
	ShooterNeo();

	double GetEncoder() override;

	void InvertEncoder(bool) override;

	bool ReachRPM(double) override;

	double CalculateRPM() override;

	void ResetPID() override;

	void PrintPIDError() override;

private:
	CANSparkMax m_motor{pShooterMotor, CANSparkMaxLowLevel::MotorType::kBrushless};

	SparkMaxRelativeEncoder m_encoder{m_motor.GetEncoder()};
};