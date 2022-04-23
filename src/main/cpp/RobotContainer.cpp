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

	m_shooter.ConfigureServos(pwm_shooterRightServo, pwm_shooterLeftServo);
	m_shooter.m_limelight.ConfigureMount(72, 62);

	m_shooter.SetEncoderPorts(dio_shooterEncoderA, dio_shooterEncoderB);
	m_shooter.SetRPMConversionFactor(k_shooterVCF);
	m_shooter.ConfigureSolenoids(0, 1, 2, 3);
}

void RobotContainer::TeleopInit()
{
	m_shooter.Reset();
	m_shooter.ResetRPMPID();
	m_shooter.ResetServos();
}
void RobotContainer::TeleopPeriodic()
{
	m_shooter.SetMaxSpeed(GetNumber("Max Speed", k_shooterMaxSpeed));
	m_shooter.SetMotor(GetNumber("Speed", 1));
	m_shooter.InvertEncoder(GetBool("IE", false));
	m_shooter.InvertMotor(GetBool("IM", false));
	m_shooter.PrintRPM();
	m_shooter.SetAngleServos(GetNumber("Servos", 1));
	m_shooter.PrintServos();
	m_shooter.InvertSolenoids(GetNumber("IS", false));
	m_shooter.OpenSolenoids();
	m_shooter.PrintSolenoids();
	/*m_shooter.Shoot();
	m_shooter.ConfigureRPMPID(k_shooterP, k_shooterI, k_shooterD, k_shooterPIDTolerance, GetBool("IP", false));
	m_shooter.SetRPM(GetNumber("SetSpeed", 360), GetNumber("Speed", 1));
	m_shooter.PrintRPMError();
	SmartDashboard::PutNumber("RPM", m_shooter.CalculateRPM(250));*/
}