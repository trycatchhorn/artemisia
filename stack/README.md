Intro
=====
The stack source provided here is part of the Artemisia library. Although, the stack project is
part of the Artemisia library, it is a self-contained API, which is build both as a static link 
library and as a shared dynamic library. Additionally, a small test suite is included showing 
how to use the stack API.

Compiling and building 
======================
The easiest way to build the source is to run 'make' in the root of the stack directory. This
will automatically compile and link everything related to the stack source. Additionally,
a static link library and a dynamic link library are build together with a small test suite. 

Directory structure
===================
The directory structure for the stack project follows the layout shown below. 

- __stack__
  - CHANGES.txt
  - Makefile
  - README.md
  - __include__
    - stack.h
  - __lib__
    - Makefile
    - __shared_lib__
      - Makefile
      - __build__
        - __debug__
          - libstackd.dylib
        - __release__
          - libstack.dylib
      - install.sh
      - uninstall.sh
    - __static_lib__
      - Makefile
      - __build__
        - __debug__
          - libstackd.a
        - __release__
          - libstack.a
  - __src__
    - Makefile
    - __build__
      - __debug__
        - stackd.o
      - __release__
        - stack.o
    - stack.c
  - __test__
    - Makefile
    - __lib_test__
      - Makefile
      - shared_lib_test
        - Makefile
        - __build__
          - __debug__
            - stack_test_shared_libd
            - stack_test_shared_libd.o
          - __release__
            - stack_test_shared_lib
            - stack_test_shared_lib.o
        - stack_test_shared_lib.c
      - static_lib_test
        - Makefile
        - __build__
          - __debug__
            - stack_test_static_libs
            - stack_test_static_libd.o
          - __release__
            - stack_test_static_lib
            - stack_test_static_lib.o
        - stack_test_static_lib.c
    - __no_lib_test__
      - Makefile
      - __build__
        - __debug__
          - stack_testd
          - stack_testd.o
        - __release__
          - stack_test
          - stack_test.o
      - stack_test.c