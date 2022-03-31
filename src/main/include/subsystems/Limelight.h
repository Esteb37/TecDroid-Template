#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableValue.h"
#include "wpi/span.h"
#include <frc/smartdashboard/smartdashboard.h>
#include <frc2/command/SubsystemBase.h>

class Limelight : public frc2::SubsystemBase
{
private:
	std::shared_ptr<nt::NetworkTable> limelight;

	double horizontalAngle;
	double verticalAngle;
	double area;
	double skew;
	double pipeline;
	double valid;
	double target;
	double ltx;
	double lty;
	double lta;
	double lts;
	double ltp;
	double ltv;
	double distanceToTarget;

public:
	Limelight();

	/**
	 * Will be called periodically whenever the CommandScheduler runs.
	 */
	void Periodic() override;

	void Update();

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

	double GetDistanceToTarget();

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
