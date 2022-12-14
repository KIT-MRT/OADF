/*************************************************************************
Trajectory and emergency path preprocessing (for IPG CarMaker 9.1)

Dependencies:
	External Libraries:
		GeographicLib (https://geographiclib.sourceforge.io/), Charles Karney (Version 1.50, MIT/X11)

File name:         tp_cm.cpp
Author:            Stefan Ackermann, stefan.ackermann@tu-darmstadt.de
Date:              22.01.2021
Version:           0.1 alpha
*************************************************************************/

/* Including the header files */
#include "tp_cm.h"

/*************************************************************************
This function reads the current TAI_Time
1. Read current GPS Time from IPG CarMaker GNavSensor Sensor
2. Shift GPS Time to TaiTime

INPUT PARAMETERS:
	taitime - Empty taitime struct fpr tai_seconds and tai_nanoseconds

OUTPUT PARAMETERS:
	taitime - taitime struct with cent tai_seconds and tai_nanoseconds

DEPENDENCIES:

AUTHOR:            Stefan Ackermann, stefan.ackermann@tu-darmstadt.de
DATE:              12.11.2020
*************************************************************************/
void tpinterface::read_taitime(taitime &taitime) {

	uint16_t gpsweek;
	double gpssow;

	/* Read GPS time */
	gpssow = GNavSensor.Receiver.Time_secsOfWeek;
	gpsweek = uint16_t(GNavSensor.Receiver.Time_GpsWeek);

	/* Convert GPS Time to TAI Time*/
	GPStoTAI(gpsweek, gpssow, taitime);

}