INTRO
#####
The stack source provided here is part of the Artemisia library. Although, the stack project is
part of the Artemisia library, it is a self-contained API, which is build both as a static link 
library and as a shared dynamic library. Additionally, a small test suite is included showing 
how to use the stack API.

COMPILING AND BUILDING THE SOURCE
#################################
The easiest way to build the source is to run 'make' in the root of the stack directory. This
will automatically compile and link everything related to the stack source. Additionally,
a static link library and a dynamic link library are build together with a small test suite. 

DIRECTORY STRUCTURE
###################
The directory structure for the stack project follows the layout shown below. 

- __stack__
  - [CHANGES.txt](stack/CHANGES.txt)
  - [Makefile](stack/Makefile)
  - [README.md](stack/README.md)
  - __include__
    - [stack.h](stack/include/stack.h)
  - __lib__
    - [Makefile](stack/lib/Makefile)
    - __shared_lib__
      - [Makefile](stack/lib/shared_lib/Makefile)
      - __build__
        - __debug__
          - [libstackd.dylib](stack/lib/shared_lib/build/debug/libstackd.dylib)
        - __release__
          - [libstack.dylib](stack/lib/shared_lib/build/release/libstack.dylib)
      - [install.sh](stack/lib/shared_lib/install.sh)
      - [uninstall.sh](stack/lib/shared_lib/uninstall.sh)
    - __static_lib__
      - [Makefile](stack/lib/static_lib/Makefile)
      - __build__
        - __debug__
          - [libstackd.a](stack/lib/static_lib/build/debug/libstackd.a)
        - __release__
          - [libstack.a](stack/lib/static_lib/build/release/libstack.a)
  - __src__
    - [Makefile](stack/src/Makefile)
    - __build__
      - __debug__
        - [stackd.o](stack/src/build/debug/stackd.o)
      - __release__
        - [stack.o](stack/src/build/release/stack.o)
    - [stack.c](stack/src/stack.c)
  - __test__
    - [Makefile](stack/test/Makefile)
    - __lib_test__
      - [Makefile](stack/test/lib_test/Makefile)
      - __shared_lib_test__
        - [Makefile](stack/test/lib_test/shared_lib_test/Makefile)
        - __build__
          - __debug__
            - [stack_test_shared_libd](stack/test/lib_test/shared_lib_test/build/debug/stack_test_shared_libd)
            - [stack_test_shared_libd.o](stack/test/lib_test/shared_lib_test/build/debug/stack_test_shared_libd.o)
          - __release__
            - [stack_test_shared_lib](stack/test/lib_test/shared_lib_test/build/release/stack_test_shared_lib)
            - [stack_test_shared_lib.o](stack/test/lib_test/shared_lib_test/build/release/stack_test_shared_lib.o)
        - [stack_test_shared_lib.c](stack/test/lib_test/shared_lib_test/stack_test_shared_lib.c)
      - __static_lib_test__
        - [Makefile](stack/test/lib_test/static_lib_test/Makefile)
        - __build__
          - __debug__
            - [stack_test_static_libd](stack/test/lib_test/static_lib_test/build/debug/stack_test_static_libd)
            - [stack_test_static_libd.o](stack/test/lib_test/static_lib_test/build/debug/stack_test_static_libd.o)
          - __release__
            - [stack_test_static_lib](stack/test/lib_test/static_lib_test/build/release/stack_test_static_lib)
            - [stack_test_static_lib.o](stack/test/lib_test/static_lib_test/build/release/stack_test_static_lib.o)
        - [stack_test_static_lib.c](stack/test/lib_test/static_lib_test/stack_test_static_lib.c)
    - __no_lib_test__
      - [Makefile](stack/test/no_lib_test/Makefile)
      - __build__
        - __debug__
          - [stack_testd](stack/test/no_lib_test/build/debug/stack_testd)
          - [stack_testd.o](stack/test/no_lib_test/build/debug/stack_testd.o)
        - __release__
          - [stack_test](stack/test/no_lib_test/build/release/stack_test)
          - [stack_test.o](stack/test/no_lib_test/build/release/stack_test.o)
      - [stack_test.c](stack/test/no_lib_test/stack_test.c)