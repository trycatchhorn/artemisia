#!/bin/bash

#################################################################################
#                                                                               #
# This script installs the stack API compiled as a shared dynamic library into  #
# 'usr/local/lib'. The stack API is compiled in both a debug version and a      #
# release version.                                                              #
#                                                                               #
# Usage:                                                                        #
# ./install - installs the stack API in both debug -and release mode.           #
# ./install [options]                                                           #
#                                                                               #
# -h     Shows help message.                                                    #
# -d     Install the shared dynamic library in debug mode.                      #
# -r     Install the shared dynamic library in release mode.                    #
#                                                                               #
# Author: Brian Horn                                                            #                     
# Email: trycatchhorn@gmail.com                                                 #                     
# Version: 1.0.0                                                                #
#                                                                               #
#################################################################################

# Build directory.
STACK_SHARED_LIB_BUILD_DIR=./build

# Path -and filename for the shared dynamic library compiled in debug mode.
STACK_SHARED_LIB_DEBUG=$STACK_SHARED_LIB_BUILD_DIR/debug/libstackd.dylib

# Path -and filename for the shared dynamic library compiled in release mode.
STACK_SHARED_LIB_RELEASE=$STACK_SHARED_LIB_BUILD_DIR/release/libstack.dylib

# Install directory for the shared dynamic libraries - debug and release.
STACK_SHARED_LIB_INSTALL_DIR_1=/usr
STACK_SHARED_LIB_INSTALL_DIR_2=$STACK_SHARED_LIB_INSTALL_DIR_1/local
STACK_SHARED_LIB_INSTALL_DIR=$STACK_SHARED_LIB_INSTALL_DIR_2/lib

# Install debug version of shared dynamic library?
DO_INSTALL_LIB_DEBUG=true

# Install release version of shared dynamic library?
DO_INSTALL_LIB_RELEASE=true

# Create usage function
Usage() {
USAGE_MESSAGE=$(
cat <<EOF
$0    Installs the stack API in both debug -and release mode. 
$0    [options]

      -h    Shows this help message.
      -d    Install the shared dynamic library in debug mode.
      -r    Install the shared dynamic library in release mode.
EOF
)
    echo "$USAGE_MESSAGE"
}

# Check permissions.
if [ "$(id -u)" != "0" ]; then
    echo "This script must be run as root. Aborting." 2>&1
    exit 1
fi

# Parse command-line arguments.
while getopts "hdr" OPTION; do
  case "$OPTION" in
    h)
      Usage
      exit 0
      ;;
    d)
      DO_INSTALL_LIB_DEBUG=true
      DO_INSTALL_LIB_RELEASE=false
      ;;
    r)
      DO_INSTALL_LIB_RELEASE=true
      DO_INSTALL_LIB_DEBUG=false
      ;;
    *)
      Usage
      exit 1
      ;;
  esac
done

# Handle the installation of libstackd.dylib (debug)
if $DO_INSTALL_LIB_DEBUG; then
    if [[ ! -f $STACK_SHARED_LIB_DEBUG ]]; then
	echo "Could not find the file $STACK_SHARED_LIB_DEBUG. Aborting." 2>&1
	exit 1    
    else
        # Extract filename from path.
	STACK_SHARED_LIB_DEBUG_FILENAME=$(basename $STACK_SHARED_LIB_DEBUG)
	# Create install directory if it does not exist.
	if [[ ! -d $STACK_SHARED_LIB_INSTALL_DIR_2 ]]; then
	    mkdir $STACK_SHARED_LIB_INSTALL_DIR_2
	fi
	if [[ ! -d $STACK_SHARED_LIB_INSTALL_DIR ]]; then
	    mkdir $STACK_SHARED_LIB_INSTALL_DIR
	fi
        # Copy library to install location and rename it according to the compatibility version.
	cp -f $STACK_SHARED_LIB_DEBUG $STACK_SHARED_LIB_INSTALL_DIR/libstackd.1.0.0.dylib
	if [[ -f $STACK_SHARED_LIB_INSTALL_DIR/libstackd.1.0.0.dylib ]]; then	
	    # Remove previously installed libraries.
	    rm -f $STACK_SHARED_LIB_INSTALL_DIR/$STACK_SHARED_LIB_DEBUG_FILENAME
	    # Create symbolic link to library.
	    (cd $STACK_SHARED_LIB_INSTALL_DIR && ln -s libstackd.1.0.0.dylib $STACK_SHARED_LIB_DEBUG_FILENAME)
	    # Perform check to see if library was installed successfully.
	    if [[ -L $STACK_SHARED_LIB_INSTALL_DIR/$STACK_SHARED_LIB_DEBUG_FILENAME ]] && [[ -f $STACK_SHARED_LIB_INSTALL_DIR/libstackd.1.0.0.dylib ]]; then
		echo "Library $STACK_SHARED_LIB_DEBUG_FILENAME was successfully installed in $STACK_SHARED_LIB_INSTALL_DIR."
	    else
		echo "Library $STACK_SHARED_LIB_DEBUG_FILENAME could not be installed in $STACK_SHARED_LIB_INSTALL_DIR." 2>&1
		exit 1
	    fi

	fi
    fi
fi

# Handle the installation of libstack.dylib (release)
if $DO_INSTALL_LIB_RELEASE; then
    if [[ ! -f $STACK_SHARED_LIB_RELEASE ]]; then
	echo "Could not find the file $STACK_SHARED_LIB_RELEASE. Aborting." 2>&1
	exit 1    
    else
        # Extract filename from path.
	STACK_SHARED_LIB_RELEASE_FILENAME=$(basename $STACK_SHARED_LIB_RELEASE)
	# Create install directory if it does not exist.
	if [[ ! -d $STACK_SHARED_LIB_INSTALL_DIR ]]; then
	    mkdir $STACK_SHARED_LIB_INSTALL_DIR
	fi
        # Copy library to install location and rename it according to the compatibility version.
	cp -f $STACK_SHARED_LIB_RELEASE $STACK_SHARED_LIB_INSTALL_DIR/libstack.1.0.0.dylib
	if [[ -f $STACK_SHARED_LIB_INSTALL_DIR/libstack.1.0.0.dylib ]]; then	
	    # Remove previously installed libraries.
	    rm -f $STACK_SHARED_LIB_INSTALL_DIR/$STACK_SHARED_LIB_RELEASE_FILENAME
	    # Create symbolic link to library.
	    (cd $STACK_SHARED_LIB_INSTALL_DIR && ln -s libstack.1.0.0.dylib $STACK_SHARED_LIB_RELEASE_FILENAME)
	    # Perform check to see if library was installed successfully.
	    if [[ -L $STACK_SHARED_LIB_INSTALL_DIR/$STACK_SHARED_LIB_RELEASE_FILENAME ]] && [[ -f $STACK_SHARED_LIB_INSTALL_DIR/libstack.1.0.0.dylib ]]; then
		echo "Library $STACK_SHARED_LIB_RELEASE_FILENAME was successfully installed in $STACK_SHARED_LIB_INSTALL_DIR."
	    else
		echo "Library $STACK_SHARED_LIB_RELEASE_FILENAME could not be installed in $STACK_SHARED_LIB_INSTALL_DIR." 2>&1
		exit 1
	    fi

	fi
    fi
fi

exit 0

