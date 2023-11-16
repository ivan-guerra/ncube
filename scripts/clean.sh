#!/bin/bash

source config.sh

# Remove the binary directory.
if [ -d $NCUBE_BIN_DIR ]
then
    echo "removing '$NCUBE_BIN_DIR'"
    rm -r $NCUBE_BIN_DIR
fi

# Remove the CMake build directory.
if [ -d $NCUBE_BUILD_DIR ]
then
    echo "removing '$NCUBE_BUILD_DIR'"
    rm -rf $NCUBE_BUILD_DIR
fi
