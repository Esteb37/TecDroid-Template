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

	m_drivetrain.ResetMotors();
	m_drivetrain.ResetSensors();
	m_drivetrain.SetSafetyEnabled(true);
	m_drivetrain.SetPositionConversionFactor(k_drivetrainDPR);
	m_drivetrain.m_limelight.ConfigureMount(35, 72);
	m_shooter.SetMaxSpeed(k_shooterMaxSpeed);
	m_shooter.ConfigureServos(pwm_shooterRightServo, pwm_shooterLeftServo);
	m_shooter.SetSpeedConversionFactor(k_shooterVCF);
	m_shooter.ConfigureSpeedPID(k_shooterP, k_shooterI, k_shooterD, k_shooterPIDTolerance);
	m_shooter.InvertEncoder(false);
	m_shooter.InvertMotor(false);

	m_intake.SetMaxSpeed(k_intakeMaxSpeed);
	m_intake.InvertMotor(false);

	m_feeder.SetMaxSpeed(k_feederMaxSpeed);
	m_feeder.InvertMotor(false);

	m_elevator.SetMaxSpeed(k_elevatorMaxSpeed);
	m_elevator.ConfigureLimitSwitches(dio_elevatorLimitTop, dio_elevatorLimitBottom);
	m_elevator.SetPositionConversionFactor(k_elevatorDPR);
	m_elevator.ConfigurePositionPID(k_elevatorHeightP, k_elevatorHeightI, k_elevatorHeightD, k_elevatorHeightPIDTolerance);
	m_elevator.SetHeightToFloor(30);
	m_elevator.SetMinMaxHeight(0, 130);
	m_elevator.SetLimitSafety(true);
	m_elevator.SetPositionSafety(true);
	m_elevator.InvertEncoder(false);
	m_elevator.InvertMotors({false, false});

	m_claw.InvertHand(false);
	m_claw.InvertWrist(false);

	m_turret.SetMaxSpeed(k_turretMaxSpeed);
	m_turret.ConfigureLimitSwitches(dio_turretLimitRight, dio_turretLimitLeft);
	m_turret.SetPositionConversionFactor(k_turretDPR);
	m_turret.ConfigurePositionPID(k_turretAngleP, k_turretAngleI, k_turretAngleD, k_turretAnglePIDTolerance);
	m_turret.ConfigureAlignPID(k_turretAlignP, k_turretAlignI, k_turretAlignD, k_turretAlignPIDTolerance);
	m_turret.SetFreedom(360);
	m_turret.SetLimitSafety(true);
	m_turret.SetPositionSafety(true);
	m_turret.InvertEncoder(false);
	m_turret.InvertMotor(false);
}

void RobotContainer::TeleopInit()
{
}
void RobotContainer::TeleopPeriodic()
{

	m_drivetrain.PrintGyro();
	m_drivetrain.PrintMotors();
	m_drivetrain.ConfigureAlignPID(k_alignP, k_alignI, k_alignD, k_alignPIDTolerance, GetBool("Invert", false));
	m_drivetrain.ConfigureDistancePID(k_distanceP, k_distanceI, k_distanceD, k_distancePIDTolerance, GetBool("Invert", false));
	m_drivetrain.ConfigureTurnPID(k_turnP, k_turnI, k_turnD, k_turnPIDTolerance, GetBool("Invert", false));
	m_drivetrain.ConfigureMovePID(k_moveP, k_moveI, k_moveD, k_movePIDTolerance, GetBool("Invert", false));
	/*m_drivetrain.Move(GetNumber();
	m_drivetrain.PrintMoveError();*/

	/*m_drivetrain.Turn(("Distance", 100), GetNumber("Speed", -1));
	m_drivetrain.PrintTurnError();
	m_drivetrain.MoveTo(GetNumber("X", 100), GetNumber("Y", 100), 1, 1);
	m_drivetrain.PrintMoveToError();
	m_drivetrain.PrintCurrentPosition();*/
	// m_drivetrain.SetAngleWithTarget(10, 1);
	/*m_drivetrain.AlignWithTarget(1);
	m_drivetrain.PrintAlignError();*/
	m_drivetrain.SetDistanceWithTarget(250, 100, 1);
	m_drivetrain.PrintSetDistanceError();
}