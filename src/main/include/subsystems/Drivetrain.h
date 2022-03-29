#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>


#include "Constants.h"

using namespace frc2;
using namespace rev;

class Drivetrain : public frc2::SubsystemBase
{
public:
	Drivetrain();

	/**
	 * Will be called periodically whenever the CommandScheduler runs.
	 */
	void Periodic() override;

	// Read right encoders
	double GetRightEncoders();

	// Read left encoders
	double GetLeftEncoders();
	
	// Function for getting encoder average
	double GetEncoderAverage();

	// drive x y
	void Drive(double, double);

	// Drive no parameters
	void Drive();

	// Read gyro in degrees
	double GetGyro();

	// Read gyro in radians
	double GetGyroRad();

	// reset all 
	void Reset();

	// reset gyro
	void ResetGyro();

	// Reset encoders
	void ResetEncoders();


	/**
	 * Will be called periodically whenever the CommandScheduler runs during
	 * simulation.
	 */
	void SimulationPeriodic() override;

private:
	// Components (e.g. motor controllers and sensors) should generally be
	// declared private and exposed only through public methods.

	// Add CANSparkMax object on port pFrontLeft
	CANSparkMax m_frontLeft{pFrontLeft, CANSparkMaxLowLevel::MotorType::kBrushless};
	// Add CANSparkMax object on port pFrontRight
	CANSparkMax m_frontRight{pFrontRight, CANSparkMaxLowLevel::MotorType::kBrushless};

	// Add CANSparkMax object on port pBackLeft
	CANSparkMax m_backLeft{pBackLeft, CANSparkMaxLowLevel::MotorType::kBrushless};

	// Add CANSparkMax object on port pBackRight
	CANSparkMax m_backRight{pBackRight,CANSparkMaxLowLevel::MotorType::kBrushless};

 // right motor group
	SpeedControllerGroup m_right{m_frontRight, m_backRight};

	//Left motor group
	SpeedControllerGroup m_left{m_frontLeft, m_backLeft};

	// Create drivetrain named chasis with motor group
	DifferentialDrive m_chasis{m_left, m_right};

	// Create xbox controller
	XboxController m_controller{0};

	// Create SparkMaxRelativeEncoder right with right.getencoder
	SparkMaxRelativeEncoder m_frontRightEncoder{m_frontRight.GetEncoder()};

	// Create SparkMaxRelativeEncoder left with left.getencoder
	SparkMaxRelativeEncoder m_frontLeftEncoder{m_frontLeft.GetEncoder()};

	// Create SparkMaxRelativeEncoder right with right.getencoder
	SparkMaxRelativeEncoder m_backRightEncoder{m_backRight.GetEncoder()};

	// Create SparkMaxRelativeEncoder left with left.getencoder
	SparkMaxRelativeEncoder m_backLeftEncoder{m_backLeft.GetEncoder()};

	// Add adis gyro
	ADIS16448_IMU m_gyro;

	






	


};






	



	







	









	
	

};
