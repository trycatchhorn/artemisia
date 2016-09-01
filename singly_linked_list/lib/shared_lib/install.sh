#!/bin/bash

####################################################################################
#                                                                                  #
# This script installs the singly linked list API compiled as a shared             #
# dynamic library into 'usr/local/lib'. The singly linked list API is              #
# compiled in both a debug version and a release version.                          #
#                                                                                  #
# Usage:                                                                           #
# ./install - installs the singly linked list API in both debug -and release mode. #
# ./install [options]                                                              #
#                                                                                  #
# -h     Shows help message.                                                       #
# -d     Install the shared dynamic library in debug mode.                         #
# -r     Install the shared dynamic library in release mode.                       #
#                                                                                  #
# Author: Brian Horn                                                               #                     
# Email: trycatchhorn@gmail.com                                                    #                     
# Version: 1.0.0                                                                   #
#                                                                                  #
####################################################################################

# Build directory.
SINGLY_LINKED_LIST_SHARED_LIB_BUILD_DIR=./build

# Path -and filename for the shared dynamic library compiled in debug mode.
SINGLY_LINKED_LIST_SHARED_LIB_DEBUG=$SINGLY_LINKED_LIST_SHARED_LIB_BUILD_DIR/debug/libsingly_linked_listd.dylib

# Path -and filename for the shared dynamic library compiled in release mode.
SINGLY_LINKED_LIST_SHARED_LIB_RELEASE=$SINGLY_LINKED_LIST_SHARED_LIB_BUILD_DIR/release/libsingly_linked_list.dylib

# Install directory for the shared dynamic libraries - debug and release.
SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR_1=/usr
SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR_2=$SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR_1/local
SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR=$SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR_2/lib

# Install debug version of shared dynamic library?
DO_INSTALL_LIB_DEBUG=true

# Install release version of shared dynamic library?
DO_INSTALL_LIB_RELEASE=true

# Create usage function
Usage() {
USAGE_MESSAGE=$(
cat <<EOF
$0    Installs the singly linked list API in both debug -and release mode. 
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

# Handle the installation of libsingly_linked_listd.dylib (debug)
if $DO_INSTALL_LIB_DEBUG; then
    if [[ ! -f $SINGLY_LINKED_LIST_SHARED_LIB_DEBUG ]]; then
	echo "Could not find the file $SINGLY_LINKED_LIST_SHARED_LIB_DEBUG. Aborting." 2>&1
	exit 1    
    else
        # Extract filename from path.
	SINGLY_LINKED_LIST_SHARED_LIB_DEBUG_FILENAME=$(basename $SINGLY_LINKED_LIST_SHARED_LIB_DEBUG)
	# Create install directory if it does not exist.
	if [[ ! -d $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR_2 ]]; then
	    mkdir $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR_2
	fi	
	if [[ ! -d $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR ]]; then
	    mkdir $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR
	fi
        # Copy library to install location and rename it according to the compatibility version.
	cp -f $SINGLY_LINKED_LIST_SHARED_LIB_DEBUG $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR/libsingly_linked_listd.1.0.0.dylib
	if [[ -f $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR/libsingly_linked_listd.1.0.0.dylib ]]; then	
	    # Remove previously installed libraries.
	    rm -f $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR/$SINGLY_LINKED_LIST_SHARED_LIB_DEBUG_FILENAME
	    # Create symbolic link to library.
	    (cd $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR && ln -s libsingly_linked_listd.1.0.0.dylib $SINGLY_LINKED_LIST_SHARED_LIB_DEBUG_FILENAME)
	    # Perform check to see if library was installed successfully.
	    if [[ -L $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR/$SINGLY_LINKED_LIST_SHARED_LIB_DEBUG_FILENAME ]] && [[ -f $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR/libsingly_linked_listd.1.0.0.dylib ]]; then
		echo "Library $SINGLY_LINKED_LIST_SHARED_LIB_DEBUG_FILENAME was successfully installed in $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR."
	    else
		echo "Library $SINGLY_LINKED_LIST_SHARED_LIB_DEBUG_FILENAME could not be installed in $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR." 2>&1
		exit 1
	    fi

	fi
    fi
fi

# Handle the installation of libsingly_linked_list.dylib (release)
if $DO_INSTALL_LIB_RELEASE; then
    if [[ ! -f $SINGLY_LINKED_LIST_SHARED_LIB_RELEASE ]]; then
	echo "Could not find the file $SINGLY_LINKED_LIST_SHARED_LIB_RELEASE. Aborting." 2>&1
	exit 1    
    else
        # Extract filename from path.
	SINGLY_LINKED_LIST_SHARED_LIB_RELEASE_FILENAME=$(basename $SINGLY_LINKED_LIST_SHARED_LIB_RELEASE)
	# Create install directory if it does not exist.
	if [[ ! -d $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR_2 ]]; then
	    mkdir $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR_2
	fi
	if [[ ! -d $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR ]]; then
	    mkdir $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR
	fi
        # Copy library to install location and rename it according to the compatibility version.
	cp -f $SINGLY_LINKED_LIST_SHARED_LIB_RELEASE $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR/libsingly_linked_list.1.0.0.dylib
	if [[ -f $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR/libsingly_linked_list.1.0.0.dylib ]]; then	
	    # Remove previously installed libraries.
	    rm -f $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR/$SINGLY_LINKED_LIST_SHARED_LIB_RELEASE_FILENAME
	    # Create symbolic link to library.
	    (cd $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR && ln -s libsingly_linked_list.1.0.0.dylib $SINGLY_LINKED_LIST_SHARED_LIB_RELEASE_FILENAME)
	    # Perform check to see if library was installed successfully.
	    if [[ -L $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR/$SINGLY_LINKED_LIST_SHARED_LIB_RELEASE_FILENAME ]] && [[ -f $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR/libsingly_linked_list.1.0.0.dylib ]]; then
		echo "Library $SINGLY_LINKED_LIST_SHARED_LIB_RELEASE_FILENAME was successfully installed in $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR."
	    else
		echo "Library $SINGLY_LINKED_LIST_SHARED_LIB_RELEASE_FILENAME could not be installed in $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR." 2>&1
		exit 1
	    fi

	fi
    fi
fi

exit 0

