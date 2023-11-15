#!/bin/bash

source config.sh

# Remove the binary directory.
if [ -d $NSHAPES_BIN_DIR ]
then
    echo "removing '$NSHAPES_BIN_DIR'"
    rm -r $NSHAPES_BIN_DIR
fi

# Remove the CMake build directory.
if [ -d $NSHAPES_BUILD_DIR ]
then
    echo "removing '$NSHAPES_BUILD_DIR'"
    rm -rf $NSHAPES_BUILD_DIR
fi
