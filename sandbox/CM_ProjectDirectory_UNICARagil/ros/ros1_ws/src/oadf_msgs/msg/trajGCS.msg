#Header               header
float64 send_tai_seconds
float64 send_tai_nanoseconds

# Pose origin flags
bool use_previous_trj
bool use_atlatec

# Time vectors that describe each point
float64[] tai_seconds
float64[] tai_nanoseconds

# Standstill flag (0, 1) - Data type could theoretically be changed to boolean but is currently not available in the architecture tool / IDL
int32[] standstill
int32[] parking

# Trajectory positions in global ellipsoidic coordinates (ETRS89). 51 elements, the first element contains the position where the trajectory was planned on
float64[] pos_ell_lat_rad
float64[] pos_ell_lon_rad
float64[] pos_ell_h_m

# Slope between two trajectory points in longitudinal and lateral
float64[] slope_long
float64[] slope_lat

# Velocity vector in polar coordinates (Magnitude & Angle) for each trajectory element. 50 elements (only for the “real” trajectory elements).
float64[] vel_enu_mag_m_s
float64[] vel_enu_angle_rad

# Acceleration vector in polar coordinates (Magnitude & Angle) for each trajectory element. 50 elements (only for the “real” trajectory elements).
float64[] acc_enu_mag_m_s2
float64[] acc_enu_angle_rad

# Orientation and its two derivatives. 51 elements for orientation (planning pose). Velocity and Acceleration can be 50 elements (only for the “real” trajectory elements).
float64[] ori_enu_psi_rad
float64[] ori_vel_enu_psi_rad_s
float64[] ori_acc_enu_psi_rad_s2
