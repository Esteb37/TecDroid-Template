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
	m_drivetrain.Initialize(
		M::CAN::FRONT_RIGHT,
		M::CAN::FRONT_LEFT,
		M::CAN::BACK_RIGHT,
		M::CAN::BACK_LEFT);

	m_shooter.Initialize(
		MotorConfig::Spark,
		EncoderConfig::kFrc,
		M::CAN::SHOOTER,
		DIO::ENCODER::SHOOTER_A,
		DIO::ENCODER::SHOOTER_B);

	m_intake.Initialize(MotorConfig::Spark,
						M::CAN::INTAKE,
						SOL::INTAKE_RIGHT_FORWARD,
						SOL::INTAKE_RIGHT_REVERSE,
						SOL::INTAKE_LEFT_FORWARD,
						SOL::INTAKE_LEFT_REVERSE);

	m_feeder.Initialize(MotorConfig::VictorPWM, M::PWM::FEEDER);

	m_elevator.Initialize(MotorConfig::Spark,
						  EncoderConfig::kFrc,
						  {M::CAN::ELEVATOR_LEFT, M::CAN::ELEVATOR_RIGHT},
						  DIO::ENCODER::ELEVATOR_A,
						  DIO::ENCODER::ELEVATOR_B);

	m_claw.Initialize(SOL::CLAW_FORWARD,
					  SOL::CLAW_REVERSE,
					  SOL::WRIST_FORWARD,
					  SOL::WRIST_REVERSE);

	m_turret.Initialize(MotorConfig::VictorPWM,
						EncoderConfig::kFrc,
						M::PWM::TURRET,
						DIO::ENCODER::TURRET_A,
						DIO::ENCODER::TURRET_B);

	m_limelight.Initialize(LIMELIGHT::ANGLE_DEG, LIMELIGHT::HEIGHT);
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