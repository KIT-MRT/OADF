#
# CarMaker IPGDriver Poses

Header               header         #
float64              time           # Time for current trajectory point    (required)
geometry_msgs/Point  position       # Position in Fr0-coordinates          (required)
geometry_msgs/Point  velocity       # Velocity in Fr0-coordinates          (optional)
float64              abs_vel        # Absolute velocity                    (required)
geometry_msgs/Point  acceleration   # Acceleration in Fr0-coordinates      (optional)
float64              abs_acc        # Absolute acceleration                (optional)
float64              yaw            # Yaw angle                            (required)
float64              kappa          # Curvature                            (recommended)
