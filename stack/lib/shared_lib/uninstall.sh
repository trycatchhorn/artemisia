#!/bin/bash

#################################################################################
#                                                                               #
# This script uninstalls the stack API compiled as a shared dynamic library     #
# from 'usr/local/lib'.                                                         #
#                                                                               #
# Usage:                                                                        #
# ./uninstall - uninstalls the stack API in both debug -and release mode.       #
# ./uninstall [options]                                                         #
#                                                                               #
# -h     Shows help message.                                                    #
# -d     Uninstall the shared dynamic library in debug mode.                    #
# -r     Uninstall the shared dynamic library in release mode.                  #
#                                                                               #
# Author: Brian Horn                                                            #                     
# Email: trycatchhorn@gmail.com                                                 #                     
# Version: 1.0.0                                                                #
#                                                                               #
#################################################################################

# Install directory for the shared dynamic libraries - debug and release.
STACK_SHARED_LIB_INSTALL_DIR=/usr/local/lib

# Check permissions.
if [ "$(id -u)" != "0" ]; then
    echo "This script must be run as root. Aborting." 2>&1
    exit 1
fi

# Create usage function
Usage() {
USAGE_MESSAGE=$(
cat <<EOF
$0    Uninstalls the stack API in both debug -and release mode. 
$0    [options]

      -h    Shows this help message.
      -d    Uninstall the shared dynamic library in debug mode.
      -r    Uninstall the shared dynamic library in release mode.
EOF
)
    echo "$USAGE_MESSAGE"
}

# Check permissions.
if [ "$(id -u)" != "0" ]; then
    echo "This script must be run as root. Aborting." 2>&1
    exit 1
fi

# Fuction to handle uninstall of libstackd.dylib (debug)
DoUninstallDebug() {
    # Handle uninstall of libstackd.dylib (debug)
    if [[ -f $STACK_SHARED_LIB_INSTALL_DIR/libstackd.dylib ]]; then
	rm -f $STACK_SHARED_LIB_INSTALL_DIR/libstackd.dylib
	rm -f $STACK_SHARED_LIB_INSTALL_DIR/libstackd.1.0.0.dylib
    else
	echo "Nothing to uninstall."
	exit 0
    fi
    if [[ ! -f $STACK_SHARED_LIB_INSTALL_DIR/libstackd.dylib ]]; then
	echo "Library libstackd.dylib was successfully uninstalled from $STACK_SHARED_LIB_INSTALL_DIR."
    else
	echo "Library libstackd.dylib could not be uninstalled from $STACK_SHARED_LIB_INSTALL_DIR." 2>&1
    fi
}

# Function to handle uninstall of libstack.dylib (release)
DoUninstallRelease() {
    # Handle uninstall of libstack.dylib (release)
    if [[ -f $STACK_SHARED_LIB_INSTALL_DIR/libstack.dylib ]]; then
	rm -f $STACK_SHARED_LIB_INSTALL_DIR/libstack.dylib
	rm -f $STACK_SHARED_LIB_INSTALL_DIR/libstack.1.0.0.dylib
    else 
	echo "Nothing to uninstall."
	exit 0
    fi
    if [[ ! -f $STACK_SHARED_LIB_INSTALL_DIR/libstack.dylib ]]; then
	echo "Library libstack.dylib was successfully uninstalled from $STACK_SHARED_LIB_INSTALL_DIR."
    else
	echo "Library libstack.dylib could not be uninstalled from $STACK_SHARED_LIB_INSTALL_DIR." 2>&1
    fi
}

# Parse command-line arguments.
if [ $# -eq 0 ]; then
    DoUninstallDebug
    DoUninstallRelease
fi
while getopts "hdr" OPTION; do
  case "$OPTION" in
    h)
      Usage
      exit 0
      ;;
    d)
      DoUninstallDebug
      ;;
    r)
      DoUninstallRelease
      ;;
    *)
      Usage
      exit 1
      ;;
  esac
done

exit 0