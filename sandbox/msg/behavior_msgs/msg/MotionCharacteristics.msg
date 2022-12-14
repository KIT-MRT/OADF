# Preprocessed motion characteristics ready for plotting or other analysis

# Header
#   frame_id of the global reference frame (common: "map", "odom")
Header header

#   frame_id of the child frame that this MotionState describes (common: "vehicle", "sensor_x")
string child_frame_id

# Traveled distance since start of analysis
float64 traveled_distance

# Velocity
float64 velocity

# Acceleration
float64 acceleration

# Jerk
float64 jerk

