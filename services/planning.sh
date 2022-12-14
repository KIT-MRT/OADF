#!/bin/bash

# optional source
SCRIPT_DIR=$(dirname "$(readlink -f "$0")")
source "${SCRIPT_DIR}/base.sh"
check_arguments "${@}"
set -- "${ARGUMENTS[@]}"

# run with remaining arguments
roslaunch lanelet_map_launch lanelet_map.launch "$@"
