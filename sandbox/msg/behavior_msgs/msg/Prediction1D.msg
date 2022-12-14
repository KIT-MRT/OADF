# Message for the prediction of an object
# License: BSD

# Header
Header header

# ID of the prediction
#    Meant to be unique for one set of predictions for an object
uint32 prediction_id

# Actual prediction
#    See parent message for definition of s inside StampedPose1D
StampedPose1D[] s_with_delta_time
