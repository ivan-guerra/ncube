#!/bin/bash

CWD=$(pwd)

# Root directory.
NSHAPES_PROJECT_PATH=$(dirname ${CWD})

# Scripts directory.
NSHAPES_SCRIPTS_PATH="${NSHAPES_PROJECT_PATH}/scripts/linux"

# Binary directory.
NSHAPES_BIN_DIR="${NSHAPES_PROJECT_PATH}/bin"

# Resource directory.
NSHAPES_RES_DIR="${NSHAPES_PROJECT_PATH}/resources"

# CMake build files and cache.
NSHAPES_BUILD_DIR="${NSHAPES_PROJECT_PATH}/build"
