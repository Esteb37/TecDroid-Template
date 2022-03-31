#include "Constants.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <subsystems/Limelight.h>

using namespace frc;

Limelight::Limelight()
{
	limelight = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
}

double Limelight::GetArea()
{
	return limelight->GetEntry("ta").GetDouble(0);
}

double Limelight::GetHorizontalAngle()
{
	return limelight->GetEntry("tx").GetDouble(0);
}

double Limelight::GetVerticalAngle()
{
	return limelight->GetEntry("ty").GetDouble(0);
}

double Limelight::GetSkew()
{
	return limelight->GetEntry("ts").GetDouble(0);
}

double Limelight::GetPipeline()
{
	return limelight->GetEntry("getpipe").GetDouble(0);
}

double Limelight::GetValid()
{
	return limelight->GetEntry("tv").GetDouble(0);
}

double Limelight::GetTarget()
{
	return limelight->GetEntry("target").GetDouble(0);
}

double Limelight::GetLtx()
{
	return limelight->GetEntry("ltx").GetDouble(0);
}

double Limelight::GetLty()
{
	return limelight->GetEntry("lty").GetDouble(0);
}

double Limelight::GetLta()
{
	return limelight->GetEntry("lta").GetDouble(0);
}

double Limelight::GetLts()
{
	return limelight->GetEntry("lts").GetDouble(0);
}

double Limelight::GetLtp()
{
	return limelight->GetEntry("ltp").GetDouble(0);
}

double Limelight::GetLtv()
{
	return limelight->GetEntry("ltv").GetDouble(0);
}

double Limelight::GetDistanceToTarget()
{
	return (k_objectiveHeight - k_limelightHeight) / tan(k_limelightAngle + GetVerticalAngle());
}

void Limelight::SetPipeline(int pipeline)
{
	limelight->GetEntry("pipeline").SetDouble(pipeline);
}

void Limelight::SetLED(int led)
{
	limelight->GetEntry("ledMode").SetDouble(led);
}

void Limelight::SetCamMode(int mode)
{
	limelight->GetEntry("camMode").SetDouble(mode);
}

void Limelight::SetStream(int stream)
{
	limelight->GetEntry("stream").SetDouble(stream);
}

void Limelight::SetSnapshot(int snapshot)
{
	limelight->GetEntry("snapshot").SetDouble(snapshot);
}

void Limelight::SetLight(int light)
{
	limelight->GetEntry("light").SetDouble(light);
}

void Limelight::SetLEDMode(int mode)
{
	limelight->GetEntry("ledMode").SetDouble(mode);
}

void Limelight::SetLEDFrequency(int freq)
{
	limelight->GetEntry("ledFrequency").SetDouble(freq);
}

void Limelight::SetLEDIntensity(int intensity)
{
	limelight->GetEntry("ledIntensity").SetDouble(intensity);
}

void Limelight::SetLEDState(int state)
{
	limelight->GetEntry("ledState").SetDouble(state);
}

void Limelight::SetLEDOff()
{
	limelight->GetEntry("ledMode").SetDouble(0);
}

void Limelight::SetLEDOn()
{
	limelight->GetEntry("ledMode").SetDouble(1);
}

void Limelight::PrintHorizontalAngle()
{
	SmartDashboard::PutNumber("Horizontal Angle", GetHorizontalAngle());
}

void Limelight::PrintVerticalAngle()
{
	SmartDashboard::PutNumber("Vertical Angle", GetVerticalAngle());
}

void Limelight::PrintArea()
{
	SmartDashboard::PutNumber("Area", GetArea());
}

void Limelight::PrintSkew()
{
	SmartDashboard::PutNumber("Skew", GetSkew());
}

void Limelight::PrintPipeline()
{
	SmartDashboard::PutNumber("Pipeline", GetPipeline());
}

void Limelight::PrintValid()
{
	SmartDashboard::PutNumber("Valid", GetValid());
}

void Limelight::PrintTarget()
{
	SmartDashboard::PutNumber("Target", GetTarget());
}

void Limelight::PrintLtx()
{
	SmartDashboard::PutNumber("Ltx", GetLtx());
}

void Limelight::PrintLty()
{
	SmartDashboard::PutNumber("Lty", GetLty());
}

void Limelight::PrintLta()
{
	SmartDashboard::PutNumber("Lta", GetLta());
}

void Limelight::PrintLts()
{
	SmartDashboard::PutNumber("Lts", GetLts());
}

void Limelight::PrintLtp()
{
	SmartDashboard::PutNumber("Ltp", GetLtp());
}

void Limelight::PrintLtv()
{
	SmartDashboard::PutNumber("Ltv", GetLtv());
}

void Limelight::PrintDistanceToTarget()
{
	SmartDashboard::PutNumber("Distance to Target", GetDistanceToTarget());
}