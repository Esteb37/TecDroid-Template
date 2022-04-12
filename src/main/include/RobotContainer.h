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
	Drivetrain m_drivetrain;

	Shooter m_shooter{MotorConfig::kSpark, EncoderConfig::kFrc, 0, 0, 1};

	Intake m_intake{MotorConfig::kSpark, 1, 0, 1, 2, 3};

	Feeder m_feeder{MotorConfig::kVictorPWM, 2};

	Elevator m_elevator{MotorConfig::kSpark, EncoderConfig::kFrc, 3, 2, 3};

	Claw m_claw{4, 5, 6, 7};
};
