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
constexpr unsigned int pShooter = 4;
constexpr unsigned int pIntake = 5;
constexpr unsigned int pConveyor = 6;
constexpr unsigned int pElevator = 7;
constexpr unsigned int pClimber = 8;

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

constexpr double k_wheelDiameter = 6 * 2.54;
constexpr double k_wheelGearRatio = 10.71;
constexpr double k_drivetrainDPR = k_wheelDiameter * M_PI / k_wheelGearRatio;

constexpr double k_ObjectiveHeight = 1.35;
constexpr double k_LimelightHeight = 0.35;
constexpr double k_LimelightAngle = 45 * M_PI / 180;
constexpr double k_LimelightToFront = 0.68;