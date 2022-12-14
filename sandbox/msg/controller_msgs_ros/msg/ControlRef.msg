# This message holds the input for longitudinal and lateral control.
# Based on a given trajectory, the control reference server computes current goal points for the underlying control loops.
# This is necessary, to ensure synchronicity between the two seperated loops.
# E.g. In case the longitudinal control is not holding up with the specified trajectory,
# the lateral control loop has to act based on the current real position instead of the "should be" position.

# Header
Header header

# The control reference therefor computes two control points: A main point (m) and a preview point (p)
# Information on current state
float64 velocity
float64 yawRate
float64 s_ist

# Main control point
# Arclength, speed and acceleration
float64 s_trj
float64 v_trj
float64 a_trj
# Curvature
float64 C_m
# Lateral offset
float64 y_m
# Yaw rate offset
float64 dpsi_m

# Preview point
float64 C_p
float64 y_p
float64 dpsi_p

