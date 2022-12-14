#ifdef TP_DEBUG
#include <iostream> //std::cout
#endif

// Include CarMaker specific stuff
#include "CarMaker.h"
#include "Vehicle/Sensor_GNav.h"

#include "../tp-core/tp_core.h"
//#include "../csv-parser/single_include/csv.hpp"

namespace tpcm {

	int createPath(trajGCS& TrajFull, pathGCS& path, long& time);

	void createFullPath(pathGCS& path);

}
