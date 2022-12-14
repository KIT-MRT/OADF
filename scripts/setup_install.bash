#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
WS_DIR=$(readlink -f "${SCRIPT_DIR}/..")

source ${WS_DIR}/sandbox/launch/setup.bash --extend
