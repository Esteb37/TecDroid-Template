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
		EncoderConfig::Frc,
		M::CAN::SHOOTER,
		DIO::Encoder::SHOOTER_A,
		DIO::Encoder::SHOOTER_B);

	m_intake.Initialize(MotorConfig::Spark,
						M::CAN::INTAKE,
						TD::Solenoid::INTAKE_RIGHT_FORWARD,
						TD::Solenoid::INTAKE_RIGHT_REVERSE,
						TD::Solenoid::INTAKE_LEFT_FORWARD,
						TD::Solenoid::INTAKE_LEFT_REVERSE);

	m_feeder.Initialize(MotorConfig::VictorPWM, M::PWM::FEEDER);

	m_elevator.Initialize(MotorConfig::Spark,
						  EncoderConfig::Frc,
						  {M::CAN::ELEVATOR_LEFT, M::CAN::ELEVATOR_RIGHT},
						  DIO::Encoder::ELEVATOR_A,
						  DIO::Encoder::ELEVATOR_B);

	m_claw.Initialize(TD::Solenoid::CLAW_FORWARD,
					  TD::Solenoid::CLAW_REVERSE,
					  TD::Solenoid::WRIST_FORWARD,
					  TD::Solenoid::WRIST_REVERSE);

	m_turret.Initialize(MotorConfig::VictorPWM,
						EncoderConfig::Frc,
						M::PWM::TURRET,
						DIO::Encoder::TURRET_A,
						DIO::Encoder::TURRET_B);

	m_limelight.Initialize(LL::ANGLE_DEG, LL::HEIGHT);
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