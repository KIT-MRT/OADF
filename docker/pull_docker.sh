#!/bin/bash

function pull_docker() {
  # check function arguments
  if [[ $# -ne 1 ]]; then
    >&2 echo "Error: invalid number of input arguments for 'pull_docker CONFIG'"
    exit 1
  fi

  # read config file
  local registry=$(grep REGISTRY $1 | head -n 1 | sed -e 's/.*: //')
  local image=$(grep IMAGE $1 | head -n 1 | sed -e 's/.*: //')
  local tag=$(grep TAG $1 | head -n 1 | sed -e 's/.*: //')
  if [ -z ${registry} ] || [ -z ${image} ] || [ -z ${tag} ]; then
    >&2 echo "Error: either registry, image or tag not found in config file '$1'"
    exit 2
  fi

  # create url
  local url="${registry}/${image}:${tag}"

  # print or pull
  if [[ ${PRINT_ONLY} = true ]]; then
    echo ${url}

  else
    # pull
    docker pull ${PULL_ARGS} ${url}
    ret=$?

    # check return code
    if [[ ${ret} -ne 0 ]]; then
      >&2 echo "Error: could not pull image '${url}'."
      >&2 echo "Did you forget to run 'docker login ${registry}'?"
      exit ${ret}
    fi
  fi
}


# read arguments
PULL_ARGS=""

while [[ $# -gt 0 ]]; do
  key="$1"
  case ${key} in
    -q|--quiet)
    PULL_ARGS="-q"
    shift # past argument
    ;;
    --print)
    PRINT_ONLY=true
    shift # past argument
    ;;
    -h|--help)
    SHOW_HELP=true
    shift # past argument
    ;;
    *)
    echo "Unknown argument: ${key}"
    exit 1
    ;;
  esac
done


# help
if [[ ${SHOW_HELP} = true ]]; then
  echo "Usage:  ./pull_docker.bash [OPTIONS]"
  echo ""
  echo "Options:"
  echo "  -q, --quiet   Suppress verbose output"
  echo "      --print   Print image name only without pulling"
  echo "  -h, --help    Show this message"
  exit 0
fi


# pull containers
SCRIPT_DIR=$(dirname "$(readlink -f "$0")")

pull_docker ${SCRIPT_DIR}/docker.yaml
