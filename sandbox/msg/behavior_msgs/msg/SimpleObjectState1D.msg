# Message for the state of an object for 1D Behavior Generation
# License: BSD

# Header
Header header

# Lifetime ID of the object
uint32 object_id

# Lanelet ID in which object currently is
uint32 roadmap_id

# Motion state of the object
#    in 1D coordinates: relative to the start of the roadmap
float32 s
float32 v
float32 a

# Current motion predictions of the object
Prediction1D[] predictions

# Object Dimensions
#    in s-coordinates, e.g. length_back=2., length_front=2.
float32 length_back
float32 length_front
