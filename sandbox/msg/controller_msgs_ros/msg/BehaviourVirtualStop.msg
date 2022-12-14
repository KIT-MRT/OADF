# This message holds information about a virtual stop

uint8 VIRTUAL_STOP_ENABLED_AUTOMATIC=0 # Algo is sure about decision and enables a virtual stop => no driving
uint8 VIRTUAL_STOP_DISABLED_AUTOMATIC=1 # Algo is sure about decision and disables a virtual stop => driving
uint8 VIRTUAL_STOP_ENABLED_USER=2 # User enabled the stop line (after request of unsure Algo or as override) => no driving
uint8 VIRTUAL_STOP_DISABLED_USER=3 # User disabled the stop line (after request of unsure Algo or as override) => driving

float64 distanceVirtualStop
int64 idVirtualStop
string description
uint8 state
