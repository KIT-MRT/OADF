# CarMaker project directory for UNICARagil

This project directory for CarMaker 9.0.x includes different functionalities needed for
the main features of the UNICARagil vehicles:
- 4 electric motors 
    -> independently controllable
- 4 wheels steerable
    -> independently controllable
- c-code interface to feed control algorithm with trajectory

# General usage

Steps to use the directory with CarMaker (Installation of CarMaker is mandatory). 

* Clone the repository

* Open Makefile in src/ and set the correct path to the installation directory of CarMaker and the correct version (min. 9.0)

* If you haven't updated to CarMaker 9.0, you can try this commit: f7054a0da629513e42eaef26ff78a320c69a08bb
* If you haven't updated to CarMaker 8.0, you can try this commit: c043b02c34f48f2642cf2741862103950d768805

* Execute "make" in the src/ folder

* Open the CarMaker GUI 
  * File -> Project directory -> Select.. 
  * Select this directory as current project directory
  * Application -> Configuration
  * Choose the newly compiled executable (e.g. src/CarMaker.win64.exe) and click on "Start and Connect"

* Select an example TestRun or create your own

* Hit "Start"

## Quick Start
In order to quick start there are examples you can load. You can load the TestRuns saved in the
Data/TestRun folder or load the TestSeries also located there.

Additionally the project directory includes example (not validated) vehicle models for,
- AUTOtaxi
- AUTOshuttle

located in Data/Vehicle. 

:exclamation: Note that the vehicle models are generated with the IPG vehicle generator and are not validated 
although the mass and geometry was taken from the latest decision. Also keep in
mind that the suspension is simplified to a linear-2DOF at the front an linear-3DOF at the rear. As soon as the real 
suspension was measured and converted into a virtual model changes to the vehicle model need to be applied.

There are no perception sensors built in the vehicle model for now. Can be added 
manually.


## Models
The project folder comes with 3 additional models compared to a normal directory
to meet the UNICARagil goals. Those are:
- AllWheelSteering (.c)
- WheelControlModel (.c)
- VehicleControl_UNICAR (.c)

All models are written in C and are located in the src/ folder. They can be 
edited and compiled by anyone (execute make, inside of a console: msys for Windows,
 console when using Linux). A Simulink version of the models is not planned yet, 
but is generally possible.


The general setup of the models is designed like this:
```
VehicleControl_UNICAR ---- steering angles ------>  AllWheelSteering
                     |
                     `---- wheel movement ------->  WheelControlModel
```

Following all files/models are gonna be described a bit more in detail:

* AllWheelSteering(.c):
This model allows the User to steer each wheel independently from each other. 
Additionally it covers different modes which have different functionalities like
in phase steering, counter phase steering, pivoted turn, ... and so on. Modes can
be switched via the Quantity "Steer.Mode". All details and modes can be found
inside the .c file. The parameter Steering.Rack2StWhl describes the relation
between steering rack and steering wheel. It can be set in the Vehicle Dataset
"Misc" tab. A motor model for the steering is not implemented. Meaning that once
an angle or rack movement is set it is applied immediately 

* WheelControlModel(.c):
This model allows the user to set the desired torque, rotational speed or load
at each wheel independently. Same as the steering model this model also has
some predefined modes. There is Standard, PivotedTurn, Rotate, RotControl, ....
However, the modes are explained more in detail within the .c file.

* VehicleControl_UNICAR(.c):
This model contains a function (int updateTrajectory (tUnicarTraj *Traj)) 
where the trajectory can be filled with values. It also contains a function 
dummy for the controller code (int controlModelCalculation()).

:point_right: Good to know:

-> Datastructure:
At the moment there is a global structure of the data used within the set of
models.

tUnicarControl comes with a timestamp (double), the trajectory, the values for
steering the wheels and the values for controling the wheel speeds:

```
typedef struct tUnicarControl {
    double timestamp;
    tUnicarTraj UnicarTraj;
    tUnicarControlSteer UnicarControlSteer;
    tUnicarControlAcc UnicarControlAcc;
} tUnicarControl;
```

How the tUnicar* structs are defined is described in UnicarModels.h.

Note: These data definitions are only examples of how it could look like. The
definitions can be modified or replaced by the user.

# CarMaker for Simulink

This project also has a similar interface with the usage of CarMaker4SL. To use 
this interface do following steps:
- open Matlab (r2019a) 
  - navigate into /src_cm4sl
  - run cmenv.m (needs to be replaced, if started on a Windows machine)
  - open the UNICAR_model.slx file
- double click on "Open CarMaker GUI"
  - open the example TestRun "LaneChange_ISO_UNICAR_electricpt"
  - select the vehicle "AUTOtaxi4SL.car" (no built in models in that car)
  - hit the "Start" button

You can modify the model by clicking on the "CarMaker" symbol in the middle. 
Modifications have been done inside the VehicleControl, Steering (IPGVehicle, 
CarAndTrailier) and the Powertrain (IPGVehicle) blocks. Only very simple models, 
even simpler than the ones without Simulink have been modeled.

:exclamation: Note that the powertrain and steering modes do not apply to the 
CarMaker4SL version.

# Run the Driver Trajectory Example
- Build the ros workspace and your CarMaker executables by runnung `./build_cmrosif.sh`
  - If you're experiencing issues with your installation, have a look at the CarMaker ROS Interface documentation `doc/CMRosIF_UsersGuide.pdf`
- Start the CarMaker GUI via the bash script `./CMStart.sh`
- Choose the TestRun IPGDriverTrajectory_ISO_LaneChange
- Launch the ros nodes, by clicking: `Extras->CMRosIF->Launch & Start Application`
- Make sure DrvTrj.ModeReq is set to 1, e.g. in the MiniManeuvers: `Eval first(DM.ManTime > 1) ? DrvTrj.ModeReq = 1`
- When synchronization is activated in the CMRosIFParameters (`Node.Sync.Mode = 1`) and syncs on the incoming trajectory topic `/trj_in`, set the simulation time higher than the rosbag play rate, to make sure the simulation has enough time to wait for a new message from the bagfile.
- Start the TestRun
- Start the rosbag from a new terminal and remap the topic like so:
`rosbag play ros/IPGDriverTrajectory_ISO_LaneChange.bag /trj_out:=/trj_in`
- Check the `Movie/DriverTrajectory.tclgeo`file for information about trajectory visualization inside IPGMovie

# Problems?
* PROBLEMS when building? --> delete .depend and execute 

```
make clean; make
```
* PROBLEMS with any of the models or interfaces? -> contact David Wójcik (IPG)

Authors: Andreas Wagener & David Wójcik, IPG Automotive GmbH
