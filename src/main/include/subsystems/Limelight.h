#pragma once

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableValue.h"
#include "wpi/span.h"
#include <frc/smartdashboard/smartdashboard.h>

class Limelight
{
private:
	std::shared_ptr<nt::NetworkTable> limelight;

public:
	Limelight();

	// ---------- Actions ----------

	double GetDistanceToTarget();

	// ---------- Getters ----------

	double GetHorizontalAngle();

	double GetVerticalAngle();

	double GetArea();

	double GetSkew();

	double GetPipeline();

	double GetValid();

	double GetTarget();

	double GetLtx();

	double GetLty();

	double GetLta();

	double GetLts();

	double GetLtp();

	double GetLtv();

	// ---------- Setters ----------

	void SetPipeline(int);

	void SetLED(int);

	void SetCamMode(int);

	void SetStream(int);

	void SetSnapshot(int);

	void SetLight(int);

	void SetLEDMode(int);

	void SetLEDFrequency(int);

	void SetLEDIntensity(int);

	void SetLEDState(int);

	void SetLEDOff();

	void SetLEDOn();

	// ---------- Printers ----------

	void PrintHorizontalAngle();

	void PrintVerticalAngle();

	void PrintArea();

	void PrintSkew();

	void PrintPipeline();

	void PrintValid();

	void PrintTarget();

	void PrintLtx();

	void PrintLty();

	void PrintLta();

	void PrintLts();

	void PrintLtp();

	void PrintLtv();

	void PrintDistanceToTarget();
};
