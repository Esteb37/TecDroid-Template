// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

#include <Math.h>

constexpr unsigned int pFrontRight = 0;
constexpr unsigned int pFrontLeft = 1;
constexpr unsigned int pBackRight = 2;
constexpr unsigned int pBackLeft = 3;
constexpr unsigned int pShooterMotor = 4;
constexpr unsigned int pIntakeMotor = 5;
constexpr unsigned int pTurretMotor = 6;
constexpr unsigned int pFeederMotor = 6;
constexpr unsigned int pConveyor = 7;
constexpr unsigned int pElevatorMotor = 8;
constexpr unsigned int pClimber = 9;

constexpr unsigned int pShooterRightSolenoidForward = 0;
constexpr unsigned int pShooterRightSolenoidReverse = 1;
constexpr unsigned int pShooterLeftSolenoidForward = 2;
constexpr unsigned int pShooterLeftSolenoidReverse = 3;
constexpr unsigned int pIntakeRightSolenoidForward = 4;
constexpr unsigned int pIntakeRightSolenoidReverse = 5;
constexpr unsigned int pIntakeLeftSolenoidForward = 6;
constexpr unsigned int pIntakeLeftSolenoidReverse = 7;
constexpr unsigned int pClawHandSolenoidForward = 8;
constexpr unsigned int pClawHandSolenoidReverse = 9;
constexpr unsigned int pClawWristSolenoidForward = 10;
constexpr unsigned int pClawWristSolenoidReverse = 11;

constexpr unsigned int pShooterRightServo = 0;
constexpr unsigned int pShooterLeftServo = 1;

constexpr unsigned int pShooterEncoderA = 0;
constexpr unsigned int pShooterEncoderB = 1;
constexpr unsigned int pTurretEncoderA = 2;
constexpr unsigned int pTurretEncoderB = 3;
constexpr unsigned int pTurretLimitLeft = 4;
constexpr unsigned int pTurretLimitSwitchRight = 5;
constexpr unsigned int pElevatorEncoderA = 6;
constexpr unsigned int pElevatorEncoderB = 7;
constexpr unsigned int pElevatorLimitTop = 8;
constexpr unsigned int pElevatorLimitBottom = 9;

constexpr double k_moveP = 0.01;
constexpr double k_moveI = 0.0;
constexpr double k_moveD = 0.0;
constexpr double k_movePIDTolerance = 0.5;

constexpr double k_turnP = 0.01;
constexpr double k_turnI = 0.0;
constexpr double k_turnD = 0.0;
constexpr double k_turnPIDTolerance = 0.5;

constexpr double k_alignP = 0.01;
constexpr double k_alignI = 0.0;
constexpr double k_alignD = 0.0;
constexpr double k_alignPIDTolerance = 0.5;

constexpr double k_distanceP = 0.01;
constexpr double k_distanceI = 0.0;
constexpr double k_distanceD = 0.0;
constexpr double k_distancePIDTolerance = 0.5;

constexpr double k_shooterP = 0.01;
constexpr double k_shooterI = 0.0;
constexpr double k_shooterD = 0.0;
constexpr double k_shooterPIDTolerance = 0.5;

constexpr double k_turretAlignP = 0.01;
constexpr double k_turretAlignI = 0.0;
constexpr double k_turretAlignD = 0.0;
constexpr double k_turretAlignPIDTolerance = 0.5;

constexpr double k_turretAngleP = 0.01;
constexpr double k_turretAngleI = 0.0;
constexpr double k_turretAngleD = 0.0;
constexpr double k_turretAnglePIDTolerance = 0.5;

constexpr double k_elevatorHeightP = 0.01;
constexpr double k_elevatorHeightI = 0.0;
constexpr double k_elevatorHeightD = 0.0;
constexpr double k_elevatorHeightPIDTolerance = 0.5;

constexpr double k_wheelDiameter = 6 * 2.54;
constexpr double k_wheelGearRatio = 10.71;

constexpr double k_drivetrainDPR = k_wheelDiameter * M_PI / k_wheelGearRatio;
constexpr double k_turretDPR = 360.0; // TODO Define turret encoder to angle ratio
constexpr double k_shooterVCF = 180;  // TODO Define shooter conversion factor
constexpr double k_elevatorDPR = 180; // TODO Define elevator distance per revolution

constexpr double k_objectiveHeight = 1.35;
constexpr double k_limelightHeight = 0.35;
constexpr double k_limelightAngle = 45 * M_PI / 180;
constexpr double k_limelightToFront = 0.68;

constexpr double k_drivetrainMaxSpeed = 1;
constexpr double k_drivetrainMaxRotation = 1;
constexpr double k_shooterMaxSpeed = 1;
constexpr double k_intakeMaxSpeed = 1;
constexpr double k_turretMaxSpeed = 1;
constexpr double k_feederMaxSpeed = 1;
constexpr double k_elevatorMaxSpeed = 1;

constexpr double k_shooterLoadTime = 2;
constexpr double k_feederFeedTime = 5;

constexpr double k_turretMaxAngle = 90;
constexpr double k_turretMinAngle = -90;

constexpr double k_elevatorMaxHeight = 2.5;
constexpr double k_elevatorMinHeight = 0.3;

constexpr double shooterRPMFromDistance(double distance)
{
	return 60; // TODO: place RPM function here
}