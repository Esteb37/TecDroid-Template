// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"
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

	Shooter<CANSparkMax, SparkMaxRelativeEncoder> m_shooter;

	Intake<VictorSP> m_intake;
};
