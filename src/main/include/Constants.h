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
#define _USE_MATH_DEFINES
#include <math.h>

using port = unsigned int;

// MOTORS
namespace M
{
	namespace CAN
	{
		port FRONT_RIGHT = 0;
		port FRONT_LEFT = 1;
		port BACK_RIGHT = 2;
		port BACK_LEFT = 3;
		port SHOOTER = 4;
		port ELEVATOR_RIGHT = 5;
		port ELEVATOR_LEFT = 6;
		port INTAKE = 7;
	};

	namespace PWM
	{
		port FEEDER = 0;
		port TURRET = 1;
	};

	namespace Servo
	{
		port SHOOTER_RIGHT = 2;
		port SHOOTER_LEFT = 3;
	};
}

namespace Solenoid
{
	port CLAW_FORWARD = 0;
	port CLAW_REVERSE = 1;
	port WRIST_FORWARD = 2;
	port WRIST_REVERSE = 3;
	port INTAKE_RIGHT_FORWARD = 4;
	port INTAKE_RIGHT_REVERSE = 5;
	port INTAKE_LEFT_FORWARD = 6;
	port INTAKE_LEFT_REVERSE = 7;
}

namespace DIO
{
	namespace Encoder
	{
		port SHOOTER_A = 0;
		port SHOOTER_B = 1;
		port TURRET_A = 2;
		port TURRET_B = 3;
		port ELEVATOR_A = 6;
		port ELEVATOR_B = 7;
	};

	namespace Limit
	{
		port TURRET_LEFT = 4;
		port TURRET_RIGHT = 5;
		port ELEVATOR_TOP = 8;
		port ELEVATOR_BOTTOM = 9;
	};
}

namespace PID
{
	namespace Move
	{
		double P = 0.01;
		double I = 0.0;
		double D = 0.0;
		double TOLERANCE = 0.5;
	}

	namespace Turn
	{
		double P = 0.01;
		double I = 0.0;
		double D = 0.0;
		double TOLERANCE = 0.5;
	}

	namespace Align
	{
		double P = 0.01;
		double I = 0.0;
		double D = 0.0;
		double TOLERANCE = 0.5;
	}

	namespace Distance
	{
		double P = 0.01;
		double I = 0.0;
		double D = 0.0;
		double TOLERANCE = 0.5;
	}

	namespace Shooter
	{
		double P = 0.01;
		double I = 0.0;
		double D = 0.0;
		double TOLERANCE = 0.5;
	}

	namespace TurretAlign
	{
		double P = 0.01;
		double I = 0.0;
		double D = 0.0;
		double TOLERANCE = 0.5;
	}

	namespace TurretAngle
	{
		double P = 0.01;
		double I = 0.0;
		double D = 0.0;
		double TOLERANCE = 0.5;
	}

	namespace Elevator
	{
		double P = 0.01;
		double I = 0.0;
		double D = 0.0;
		double TOLERANCE = 0.5;
	}
}

namespace LL
{
	double OBJECTIVE_HEIGHT = 135;
	double HEIGHT = 35;
	double ANGLE_DEG = 45;
	double ANGLE_RAD = ANGLE_DEG * M_PI / 180;
	double TO_FRONT = 68;
}

namespace Wheel
{
	double DIAMETER_IN = 6;
	double DIAMETER = DIAMETER_IN * 2.54;
	double CIRCUMFERENCE = DIAMETER * M_PI;
	double RADIUS = DIAMETER / 2;
	double GEAR_RATIO = 10.71;
}

namespace DPR
{
	double DRIVETRAIN = Wheel::CIRCUMFERENCE / Wheel::GEAR_RATIO;
	double TURRET = 360;   // TODO Define turret encoder to angle ratio
	double ELEVATOR = 180; // TODO Define elevator distance per revolution
	double SHOOTER = 180;  // TODO Define shooter conversion factor
}

namespace Speed
{
	double DRIVETRAIN_MOVE = 1;
	double DRIVETRAIN_TURN = 1;
	double SHOOTER = 1;
	double TURRET = 1;
	double FEEDER = 1;
	double ELEVATOR = 1;
}

namespace Time
{
	double SHOOTER_LOAD = 2;
	double FEEDER = 5;
}

namespace Minmax
{
	double TURRET_MIN = 0;
	double TURRET_MAX = 360;
	double ELEVATOR_MIN = 250;
	double ELEVATOR_MAX = 30;
};

double shooterRPMFromDistance(double distance)
{
	return 60; // TODO: place RPM function here
}
