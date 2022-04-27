// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

double GetNumber(string name, double alt)
{
	return SmartDashboard::GetNumber(name, alt);
}

double GetBool(string name, double alt)
{
	return SmartDashboard::GetBoolean(name, alt);
}

RobotContainer::RobotContainer()
{
	InitializeSubsystems();
	ConfigureSubsystems();
}

void RobotContainer::InitializeSubsystems()
{
	m_drivetrain.Initialize(can_frontRight, can_frontLeft, can_backRight, can_backLeft);

	m_shooter.Initialize(MotorConfig::kSpark, EncoderConfig::kFrc, can_shooterMotor, dio_shooterEncoderA, dio_shooterEncoderB);

	m_intake.Initialize(MotorConfig::kSpark, can_intakeMotor, sl_intakeRightForward, sl_intakeRightReverse, sl_intakeLeftForward, sl_intakeLeftReverse);

	m_feeder.Initialize(MotorConfig::kVictorPWM, pwm_feederMotor);

	m_elevator.Initialize(MotorConfig::kSpark, EncoderConfig::kFrc, {can_elevatorLeftMotor, can_elevatorRightMotor}, dio_elevatorEncoderA, dio_elevatorEncoderB);

	m_claw.Initialize(sl_clawForward, sl_clawReverse, sl_wristForward, sl_wristReverse);

	m_turret.Initialize(MotorConfig::kVictorPWM, EncoderConfig::kFrc, pwm_turretMotor, dio_turretEncoderA, dio_turretEncoderB);

	m_limelight.Initialize(k_limelightAngle, k_limelightHeight);
}

void RobotContainer::ConfigureSubsystems()
{
	m_drivetrain.InvertMove(true);
	m_drivetrain.InvertRotation(true);
}

void RobotContainer::TeleopInit()
{
}
void RobotContainer::TeleopPeriodic()
{
}

frc2::Command *RobotContainer::GetAutonomousCommand()
{
	auto [command, trajectory] = m_drivetrain.OpenPath("path.json");

	// Reset odometry to the starting pose of the trajectory.
	m_drivetrain.ConfigurePosition(trajectory.InitialPose());

	// no auto
	return new SequentialCommandGroup(
		move(command),
		InstantCommand([this]
					   { m_drivetrain.TankDriveVolts(0_V, 0_V); },
					   {}));
}