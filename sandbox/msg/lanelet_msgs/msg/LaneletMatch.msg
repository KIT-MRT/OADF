# Lanelet match of an object
# License: BSD

# ID of the lanelet
int64 lanelet_id

# true if the lanelet identified by lanelet_id is inverted for this match
bool isInverted

# Euclidean distance to lanelet
float32 lanelet_distance

# Squared Mahalanobis distance to closest point on centerline of lanelet
float32 mahalanobis_distance_squared

# Projection of object to closest point on centerline of lanelet
Projection centerline_projection
