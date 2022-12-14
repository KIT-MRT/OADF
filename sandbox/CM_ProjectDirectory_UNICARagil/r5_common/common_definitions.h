#ifndef COMMON_DEFINITIONS_H
#define COMMON_DEFINITIONS_H

// Set configuration of code manually dependig on the system that service-no-runtime repo is being compiled on
// #define RUN_ON_R5

#include <stdint.h>
#include "unicar-definitions/UNICAR_definitions.h"


typedef struct wheelData_double {

    double DM_1;
    double DM_2;
    double DM_3;
    double DM_4;

} wheelData_double;

namespace common_def {

    // Setpoint values for actuators
    typedef struct setpointDM {

        wheelData_double steering;
        wheelData_double torque;
        wheelData_double speed_lim;
        wheelData_double park_brake_active;
        wheelData_double wheel_acc;
        bool ackermann_control_flag;

    } setpointDM;

    // State of dynamic modules regarding current torque and its limits
    typedef struct dynState {

        float max_drive_trq_Nm;
        float max_regen_brake_trq_Nm;
        float max_brake_trq_Nm;
        float steering_angle_rad;
        float wheel_speed_rad_s;
        int spin_direction; // 1 if spinning forward | -1 if spinning backwards | 0 if not spinning.

        struct misc {
            uint8_t frame;
            taitime time;
        } misc;

    } dynState;

    // Struct for current state of the vehicle
    typedef struct unicarState {

        struct pos {
            double east;
            double north;
            double lat;
            double lon;
            double h;
            double yaw;
        } pos;

        struct vel {
            double east;
            double north;
            double angle;
            double mag;
            double x;
            double y;
            double yaw;
        } vel;

        struct acc {
            double east;
            double north;
            double mag;
            double x;
            double y;
        } acc;

        struct misc {
            taitime time;
            uint8_t frame;
            uint8_t status;
            int run_dir;
        } misc;

    } unicarState;

}

#endif //COMMON_DEFINITIONS_H
