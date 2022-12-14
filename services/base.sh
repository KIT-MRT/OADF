#!/bin/sh

BASE_DIR=$(dirname "$(readlink -f "$0")")
WS_DIR=$(readlink -f "${BASE_DIR}/..")
SANDBOX_DIR=$(readlink -f "${WS_DIR}/sandbox")

CONFIG_DIR=$(readlink -f "${WS_DIR}/../.config")


check_arguments() {
  while [ $# -gt 0 ]; do
    local key="$1"
    case $key in
      --source)
      source "${SANDBOX_DIR}/install/setup.bash" --extend || exit 1
      shift
      ;;
      --pid)
      local last_pid=$(($2 - 1))
      echo "${last_pid}" > /proc/sys/kernel/ns_last_pid
      local ret=$?
      if [ ${ret} -ne 0 ]; then
        >&2 echo "Insufficient permissions to set PID"
        exit ${ret}
      fi
      shift
      shift
      ;;
      *)
      ARGUMENTS+=("$1")
      shift
      ;;
    esac
  done
}


read_config_param() {
  # usage: param=$(read_config_param "config_name" "param_name") || exit 1
  if [[ $# -ne 2 ]]; then
    >&2 echo "Error: config name or parameter name missing for read_config_param()"
    exit 1
  fi

  # directory
  mkdir -p ${CONFIG_DIR} || exit 1

  # file
  local config_file="${CONFIG_DIR}/$1.yaml"
  if [ ! -f "${config_file}" ]; then
    # check default
    local default_config="${SCRIPT_DIR}/$1.yaml"
    if [ ! -f "${default_config}" ]; then
      >&2 echo "Error: default config '$1.yaml' not found"
      exit 1
    fi

    # copy default
    cp ${default_config} ${config_file} || exit 1
  fi

  # parameter
  local config_line=$(grep "^$2: " ${config_file} -m1)
  if [[ -z ${config_line} ]]; then
    >&2 echo "Error: parameter '$2' not found in config"
    exit 1
  fi
  local param=$(sed -e 's/.*: //' <<< ${config_line})
  echo ${param}
}
