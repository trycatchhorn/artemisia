#!/bin/bash

# Debug
#set -ev

parent_path=$( cd "$(dirname "${BASH_SOURCE}")" ; pwd -P )
cd $parent_path

if [ -f "./../singly_linked_list/test/no_lib_test/build/debug/singly_linked_list_testd" ]; then
    ./../singly_linked_list/test/no_lib_test/build/debug/singly_linked_list_testd
fi

if [ -f "./../singly_linked_list/test/no_lib_test/build/release/singly_linked_list_test" ]; then
    ./../singly_linked_list/test/no_lib_test/build/release/singly_linked_list_test
fi

if [ -f "./../stack/test/no_lib_test/build/debug/stack_testd" ]; then
    ./../stack/test/no_lib_test/build/debug/stack_testd
fi

if [ -f "./../stack/test/no_lib_test/build/release/stack_test" ]; then
    ./../stack/test/no_lib_test/build/release/stack_test
fi

