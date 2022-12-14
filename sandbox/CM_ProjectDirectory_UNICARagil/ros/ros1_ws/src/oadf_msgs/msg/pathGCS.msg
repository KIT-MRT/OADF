#Header               header
float64 send_tai_seconds
float64 send_tai_nanoseconds

# Time vectors that describe each point
float64 tai_seconds
float64 tai_nanoseconds

# Pose origin flags
bool use_previous_trj
bool use_atlatec

# Number of path elements (To verify, that all path elements are received correctly) nElements = PlanningPose + Number of Path Elements. (Like 51 in trajectory, but here it's X+1)
int32 n_elements

# Trajectory positions in global ellipsoidic coordinates (ETRS89). 51 elements, the first element contains the position where the trajectory was planned on
float64[] pos_ell_lat_rad
float64[] pos_ell_lon_rad
float64[] pos_ell_h_m

# Slope between two trajectory points in longitudinal and lateral
float64[] slope_long
float64[] slope_lat

# Reference velocity in arc length direction for each path position.
# Number of elements: "Number of emergency path positions" (no velocity must be given for the planning pose (should be 0)
float64[] pos_arc_vel_m_s


# Reference Vehicle Orientation. The first element holds the absolute orientation of the planning pose. In the following elements the difference to the previous element is indicated
# Length of the vectors is: "Number of emergency path positions"+1 (+1 for planning pose in first vector element)
float64[] ori_enu_psi_rad

# Direction indicator signal for each path element (0 - off, 1 - left, 2 - right)
# Length of the vectors is: "Number of emergency path positions" (no direction indicator signal must be given for the planning pose (should be 0))
int32[] dir_ind

