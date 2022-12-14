# Message for an Occupany of
# - one traffic participants
# - along one of its routes and
# - at one specific timeinterval

# Header
Header header

# Time interval of this occupancy
std_msgs/Time time
std_msgs/Duration duration

# Occupancy
geometry_msgs/Polygon polygon