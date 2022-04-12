// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "subsystems/Claw.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Elevator.h"
#include "subsystems/Feeder.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"
#include "subsystems/Turret.h"

#include <frc2/command/Command.h>

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer
{
public:
	RobotContainer();

	void RobotInit();

	void RobotPeriodic();

	void AutonomousInit();

	void AutonomousPeriodic();

	void TeleopInit();

	void TeleopPeriodic();

private:
	Drivetrain m_drivetrain{can_frontRight, can_frontLeft, can_backRight, can_backLeft};

	Shooter m_shooter{MotorConfig::kSpark, EncoderConfig::kFrc, can_shooterMotor, dio_shooterEncoderA, dio_shooterEncoderB};

	Intake m_intake{MotorConfig::kSpark, pwm_intakeMotor, sl_intakeRightForward, sl_intakeRightReverse, sl_intakeLeftForward, sl_intakeLeftReverse};

	Feeder m_feeder{MotorConfig::kVictorPWM, pwm_feederMotor};

	Elevator m_elevator{MotorConfig::kSpark, EncoderConfig::kFrc, {can_elevatorLeftMotor, can_elevatorRightMotor}, dio_elevatorEncoderA, dio_elevatorEncoderB};

	Claw m_claw{sl_clawForward, sl_clawReverse, sl_wristForward, sl_wristReverse};

	Turret m_turret{MotorConfig::kSpark, EncoderConfig::kFrc, pwm_turretMotor, dio_turretEncoderA, dio_turretEncoderB};
};
