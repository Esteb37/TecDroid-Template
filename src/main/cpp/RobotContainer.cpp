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
	m_drivetrain.Configure(can_frontRight, can_frontLeft, can_backRight, can_backLeft);

	m_shooter.Configure(MotorConfig::kSpark, EncoderConfig::kFrc, can_shooterMotor, dio_shooterEncoderA, dio_shooterEncoderB);

	m_intake.Configure(MotorConfig::kSpark, can_intakeMotor, sl_intakeRightForward, sl_intakeRightReverse, sl_intakeLeftForward, sl_intakeLeftReverse);

	m_feeder.Configure(MotorConfig::kVictorPWM, pwm_feederMotor);

	m_elevator.Configure(MotorConfig::kSpark, EncoderConfig::kFrc, {can_elevatorLeftMotor, can_elevatorRightMotor}, dio_elevatorEncoderA, dio_elevatorEncoderB);

	m_claw.Configure(sl_clawForward, sl_clawReverse, sl_wristForward, sl_wristReverse);

	m_turret.Configure(MotorConfig::kVictorPWM, EncoderConfig::kFrc, pwm_turretMotor, dio_turretEncoderA, dio_turretEncoderB);
}

void RobotContainer::ConfigureSubsystems()
{
}

void RobotContainer::TeleopInit()
{
}
void RobotContainer::TeleopPeriodic()
{
}