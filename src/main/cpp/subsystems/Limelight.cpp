#include <frc/smartdashboard/SmartDashboard.h>
#include <subsystems/Limelight.h>

using namespace frc;

Limelight::Limelight()
{
	limelight = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
}

void Limelight::Periodic()
{
	Update();
}

void Limelight::Update()
{
	horizontalAngle = limelight->GetEntry("tx").GetDouble(0);
	verticalAngle = limelight->GetEntry("ty").GetDouble(0);
	area = limelight->GetEntry("ta").GetDouble(0);
	skew = limelight->GetEntry("ts").GetDouble(0);
	pipeline = limelight->GetEntry("getpipe").GetDouble(0);
	valid = limelight->GetEntry("tv").GetDouble(0);
	target = limelight->GetEntry("tv").GetDouble(0);
	ltx = limelight->GetEntry("ltx").GetDouble(0);
	lty = limelight->GetEntry("lty").GetDouble(0);
	lta = limelight->GetEntry("lta").GetDouble(0);
	lts = limelight->GetEntry("lts").GetDouble(0);
	ltp = limelight->GetEntry("ltp").GetDouble(0);
	ltv = limelight->GetEntry("ltv").GetDouble(0);
	distanceToTarget = limelight->GetEntry("getdistance").GetDouble(0);
}

double Limelight::GetHorizontalAngle()
{
	return horizontalAngle;
}

double Limelight::GetVerticalAngle()
{
	return verticalAngle;
}

double Limelight::GetArea()
{
	return area;
}

double Limelight::GetSkew()
{
	return skew;
}

double Limelight::GetPipeline()
{
	return pipeline;
}

double Limelight::GetValid()
{
	return valid;
}

double Limelight::GetTarget()
{
	return target;
}

double Limelight::GetLtx()
{
	return ltx;
}

double Limelight::GetLty()
{
	return lty;
}

double Limelight::GetLta()
{
	return lta;
}

double Limelight::GetLts()
{
	return lts;
}

double Limelight::GetLtp()
{
	return ltp;
}

double Limelight::GetLtv()
{
	return ltv;
}

double Limelight::GetDistanceToTarget()
{
	return distanceToTarget;
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
	SmartDashboard::PutNumber("Limelight Horizontal Angle", horizontalAngle);
}

void Limelight::PrintVerticalAngle()
{
	SmartDashboard::PutNumber("Limelight Vertical Angle", verticalAngle);
}

void Limelight::PrintArea()
{
	SmartDashboard::PutNumber("Limelight Area", area);
}

void Limelight::PrintSkew()
{
	SmartDashboard::PutNumber("Limelight Skew", skew);
}

void Limelight::PrintPipeline()
{
	SmartDashboard::PutNumber("Limelight Pipeline", pipeline);
}

void Limelight::PrintValid()
{
	SmartDashboard::PutNumber("Limelight Valid", valid);
}

void Limelight::PrintTarget()
{
	SmartDashboard::PutNumber("Limelight Target", target);
}

void Limelight::PrintLtx()
{
	SmartDashboard::PutNumber("Limelight Ltx", ltx);
}

void Limelight::PrintLty()
{
	SmartDashboard::PutNumber("Limelight Lty", lty);
}

void Limelight::PrintLta()
{
	SmartDashboard::PutNumber("Limelight Lta", lta);
}

void Limelight::PrintLts()
{
	SmartDashboard::PutNumber("Limelight Lts", lts);
}

void Limelight::PrintLtp()
{
	SmartDashboard::PutNumber("Limelight Ltp", ltp);
}

void Limelight::PrintLtv()
{
	SmartDashboard::PutNumber("Limelight Ltv", ltv);
}

void Limelight::PrintDistanceToTarget()
{
	SmartDashboard::PutNumber("Limelight Distance to Target", distanceToTarget);
}
