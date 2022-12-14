cmake_minimum_required(VERSION 3.5.1)
project(behavior_msgs)

# This is used to enable cpack.
find_package(mrt_cmake_modules REQUIRED)

find_package(catkin REQUIRED COMPONENTS geometry_msgs message_generation std_msgs)

add_message_files(
  DIRECTORY msg
  FILES
  Gaussian2d.msg
  GaussianMixture2d.msg
  Corridor.msg
  CorridorArray.msg
  Covariance2d.msg
  Indicator.msg
  LaneletSequence.msg
  MotionCharacteristics.msg
  OccupanciesPrediction.msg
  OccupanciesPredictions.msg
  Occupancy.msg
  PedestrianOrientation.msg  
  PedestrianPrediction.msg
  PedestrianPredictionsArray.msg
  PedestrianPredictions.msg
  PlanningCorridor.msg
  PlanningCorridorArray.msg
  Point2d.msg
  PointWithVelocityObjective.msg
  Prediction1D.msg
  SimpleObjectState1D.msg
  SimpleObjectState1DArray.msg
  StampedPose1D.msg
  VonMisesMixture.msg
  VonMises.msg
  WeightedGaussian2d.msg
  WeightedVonMises.msg)


generate_messages(DEPENDENCIES geometry_msgs std_msgs)

catkin_package(CATKIN_DEPENDS geometry_msgs message_runtime std_msgs)

