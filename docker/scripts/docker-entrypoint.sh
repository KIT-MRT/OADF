#!/bin/bash
set -e

source /opt/mrtsoftware/setup.bash
source /opt/mrtros/setup.bash

export GPG_TTY=$(tty)

# Set language (otherwise catkin fails if environment variables contain unicode symbols!)
export LANG=C.UTF-8
export LC_ALL=C.UTF-8

# export hostname=$(hostname)
export MAP=$map
source /workspace/install/setup.bash
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/lib/asoa_core-0.3.0/
#exec roslaunch lanelet_map_launch lanelet_map.launch map:=melaten
exec "$@"
