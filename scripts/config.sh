#!/bin/bash

CWD=$(pwd)

# Root directory.
NCUBE_PROJECT_PATH=$(dirname ${CWD})

# Scripts directory.
NCUBE_SCRIPTS_PATH="${NCUBE_PROJECT_PATH}/scripts/linux"

# Binary directory.
NCUBE_BIN_DIR="${NCUBE_PROJECT_PATH}/bin"

# Resource directory.
NCUBE_RES_DIR="${NCUBE_PROJECT_PATH}/resources"

# CMake build files and cache.
NCUBE_BUILD_DIR="${NCUBE_PROJECT_PATH}/build"
