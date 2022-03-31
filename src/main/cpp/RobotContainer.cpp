// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer()
{
	// Initialize all of your commands and subsystems here
}

void RobotContainer::TeleopPeriodic()
{

	m_neoShooter.SetMotor(0);
	m_sparkShooter.SetMotor(0);
	m_victorShooter.SetMotor(0);

	m_neoShooter.GetMotor();
	m_sparkShooter.GetMotor();
	m_victorShooter.GetMotor();

	m_neoShooter.GetEncoder();
	m_sparkShooter.GetEncoder();
	m_victorShooter.GetEncoder();

	m_neoShooter.ResetEncoder();
	m_sparkShooter.ResetEncoder();
	m_victorShooter.ResetEncoder();

	m_neoShooter.InvertEncoder(false);
	m_sparkShooter.InvertEncoder(false);
	m_victorShooter.InvertEncoder(false);

	m_neoShooter.ResetMotor();
}