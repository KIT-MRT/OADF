#!/bin/bash
set -e

source ${WORKSPACE_INSTALL_DIR}/setup.bash

export GPG_TTY=$(tty)

# Set language (otherwise catkin fails if environment variables contain unicode symbols!)
export LANG=C.UTF-8
export LC_ALL=C.UTF-8

export hostname=$(hostname)

exec "$@"
