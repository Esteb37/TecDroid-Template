// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "Constants.h"
#include "subsystems/ClawBase.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/ElevatorBase.h"
#include "subsystems/FeederBase.h"
#include "subsystems/IntakeBase.h"
#include "subsystems/ShooterBase.h"
#include "subsystems/TurretBase.h"

#include <frc2/command/Command.h>

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */

using namespace TecDroid;

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

	ShooterBase m_shooter{MotorConfig::kSpark, EncoderConfig::kFrc, can_shooterMotor, dio_shooterEncoderA, dio_shooterEncoderB};

	IntakeBase m_intake{MotorConfig::kSpark, pwm_intakeMotor, sl_intakeRightForward, sl_intakeRightReverse, sl_intakeLeftForward, sl_intakeLeftReverse};

	FeederBase m_feeder{MotorConfig::kVictorPWM, pwm_feederMotor};

	ElevatorBase m_elevator{MotorConfig::kSpark, EncoderConfig::kFrc, {can_elevatorLeftMotor, can_elevatorRightMotor}, dio_elevatorEncoderA, dio_elevatorEncoderB};

	ClawBase m_claw{sl_clawForward, sl_clawReverse, sl_wristForward, sl_wristReverse};

	TurretBase m_turret{MotorConfig::kSpark, EncoderConfig::kFrc, pwm_turretMotor, dio_turretEncoderA, dio_turretEncoderB};
};
