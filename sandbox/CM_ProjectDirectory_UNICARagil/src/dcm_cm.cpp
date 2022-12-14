/*************************************************************************
Driving Corridor Monitor (DCM) (for IPG CarMaker 9.1)

Dependencies:
	External Libraries:
		ALGLIB (www.alglib.net), Sergey Bochkanov (Version 3.16.0, GPL 2 or later)
		Eigen (eigen.tuxfamily.org), Benoît Jacob (founder) and Gaël Guennebaud (guru) (Version 3.4.0,  Mozilla Public License Version 2.0)

File name:         dcm_cm.cpp
Author:            Stefan Ackermann, stefan.ackermann@tu-darmstadt.de
Date:              21.10.2021
Version:           0.1
*************************************************************************/

/* Including the header files */
#include "dcm_cm.h"

double dcminterface::steady_diff_time_debug(int a) {

	double diff_tpath_count_s = -1;

	switch (a) {

	case 0: {

		uint16_t gpsweek;
		double gpssow;

		/* Read GPS time */
		gpssow = GNavSensor.Receiver.Time_secsOfWeek;
		gpsweek = uint16_t(GNavSensor.Receiver.Time_GpsWeek);

		/* Convert GPS Time to TAI Time*/
		GPStoTAI(gpsweek, gpssow, time_debug);

		break;
	}

	case 1: {

		taitime tpathnow;

		/* Read GPS time */
		double gpssow = GNavSensor.Receiver.Time_secsOfWeek;
		uint16_t gpsweek = uint16_t(GNavSensor.Receiver.Time_GpsWeek);

		/* Convert GPS Time to TAI Time*/
		GPStoTAI(gpsweek, gpssow, tpathnow);

		//Calculate difference in microseconds ans transform into seconds
		diff_tpath_count_s = ((double)tpathnow.tai_seconds + 1.0e-9*tpathnow.tai_nanoseconds) -
			((double)time_debug.tai_seconds + 1.0e-9*time_debug.tai_nanoseconds);

	}
	default:
		break;
	}

	return diff_tpath_count_s;

}

double dcminterface::steady_diff_time_xL_psinput(int a) {

    double diff_txL_ps_count_s = -1;

    switch (a) {

        case 0: {

            uint16_t gpsweek;
            double gpssow;

            /* Read GPS time */
            gpssow = GNavSensor.Receiver.Time_secsOfWeek;
            gpsweek = uint16_t(GNavSensor.Receiver.Time_GpsWeek);

            /* Convert GPS Time to TAI Time*/
            GPStoTAI(gpsweek, gpssow, txL_psinput);

            break;
        }

        case 1: {

            taitime tpathnow;

            /* Read GPS time */
            double gpssow = GNavSensor.Receiver.Time_secsOfWeek;
            uint16_t gpsweek = uint16_t(GNavSensor.Receiver.Time_GpsWeek);

            /* Convert GPS Time to TAI Time*/
            GPStoTAI(gpsweek, gpssow, tpathnow);

			//Calculate difference in microseconds ans transform into seconds
			diff_txL_ps_count_s = ((double)tpathnow.tai_seconds + 1.0e-9*tpathnow.tai_nanoseconds) -
				((double)txL_psinput.tai_seconds + 1.0e-9*txL_psinput.tai_nanoseconds);

        }
        default:
            break;
    }

    return diff_txL_ps_count_s;

}

double dcminterface::steady_diff_time_dcminput(int a) {

    double diff_tpath_count_s = -1;

    switch (a) {

        case 0: {

            uint16_t gpsweek;
            double gpssow;

            /* Read GPS time */
            gpssow = GNavSensor.Receiver.Time_secsOfWeek;
            gpsweek = uint16_t(GNavSensor.Receiver.Time_GpsWeek);

            /* Convert GPS Time to TAI Time*/
            GPStoTAI(gpsweek, gpssow, tdcmshpathinput);

            break;
        }

        case 1: {

            taitime tpathnow;

            /* Read GPS time */
            double gpssow = GNavSensor.Receiver.Time_secsOfWeek;
            uint16_t gpsweek = uint16_t(GNavSensor.Receiver.Time_GpsWeek);

            /* Convert GPS Time to TAI Time*/
            GPStoTAI(gpsweek, gpssow, tpathnow);

			//Calculate difference in microseconds ans transform into seconds
			diff_tpath_count_s = ((double)tpathnow.tai_seconds + 1.0e-9*tpathnow.tai_nanoseconds) -
				((double)tdcmshpathinput.tai_seconds + 1.0e-9*tdcmshpathinput.tai_nanoseconds);

        }
        default:
            break;
    }

    return diff_tpath_count_s;

}

double dcminterface::steady_diff_time(int a) {

    double diff_tpath_count_s = -1;

    switch (a) {

        case 0: {

            uint16_t gpsweek;
            double gpssow;

            /* Read GPS time */
            gpssow = GNavSensor.Receiver.Time_secsOfWeek;
            gpsweek = uint16_t(GNavSensor.Receiver.Time_GpsWeek);

            /* Convert GPS Time to TAI Time*/
            GPStoTAI(gpsweek, gpssow, tpathbegin);

            break;
        }

        case 1: {

            taitime tpathnow;

            /* Read GPS time */
            double gpssow = GNavSensor.Receiver.Time_secsOfWeek;
            uint16_t gpsweek = uint16_t(GNavSensor.Receiver.Time_GpsWeek);

            /* Convert GPS Time to TAI Time*/
            GPStoTAI(gpsweek, gpssow, tpathnow);

			//Calculate difference in microseconds ans transform into seconds
			diff_tpath_count_s = ((double)tpathnow.tai_seconds + 1.0e-9*tpathnow.tai_nanoseconds) -
				((double)tpathbegin.tai_seconds + 1.0e-9*tpathbegin.tai_nanoseconds);

        }
        default:
            break;
    }

    return diff_tpath_count_s;

}

void dcminterface::read_taitime(taitime &taitime) {

    uint16_t gpsweek;
    double gpssow;

    /* Read GPS time */
    gpssow = GNavSensor.Receiver.Time_secsOfWeek;
    gpsweek = uint16_t(GNavSensor.Receiver.Time_GpsWeek);

    /* Convert GPS Time to TAI Time*/
    GPStoTAI(gpsweek, gpssow, taitime);

}

//void dcminterface::read_delay_time_s(double &delay_time) {
//	//Todo: Festen Wert fr delay time durch Eingangswert aus "Verzugszeit"-Dienst ersetzen
//	delay_time = 0;
//
//}

void cm_getObjectList_Radar(OL_radar ext_OL_radar_R, uint16_t &input) {

	// Radar front
	if (input == 0) {

		int NofObjects = 0;
		int Object_ID = 0;

		std::vector<int> globObjID;

		for (int i = 0; i < RadarSensor[0].GlobalInf[0].nObj; i++) {

			ext_OL_radar_R.Object_ID.push_back(Object_ID);
			Object_ID += 1;

			ext_OL_radar_R.Object_DistLong.push_back(RadarSensor[0].ObjList[i].DistX - (RadarSensor[0].ObjList[i].Length / 2));
			ext_OL_radar_R.Object_DistLat.push_back(RadarSensor[0].ObjList[i].DistY);
			ext_OL_radar_R.Object_VrelLong.push_back(RadarSensor[0].ObjList[i].VrelX);
			ext_OL_radar_R.Object_VrelLat.push_back(RadarSensor[0].ObjList[i].VrelY);
			ext_OL_radar_R.Object_Length.push_back(RadarSensor[0].ObjList[i].Length);
			ext_OL_radar_R.Object_Width.push_back(RadarSensor[0].ObjList[i].Width);
			ext_OL_radar_R.Obj_DistLong_rms.push_back(0);
			ext_OL_radar_R.Obj_VrelLong_rms.push_back(0);
			ext_OL_radar_R.Obj_DistLat_rms.push_back(0);
			ext_OL_radar_R.Obj_VrelLat_rms.push_back(0);
			ext_OL_radar_R.Obj_ArelLat_rms.push_back(0);
			ext_OL_radar_R.Obj_ArelLong_rms.push_back(0);
			ext_OL_radar_R.Object_ArelLong.push_back(RadarSensor[0].ObjList[i].ArelX);
			ext_OL_radar_R.Object_ArelLat.push_back(0);
			ext_OL_radar_R.Object_OrientationAngel.push_back(0);
			ext_OL_radar_R.Object_RCS.push_back(RadarSensor[0].ObjList[i].RCS);

			if (RadarSensor[0].ObjList[i].DynProp == 0) {

				ext_OL_radar_R.Object_DynProp.push_back(4);

			} else if (RadarSensor[0].ObjList[i].DynProp == 1) {

				ext_OL_radar_R.Object_DynProp.push_back(1);

			}
			else if (RadarSensor[0].ObjList[i].DynProp == 2) {

				ext_OL_radar_R.Object_DynProp.push_back(7);

			}
			else if (RadarSensor[0].ObjList[i].DynProp == 3) {

				ext_OL_radar_R.Object_DynProp.push_back(0);

			}
			else if (RadarSensor[0].ObjList[i].DynProp == 4) {

				ext_OL_radar_R.Object_DynProp.push_back(2);

			}

			if (RadarSensor[0].ObjList[i].MeasStat == 0) {

				ext_OL_radar_R.Obj_MeasState.push_back(0);

			}
			else if (RadarSensor[0].ObjList[i].MeasStat == 1) {

					ext_OL_radar_R.Obj_MeasState.push_back(1);

			}
			else if (RadarSensor[0].ObjList[i].MeasStat == 3) {

				ext_OL_radar_R.Obj_MeasState.push_back(2);

			}

			if (RadarSensor[0].ObjList[i].ProbExist == 0) {

				ext_OL_radar_R.Obj_ProbOfExist.push_back(0);

			}
			else if (RadarSensor[0].ObjList[i].ProbExist == 1) {

				ext_OL_radar_R.Obj_ProbOfExist.push_back(1);

			}
			else if (RadarSensor[0].ObjList[i].ProbExist == 2) {

				ext_OL_radar_R.Obj_ProbOfExist.push_back(2);

			}
			else if (RadarSensor[0].ObjList[i].ProbExist == 3) {

				ext_OL_radar_R.Obj_ProbOfExist.push_back(3);

			}
			else if (RadarSensor[0].ObjList[i].ProbExist == 4) {

				ext_OL_radar_R.Obj_ProbOfExist.push_back(4);

			}
			else if (RadarSensor[0].ObjList[i].ProbExist == 5) {

				ext_OL_radar_R.Obj_ProbOfExist.push_back(5);

			}
			else if (RadarSensor[0].ObjList[i].ProbExist == 6) {

				ext_OL_radar_R.Obj_ProbOfExist.push_back(6);

			}
			else if (RadarSensor[0].ObjList[i].ProbExist == 7) {

				ext_OL_radar_R.Obj_ProbOfExist.push_back(7);

			}

			NofObjects += 1;

			globObjID.push_back(RadarSensor[0].ObjList[i].ObjId);

		}

		for (int i = 0; i < RadarSensor[1].GlobalInf[0].nObj; i++) {

					bool duplicate = false;

					for (int j = 0; j < globObjID.size(); j++) {

						if (globObjID.at(j) == RadarSensor[1].ObjList[i].ObjId) {

							duplicate = true;

						}

					}

					if (!duplicate) {

						ext_OL_radar_R.Object_ID.push_back(Object_ID);
						Object_ID += 1;

						ext_OL_radar_R.Object_DistLong.push_back(RadarSensor[1].ObjList[i].DistX - (RadarSensor[1].ObjList[i].Length / 2));
						ext_OL_radar_R.Object_DistLat.push_back(RadarSensor[1].ObjList[i].DistY);
						ext_OL_radar_R.Object_VrelLong.push_back(RadarSensor[1].ObjList[i].VrelX);
						ext_OL_radar_R.Object_VrelLat.push_back(RadarSensor[1].ObjList[i].VrelY);
						ext_OL_radar_R.Object_Length.push_back(RadarSensor[1].ObjList[i].Length);
						ext_OL_radar_R.Object_Width.push_back(RadarSensor[1].ObjList[i].Width);
						ext_OL_radar_R.Obj_DistLong_rms.push_back(0);
						ext_OL_radar_R.Obj_VrelLong_rms.push_back(0);
						ext_OL_radar_R.Obj_DistLat_rms.push_back(0);
						ext_OL_radar_R.Obj_VrelLat_rms.push_back(0);
						ext_OL_radar_R.Obj_ArelLat_rms.push_back(0);
						ext_OL_radar_R.Obj_ArelLong_rms.push_back(0);
						ext_OL_radar_R.Object_ArelLong.push_back(RadarSensor[1].ObjList[i].ArelX);
						ext_OL_radar_R.Object_ArelLat.push_back(0);
						ext_OL_radar_R.Object_OrientationAngel.push_back(0);
						ext_OL_radar_R.Object_RCS.push_back(RadarSensor[1].ObjList[i].RCS);

						if (RadarSensor[1].ObjList[i].DynProp == 0) {

							ext_OL_radar_R.Object_DynProp.push_back(4);

						}
						else if (RadarSensor[1].ObjList[i].DynProp == 1) {

							ext_OL_radar_R.Object_DynProp.push_back(1);

						}
						else if (RadarSensor[1].ObjList[i].DynProp == 2) {

							ext_OL_radar_R.Object_DynProp.push_back(7);

						}
						else if (RadarSensor[1].ObjList[i].DynProp == 3) {

							ext_OL_radar_R.Object_DynProp.push_back(0);

						}
						else if (RadarSensor[1].ObjList[i].DynProp == 4) {

							ext_OL_radar_R.Object_DynProp.push_back(2);

						}

						if (RadarSensor[1].ObjList[i].MeasStat == 0) {

							ext_OL_radar_R.Obj_MeasState.push_back(0);

						}
						else if (RadarSensor[1].ObjList[i].MeasStat == 1) {

							ext_OL_radar_R.Obj_MeasState.push_back(1);

						}
						else if (RadarSensor[1].ObjList[i].MeasStat == 3) {

							ext_OL_radar_R.Obj_MeasState.push_back(2);

						}

						if (RadarSensor[1].ObjList[i].ProbExist == 0) {

							ext_OL_radar_R.Obj_ProbOfExist.push_back(0);

						}
						else if (RadarSensor[1].ObjList[i].ProbExist == 1) {

							ext_OL_radar_R.Obj_ProbOfExist.push_back(1);

						}
						else if (RadarSensor[1].ObjList[i].ProbExist == 2) {

							ext_OL_radar_R.Obj_ProbOfExist.push_back(2);

						}
						else if (RadarSensor[1].ObjList[i].ProbExist == 3) {

							ext_OL_radar_R.Obj_ProbOfExist.push_back(3);

						}
						else if (RadarSensor[1].ObjList[i].ProbExist == 4) {

							ext_OL_radar_R.Obj_ProbOfExist.push_back(4);

						}
						else if (RadarSensor[1].ObjList[i].ProbExist == 5) {

							ext_OL_radar_R.Obj_ProbOfExist.push_back(5);

						}
						else if (RadarSensor[1].ObjList[i].ProbExist == 6) {

							ext_OL_radar_R.Obj_ProbOfExist.push_back(6);

						}
						else if (RadarSensor[1].ObjList[i].ProbExist == 7) {

							ext_OL_radar_R.Obj_ProbOfExist.push_back(7);

						}

						NofObjects += 1;

					}

		}

		ext_OL_radar_R.Object_NofObjects = NofObjects;
		taitime taitime;
		dcminterface::read_taitime(taitime);
		ext_OL_radar_R.send_tai_seconds = taitime.tai_seconds;
		ext_OL_radar_R.send_tai_nanoseconds = taitime.tai_nanoseconds;

		dcminterface::tx_OL_ps_R(ext_OL_radar_R, input);

	}
	else {

		int NofObjects = 0;
		int Object_ID = 0;

		std::vector<int> globObjID;

		for (int i = 0; i < RadarSensor[2].GlobalInf[0].nObj; i++) {

			ext_OL_radar_R.Object_ID.push_back(Object_ID);
			Object_ID += 1;

			ext_OL_radar_R.Object_DistLong.push_back(RadarSensor[2].ObjList[i].DistX - (RadarSensor[2].ObjList[i].Length / 2));
			ext_OL_radar_R.Object_DistLat.push_back(RadarSensor[2].ObjList[i].DistY);
			ext_OL_radar_R.Object_VrelLong.push_back(RadarSensor[2].ObjList[i].VrelX);
			ext_OL_radar_R.Object_VrelLat.push_back(RadarSensor[2].ObjList[i].VrelY);
			ext_OL_radar_R.Object_Length.push_back(RadarSensor[2].ObjList[i].Length);
			ext_OL_radar_R.Object_Width.push_back(RadarSensor[2].ObjList[i].Width);
			ext_OL_radar_R.Obj_DistLong_rms.push_back(0);
			ext_OL_radar_R.Obj_VrelLong_rms.push_back(0);
			ext_OL_radar_R.Obj_DistLat_rms.push_back(0);
			ext_OL_radar_R.Obj_VrelLat_rms.push_back(0);
			ext_OL_radar_R.Obj_ArelLat_rms.push_back(0);
			ext_OL_radar_R.Obj_ArelLong_rms.push_back(0);
			ext_OL_radar_R.Object_ArelLong.push_back(RadarSensor[2].ObjList[i].ArelX);
			ext_OL_radar_R.Object_ArelLat.push_back(0);
			ext_OL_radar_R.Object_OrientationAngel.push_back(0);
			ext_OL_radar_R.Object_RCS.push_back(RadarSensor[2].ObjList[i].RCS);

			if (RadarSensor[2].ObjList[i].DynProp == 0) {

				ext_OL_radar_R.Object_DynProp.push_back(4);

			}
			else if (RadarSensor[2].ObjList[i].DynProp == 1) {

				ext_OL_radar_R.Object_DynProp.push_back(1);

			}
			else if (RadarSensor[2].ObjList[i].DynProp == 2) {

				ext_OL_radar_R.Object_DynProp.push_back(7);

			}
			else if (RadarSensor[2].ObjList[i].DynProp == 3) {

				ext_OL_radar_R.Object_DynProp.push_back(0);

			}
			else if (RadarSensor[2].ObjList[i].DynProp == 4) {

				ext_OL_radar_R.Object_DynProp.push_back(2);

			}

			if (RadarSensor[2].ObjList[i].MeasStat == 0) {

				ext_OL_radar_R.Obj_MeasState.push_back(0);

			}
			else if (RadarSensor[2].ObjList[i].MeasStat == 1) {

				ext_OL_radar_R.Obj_MeasState.push_back(1);

			}
			else if (RadarSensor[2].ObjList[i].MeasStat == 3) {

				ext_OL_radar_R.Obj_MeasState.push_back(2);

			}

			if (RadarSensor[2].ObjList[i].ProbExist == 0) {

				ext_OL_radar_R.Obj_ProbOfExist.push_back(0);

			}
			else if (RadarSensor[2].ObjList[i].ProbExist == 1) {

				ext_OL_radar_R.Obj_ProbOfExist.push_back(1);

			}
			else if (RadarSensor[2].ObjList[i].ProbExist == 2) {

				ext_OL_radar_R.Obj_ProbOfExist.push_back(2);

			}
			else if (RadarSensor[2].ObjList[i].ProbExist == 3) {

				ext_OL_radar_R.Obj_ProbOfExist.push_back(3);

			}
			else if (RadarSensor[2].ObjList[i].ProbExist == 4) {

				ext_OL_radar_R.Obj_ProbOfExist.push_back(4);

			}
			else if (RadarSensor[2].ObjList[i].ProbExist == 5) {

				ext_OL_radar_R.Obj_ProbOfExist.push_back(5);

			}
			else if (RadarSensor[2].ObjList[i].ProbExist == 6) {

				ext_OL_radar_R.Obj_ProbOfExist.push_back(6);

			}
			else if (RadarSensor[2].ObjList[i].ProbExist == 7) {

				ext_OL_radar_R.Obj_ProbOfExist.push_back(7);

			}

			NofObjects += 1;

			globObjID.push_back(RadarSensor[2].ObjList[i].ObjId);

		}

		for (int i = 0; i < RadarSensor[3].GlobalInf[0].nObj; i++) {

			bool duplicate = false;

			for (int j = 0; j < globObjID.size(); j++) {

				if (globObjID.at(j) == RadarSensor[3].ObjList[i].ObjId) {

					duplicate = true;

				}

			}

			if (!duplicate) {

				ext_OL_radar_R.Object_ID.push_back(Object_ID);
				Object_ID += 1;

				ext_OL_radar_R.Object_DistLong.push_back(RadarSensor[3].ObjList[i].DistX - (RadarSensor[3].ObjList[i].Length / 2));
				ext_OL_radar_R.Object_DistLat.push_back(RadarSensor[3].ObjList[i].DistY);
				ext_OL_radar_R.Object_VrelLong.push_back(RadarSensor[3].ObjList[i].VrelX);
				ext_OL_radar_R.Object_VrelLat.push_back(RadarSensor[3].ObjList[i].VrelY);
				ext_OL_radar_R.Object_Length.push_back(RadarSensor[3].ObjList[i].Length);
				ext_OL_radar_R.Object_Width.push_back(RadarSensor[3].ObjList[i].Width);
				ext_OL_radar_R.Obj_DistLong_rms.push_back(0);
				ext_OL_radar_R.Obj_VrelLong_rms.push_back(0);
				ext_OL_radar_R.Obj_DistLat_rms.push_back(0);
				ext_OL_radar_R.Obj_VrelLat_rms.push_back(0);
				ext_OL_radar_R.Obj_ArelLat_rms.push_back(0);
				ext_OL_radar_R.Obj_ArelLong_rms.push_back(0);
				ext_OL_radar_R.Object_ArelLong.push_back(RadarSensor[3].ObjList[i].ArelX);
				ext_OL_radar_R.Object_ArelLat.push_back(0);
				ext_OL_radar_R.Object_OrientationAngel.push_back(0);
				ext_OL_radar_R.Object_RCS.push_back(RadarSensor[3].ObjList[i].RCS);

				if (RadarSensor[3].ObjList[i].DynProp == 0) {

					ext_OL_radar_R.Object_DynProp.push_back(4);

				}
				else if (RadarSensor[3].ObjList[i].DynProp == 1) {

					ext_OL_radar_R.Object_DynProp.push_back(1);

				}
				else if (RadarSensor[3].ObjList[i].DynProp == 2) {

					ext_OL_radar_R.Object_DynProp.push_back(7);

				}
				else if (RadarSensor[3].ObjList[i].DynProp == 3) {

					ext_OL_radar_R.Object_DynProp.push_back(0);

				}
				else if (RadarSensor[3].ObjList[i].DynProp == 4) {

					ext_OL_radar_R.Object_DynProp.push_back(2);

				}

				if (RadarSensor[3].ObjList[i].MeasStat == 0) {

					ext_OL_radar_R.Obj_MeasState.push_back(0);

				}
				else if (RadarSensor[3].ObjList[i].MeasStat == 1) {

					ext_OL_radar_R.Obj_MeasState.push_back(1);

				}
				else if (RadarSensor[3].ObjList[i].MeasStat == 3) {

					ext_OL_radar_R.Obj_MeasState.push_back(2);

				}

				if (RadarSensor[3].ObjList[i].ProbExist == 0) {

					ext_OL_radar_R.Obj_ProbOfExist.push_back(0);

				}
				else if (RadarSensor[3].ObjList[i].ProbExist == 1) {

					ext_OL_radar_R.Obj_ProbOfExist.push_back(1);

				}
				else if (RadarSensor[3].ObjList[i].ProbExist == 2) {

					ext_OL_radar_R.Obj_ProbOfExist.push_back(2);

				}
				else if (RadarSensor[3].ObjList[i].ProbExist == 3) {

					ext_OL_radar_R.Obj_ProbOfExist.push_back(3);

				}
				else if (RadarSensor[3].ObjList[i].ProbExist == 4) {

					ext_OL_radar_R.Obj_ProbOfExist.push_back(4);

				}
				else if (RadarSensor[3].ObjList[i].ProbExist == 5) {

					ext_OL_radar_R.Obj_ProbOfExist.push_back(5);

				}
				else if (RadarSensor[3].ObjList[i].ProbExist == 6) {

					ext_OL_radar_R.Obj_ProbOfExist.push_back(6);

				}
				else if (RadarSensor[3].ObjList[i].ProbExist == 7) {

					ext_OL_radar_R.Obj_ProbOfExist.push_back(7);

				}

				NofObjects += 1;

			}

		}

		ext_OL_radar_R.Object_NofObjects = NofObjects;
		taitime taitime;
		dcminterface::read_taitime(taitime);
		ext_OL_radar_R.send_tai_seconds = taitime.tai_seconds;
		ext_OL_radar_R.send_tai_nanoseconds = taitime.tai_nanoseconds;

		dcminterface::tx_OL_ps_R(ext_OL_radar_R, input);

	}

}

void cm_getObjectList_Radar_ObjectSensor(OL_radar ext_OL_radar_R, uint16_t &input){

    // Radar front
    if (input == 0){

		/* For object sensors */
        tObjectSensorObj *tgt_RFSR;
        tObjectSensorObj *tgt_RFLR;

        int NofObjects = 0;
        int Object_ID = 0;

        std::vector<int> globObjID;

        for (int i = 0; i < Traffic.nObjs; i++){

            tgt_RFSR = ObjectSensor_GetObject(28, i);

            if (tgt_RFSR != NULL){

                if (tgt_RFSR->dtct && tgt_RFSR->obsv){

                    ext_OL_radar_R.Object_ID.push_back(Object_ID);
                    Object_ID += 1;

                    ext_OL_radar_R.Object_DistLong.push_back(tgt_RFSR->NearPnt.ds[0]);
                    ext_OL_radar_R.Object_DistLat.push_back(tgt_RFSR->NearPnt.ds[1]);
                    ext_OL_radar_R.Object_VrelLong.push_back(tgt_RFSR->NearPnt.dv[0]);
                    ext_OL_radar_R.Object_VrelLat.push_back(tgt_RFSR->NearPnt.dv[1]);
                    ext_OL_radar_R.Object_Length.push_back(tgt_RFSR->l);
                    ext_OL_radar_R.Object_Width.push_back(tgt_RFSR->w);
					ext_OL_radar_R.Obj_DistLong_rms.push_back(0);
					ext_OL_radar_R.Obj_VrelLong_rms.push_back(0);
					ext_OL_radar_R.Obj_DistLat_rms.push_back(0);
					ext_OL_radar_R.Obj_VrelLat_rms.push_back(0);
					ext_OL_radar_R.Obj_ArelLat_rms.push_back(0);
					ext_OL_radar_R.Obj_ArelLong_rms.push_back(0);
					ext_OL_radar_R.Object_ArelLong.push_back(0);
					ext_OL_radar_R.Object_ArelLat.push_back(0);
					ext_OL_radar_R.Object_OrientationAngel.push_back(0);
					ext_OL_radar_R.Object_DynProp.push_back(1);

                    NofObjects += 1;

                    globObjID.push_back(tgt_RFSR->ObjId);

                }

            }

        }

        for (int i = 0; i < Traffic.nObjs; i++){

            tgt_RFLR = ObjectSensor_GetObject(29, i);

            if (tgt_RFLR != NULL){

                if (tgt_RFLR->dtct && tgt_RFLR->obsv){

                    bool duplicate = false;

                    for (int j=0; j < globObjID.size(); j++){

                        if (globObjID.at(j) == tgt_RFLR->ObjId){

                            duplicate = true;

                        }

                    }

                    if (!duplicate) {

                        ext_OL_radar_R.Object_ID.push_back(Object_ID);
                        Object_ID += 1;

                        ext_OL_radar_R.Object_DistLong.push_back(tgt_RFLR->NearPnt.ds[0]);
                        ext_OL_radar_R.Object_DistLat.push_back(tgt_RFLR->NearPnt.ds[1]);
                        ext_OL_radar_R.Object_VrelLong.push_back(tgt_RFLR->NearPnt.dv[0]);
                        ext_OL_radar_R.Object_VrelLat.push_back(tgt_RFLR->NearPnt.dv[1]);
                        ext_OL_radar_R.Object_Length.push_back(tgt_RFLR->l);
                        ext_OL_radar_R.Object_Width.push_back(tgt_RFLR->h);
						ext_OL_radar_R.Obj_DistLong_rms.push_back(0);
						ext_OL_radar_R.Obj_VrelLong_rms.push_back(0);
						ext_OL_radar_R.Obj_DistLat_rms.push_back(0);
						ext_OL_radar_R.Obj_VrelLat_rms.push_back(0);
						ext_OL_radar_R.Obj_ArelLat_rms.push_back(0);
						ext_OL_radar_R.Obj_ArelLong_rms.push_back(0);
						ext_OL_radar_R.Object_ArelLong.push_back(0);
						ext_OL_radar_R.Object_ArelLat.push_back(0);
						ext_OL_radar_R.Object_OrientationAngel.push_back(0);
						ext_OL_radar_R.Object_DynProp.push_back(1);

                        NofObjects += 1;
                    }

                }

            }

        }

        ext_OL_radar_R.Object_NofObjects = NofObjects;
        taitime taitime;
        dcminterface::read_taitime(taitime);
        ext_OL_radar_R.send_tai_seconds = taitime.tai_seconds;
        ext_OL_radar_R.send_tai_nanoseconds = taitime.tai_nanoseconds;

        dcminterface::tx_OL_ps_R(ext_OL_radar_R, input);

    }else{

        tObjectSensorObj *tgt_RBSR;
        tObjectSensorObj *tgt_RBLR;

        int NofObjects = 0;
        int Object_ID = 0;

        std::vector<int> globObjID;

        for (int i = 0; i < Traffic.nObjs; i++){

            tgt_RBSR = ObjectSensor_GetObject(30, i);

            if (tgt_RBSR != NULL){

                if (tgt_RBSR->dtct && tgt_RBSR->obsv){

                    ext_OL_radar_R.Object_ID.push_back(Object_ID);
                    Object_ID += 1;

                    ext_OL_radar_R.Object_DistLong.push_back(tgt_RBSR->NearPnt.ds[0]);
                    ext_OL_radar_R.Object_DistLat.push_back(tgt_RBSR->NearPnt.ds[1]);
                    ext_OL_radar_R.Object_VrelLong.push_back(tgt_RBSR->NearPnt.dv[0]);
                    ext_OL_radar_R.Object_VrelLat.push_back(tgt_RBSR->NearPnt.dv[1]);
                    ext_OL_radar_R.Object_Length.push_back(tgt_RBSR->l);
                    ext_OL_radar_R.Object_Width.push_back(tgt_RBSR->h);
					ext_OL_radar_R.Obj_DistLong_rms.push_back(0);
					ext_OL_radar_R.Obj_VrelLong_rms.push_back(0);
					ext_OL_radar_R.Obj_DistLat_rms.push_back(0);
					ext_OL_radar_R.Obj_VrelLat_rms.push_back(0);
					ext_OL_radar_R.Obj_ArelLat_rms.push_back(0);
					ext_OL_radar_R.Obj_ArelLong_rms.push_back(0);
					ext_OL_radar_R.Object_ArelLong.push_back(0);
					ext_OL_radar_R.Object_ArelLat.push_back(0);
					ext_OL_radar_R.Object_OrientationAngel.push_back(0);
					ext_OL_radar_R.Object_DynProp.push_back(1);

                    NofObjects += 1;

                    globObjID.push_back(tgt_RBSR->ObjId);

                }

            }

        }

        for (int i = 0; i < Traffic.nObjs; i++){

            tgt_RBLR = ObjectSensor_GetObject(31, i);

            if (tgt_RBLR != NULL){

                if (tgt_RBLR->dtct && tgt_RBLR->obsv){

                    bool duplicate = false;

                    for (int j=0; j < globObjID.size(); j++){

                        if (globObjID.at(j) == tgt_RBLR->ObjId){

                            duplicate = true;

                        }

                    }

                    if (!duplicate) {

                        ext_OL_radar_R.Object_ID.push_back(Object_ID);
                        Object_ID += 1;

                        ext_OL_radar_R.Object_DistLong.push_back(tgt_RBLR->NearPnt.ds[0]);
                        ext_OL_radar_R.Object_DistLat.push_back(tgt_RBLR->NearPnt.ds[1]);
                        ext_OL_radar_R.Object_VrelLong.push_back(tgt_RBLR->NearPnt.dv[0]);
                        ext_OL_radar_R.Object_VrelLat.push_back(tgt_RBLR->NearPnt.dv[1]);
                        ext_OL_radar_R.Object_Length.push_back(tgt_RBLR->l);
                        ext_OL_radar_R.Object_Width.push_back(tgt_RBLR->h);
						ext_OL_radar_R.Obj_DistLong_rms.push_back(0);
						ext_OL_radar_R.Obj_VrelLong_rms.push_back(0);
						ext_OL_radar_R.Obj_DistLat_rms.push_back(0);
						ext_OL_radar_R.Obj_VrelLat_rms.push_back(0);
						ext_OL_radar_R.Obj_ArelLat_rms.push_back(0);
						ext_OL_radar_R.Obj_ArelLong_rms.push_back(0);
						ext_OL_radar_R.Object_ArelLong.push_back(0);
						ext_OL_radar_R.Object_ArelLat.push_back(0);
						ext_OL_radar_R.Object_OrientationAngel.push_back(0);
						ext_OL_radar_R.Object_DynProp.push_back(1);

                        NofObjects += 1;
                    }

                }

            }

        }

        ext_OL_radar_R.Object_NofObjects = NofObjects;
        taitime taitime;
        dcminterface::read_taitime(taitime);
        ext_OL_radar_R.send_tai_seconds = taitime.tai_seconds;
        ext_OL_radar_R.send_tai_nanoseconds = taitime.tai_nanoseconds;

        dcminterface::tx_OL_ps_R(ext_OL_radar_R, input);

    }

}

std::vector<int> ussc_transform_feature(std::vector<int> sensor, double x, double y){
    Eigen::Matrix3d R;
    R << std::cos(sensor.at(3) * (M_PI/180)), std::sin(sensor.at(3) * (M_PI/180)), 0, -std::sin(sensor.at(3) * (M_PI/180)), std::cos(sensor.at(3) * (M_PI/180)), 0, 0, 0, 1;
    Eigen::Vector3d T;
    T << sensor.at(0), sensor.at(1), 0;
    Eigen::Matrix4d Trans;
    Trans.setIdentity();
    Trans.block<3,3>(0,0) = R.transpose();
    Trans.block<3,1>(0,3) = T;

    Eigen::Vector4d old_pos;
    Eigen::Vector4d new_pos;
    old_pos << x, y, 0, 1;

    new_pos = Trans * old_pos;

    std::vector<int> returnvalue;
    returnvalue = {(int)new_pos(0), (int)new_pos(1) , 0};

    return returnvalue;
}

void cm_getObjectList_USS(FL_uss ext_FL_uss_ECU){

    tObjectSensorObj *tgt_ussc;

    std::vector<int> globObjID;

    for (int i = 0; i < dcmcmparam::ussc.size(); i++) {

        for (int j = 0; j < Traffic.nObjs; j++){

            tgt_ussc = ObjectSensor_GetObject(i, j);

            if (tgt_ussc != NULL){

                if (tgt_ussc->dtct && tgt_ussc->obsv){

                    bool duplicate = false;

                    for (int j=0; j < globObjID.size(); j++){

                        if (globObjID.at(j) == tgt_ussc->ObjId){

                            duplicate = true;

                        }

                    }

                    if (!duplicate) {

                        std::vector<int> feature_new = ussc_transform_feature(dcmcmparam::ussc.at(i),
                                                                              tgt_ussc->NearPnt.ds[0] * 1000,
                                                                              tgt_ussc->NearPnt.ds[1] * 1000);

                        ext_FL_uss_ECU.ULS_Feature_Ax_PT_X_mm.push_back(feature_new.at(0));
                        ext_FL_uss_ECU.ULS_Feature_Ax_PT_Y_mm.push_back(feature_new.at(1));
						ext_FL_uss_ECU.velocity_abs_x_mm_s.push_back(0);
						ext_FL_uss_ECU.velocity_abs_y_mm_s.push_back(0);
						ext_FL_uss_ECU.ULS_Feature_Bx_Orthogonal_Uncert.push_back(0);
						ext_FL_uss_ECU.ULS_Feature_Ax_Lateral_Uncert.push_back(0);
						ext_FL_uss_ECU.ULS_Feature_Bx_Type.push_back(1);
						ext_FL_uss_ECU.ULS_Feature_Bx_HiHeight_Percent.push_back(50);
						ext_FL_uss_ECU.ULS_Feature_Bx_LoHeight_Percent.push_back(50);
						ext_FL_uss_ECU.ULS_Feature_Bx_Line_PT.push_back(0);
						ext_FL_uss_ECU.ULS_Feature_Bx_Trend.push_back(0);

                        globObjID.push_back(tgt_ussc->ObjId);

                    }

                }

            }

        }

    }

    taitime taitime;
    dcminterface::read_taitime(taitime);
    ext_FL_uss_ECU.send_tai_seconds = taitime.tai_seconds;
    ext_FL_uss_ECU.send_tai_nanoseconds = taitime.tai_nanoseconds;

    dcminterface::tx_FL_ps_ECU(ext_FL_uss_ECU);

}

#if defined(TUDa_SH_PLOT)

void cm_plot_dcm_shpath(dcm_shpathplot &ext_dcm_shpathplot) {

	matplotlibcpp::figure(1);
	matplotlibcpp::clf();

	if(ext_dcm_shpathplot.ns_Object_DistENU_east.size() > 0){

		matplotlibcpp::plot(ext_dcm_shpathplot.ns_Object_DistENU_east, ext_dcm_shpathplot.ns_Object_DistENU_north, "xb");

	}

	if (ext_dcm_shpathplot.path_buffered_east.size() > 0) {

		for (int i = 0; i < ext_dcm_shpathplot.path_buffered_east.size(); i++) {

			matplotlibcpp::plot(ext_dcm_shpathplot.path_buffered_east.at(i), ext_dcm_shpathplot.path_buffered_north.at(i), "-c");

		}

	}

	if (ext_dcm_shpathplot.s_obj_buffered_east.size() > 0) {

		for (int i = 0; i < ext_dcm_shpathplot.s_obj_buffered_east.size(); i++) {

			matplotlibcpp::plot(ext_dcm_shpathplot.s_obj_buffered_east.at(i), ext_dcm_shpathplot.s_obj_buffered_north.at(i), "-g");

		}

	}

	if (ext_dcm_shpathplot.target_east.size() > 0) {

		matplotlibcpp::plot(ext_dcm_shpathplot.target_east, ext_dcm_shpathplot.target_north, "or");

	}

	if (ext_dcm_shpathplot.shpath_east.size() > 0) {

		matplotlibcpp::plot(ext_dcm_shpathplot.shpath_east, ext_dcm_shpathplot.shpath_north, "y");

	}

	if (ext_dcm_shpathplot.ego_buffered_east.size() > 0) {

		for (int i = 0; i < ext_dcm_shpathplot.ego_buffered_east.size(); i++) {

			matplotlibcpp::plot(ext_dcm_shpathplot.ego_buffered_east.at(i), ext_dcm_shpathplot.ego_buffered_north.at(i), "-k");

		}

	}

	if (ext_dcm_shpathplot.intersection_east.size() > 0) {

		for (int i = 0; i < ext_dcm_shpathplot.intersection_east.size(); i++) {

			if (ext_dcm_shpathplot.intersection_east.at(i).size() > 0) {

				for (int j = 0; j < ext_dcm_shpathplot.intersection_east.at(i).size(); j++) {

					matplotlibcpp::plot(ext_dcm_shpathplot.intersection_east.at(i).at(j), ext_dcm_shpathplot.intersection_north.at(i).at(j), "*-m");

				}

			}

		}

	}

	matplotlibcpp::ion();
	matplotlibcpp::axis("equal");
	matplotlibcpp::show();
	matplotlibcpp::pause(0.001);

}

#endif
