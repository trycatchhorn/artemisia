#!/bin/bash

########################################################################################
#                                                                                      #
# This script uninstalls the singly linked list API compiled as a shared               #
# dynamic library from 'usr/local/lib'.                                                #
#                                                                                      #
# Usage:                                                                               #
# ./uninstall - uninstalls the singly linked list API in both debug -and release mode. #
# ./uninstall [options]                                                                #
#                                                                                      #
# -h     Shows help message.                                                           #
# -d     Uninstall the shared dynamic library in debug mode.                           #
# -r     Uninstall the shared dynamic library in release mode.                         #
#                                                                                      #
# Author: Brian Horn                                                                   #                     
# Email: trycatchhorn@gmail.com                                                        #                     
# Version: 1.0.0                                                                       #
#                                                                                      #
########################################################################################

# Install directory for the shared dynamic libraries - debug and release.
SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR=/usr/local/lib

# Check permissions.
if [ "$(id -u)" != "0" ]; then
    echo "This script must be run as root. Aborting." 2>&1
    exit 1
fi

# Create usage function
Usage() {
USAGE_MESSAGE=$(
cat <<EOF
$0    Uninstalls the singly linked list API in both debug -and release mode. 
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

# Fuction to handle uninstall of libsingly_linked_listd.dylib (debug)
DoUninstallDebug() {
    # Handle uninstall of libsingly_linked_listd.dylib (debug)
    if [[ -f $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR/libsingly_linked_listd.dylib ]]; then
	rm -f $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR/libsingly_linked_listd.dylib
	rm -f $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR/libsingly_linked_listd.1.0.0.dylib
    else
	echo "Nothing to uninstall."
	exit 0
    fi
    if [[ ! -f $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR/libsingly_linked_listd.dylib ]]; then
	echo "Library libsingly_linked_listd.dylib was successfully uninstalled from $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR."
    else
	echo "Library libsingly_linked_listd.dylib could not be uninstalled from $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR." 2>&1
    fi
}

# Function to handle uninstall of libsingly_linked_list.dylib (release)
DoUninstallRelease() {
    # Handle uninstall of libsingly_linked_list.dylib (release)
    if [[ -f $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR/libsingly_linked_list.dylib ]]; then
	rm -f $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR/libsingly_linked_list.dylib
	rm -f $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR/libsingly_linked_list.1.0.0.dylib
    else 
	echo "Nothing to uninstall."
	exit 0
    fi
    if [[ ! -f $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR/libsingly_linked_list.dylib ]]; then
	echo "Library libsingly_linked_list.dylib was successfully uninstalled from $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR."
    else
	echo "Library libsingly_linked_list.dylib could not be uninstalled from $SINGLY_LINKED_LIST_SHARED_LIB_INSTALL_DIR." 2>&1
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