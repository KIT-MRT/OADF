# OADF

Open Automated Driving Framework. Full autonomous driving functionalities that can be used as a baseline for develope your own approaches, or connect to your own simulators or real robots/cars.

# How it works?:

OADF is packed as a black box in a Docker container. It will work in any computer where Docker can be installed, but GPU support is suggested. Launchfiles for several examples are included.

# Simulation requirements:

CoinCar simulation (https://github.com/coincar-sim) is included in OADF.

CarMaker plugins are included in sandbox/CM_ProjectDirectory_UNICARagil. CarMaker license is not provided inside OADF. Readme for compilation is included inside this folder. Requirements: ROS melodic or noetic should be installed in the host machine and CarMaker 9.1.2. ** Note: libgeographic-dev in Ubuntu 18.04 is still in version 1.49-2. In order to compile it should be uninstalled and install version 1.52

# Launch examples:

For all launchfiles, run docker (docker/.run_docker.sh) and execute source devel/launch/setup.bash

## Coincar Simulation:

Campus Ost: area in campus Ost of KIT

roslaunch lanelet_map_launch lanelet_map.launch map:=campus-ost

Ludwigsburg: area in Ludwigsburg altstadt

roslaunch lanelet_map_launch lanelet_map.launch map:=ludwigsburg

Visualization: Open a second docker and source devel/launch/setup.bash. cd launch/lanelet_map_launch/res and execute rviz -d coincar.rviz

## CarMaker Simulation:

In order to run CarMaker,  Open CarMaker with CMStart.sh. Launch roscore with Extras/Launch & Start Application. The select testrun with File/Open and press start to run the simulation. Simulation can be visualized in real time with File/IpgMovie

Ramp simulation: Straight lane with slope for test the controller

Testrun: ramp
roslaunch lanelet_map_launch lanelet_map.launch map:=ramp

Straight simulation: Straight lane with a slower vehicle. ACC tests
Testrun: straight
roslaunch lanelet_map_launch lanelet_map.launch map:=straight

Spiral simulation: Progressively more difficult curves to drive
Testrun: spiral
roslaunch lanelet_map_launch lanelet_map.launch map:=spiral

## Change the route

Route can be changed adding route:="laneletid1 laneletid2 laneletid3..." to the roslaunch. Lanelet ids can be obtained opening the corresponding map (in lanelet_map_launch/res) using JOSM.

## Disconnect modules:

All message definitions are included in msg folder, along with the ros non standar dependencies needed for compilation. Message explanation included on each message definition.

### Longitudinal control: To deactive add to launchfile controller:=lateral_only or controller:=none (Only working in CoinCar)

Two possible inputs, full trajectory to be controlled and car position, or only reference point.

Inputs: 
- /control_pipeline/control_reference_lon [controller_msgs_ros/ControlRef]
OR
- /2d_pipeline/trajectory_to_be_controlled_lon [nav_msgs/Path]
- /motion_state [automated_driving_msgs/MotionState]

Output of the controller is acceleration

Outputs:
/control/acceleration [controller_msgs_ros/StampedFloat64]

### Lateral control: To deactivate add to launchfile controller:=longitudinal_only or controller:=none (Only working in coincar)

Two possible inputs, full trajectory to be controlled and car position, or only reference point.
Inputs:
- /motion_state [automated_driving_msgs/MotionState]
- /control_pipeline/control_reference_lat [controller_msgs_ros/ControlRef]
OR
- /2d_pipeline/trajectory_to_be_controlled_lat [nav_msgs/Path]

Outut of the controller is steering value

Outputs:
- /control/steering [controller_msgs_ros/StampedFloat64]

### Planner: Optimization based planner in the free space. To deactivate add planner:=false

Inputs are free space in a corridor array format (include left and right borders and reference speed).

Inputs:
- /2d_pipeline/planning_corridor_array [behavior_msgs/PlanningCorridorArray]
- /motion_state [automated_driving_msgs/MotionState]

Output is position used for calculate the trajectory, and trajectory to be controlled (only longitudinal is used for CarMaker. Both are used for coincar, but they can be the same).

Outputs:
- /2d_pipeline/normal_trajectory_lat [nav_msgs/Path]
- /2d_pipeline/normal_trajectory_lon [nav_msgs/Path]
- /control_motion_state [automated_driving_msgs/MotionState]

Behavior

### Behavior module: behavior arbitration to select free space and change between basic scenarios (yielding, lane change)

Inputs are the predicted obstacles (comes from a map based prediction based on ground truth from simulation), position of the car and map information (include speed limits, stop lines and relationship between lanes).

Inputs: 
- /motion_state_20hz [automated_driving_msgs/MotionState]
- /prediction/predicted_objects [lanelet_msgs/LaneletMatchedObjectStateArray]
- map (not in topic). File information in launchfile

Output is free space and reference speed profile.

Outputs:
- /2d_pipeline/planning_corridor [behavior_msgs/PlanningCorridor]
