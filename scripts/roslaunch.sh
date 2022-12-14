#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
WS_DIR=$(readlink -f "${SCRIPT_DIR}/..")

# read script name
if [[ $# -eq 0 ]]; then
  echo "Usage: ./roslaunch.sh ARGS"
  exit 1
fi

${WS_DIR}/docker/run_docker.sh "roslaunch $@"
