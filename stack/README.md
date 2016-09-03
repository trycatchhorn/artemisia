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
      - ____shared___lib___test
        - Makefile
        - __build__
          - __debug__
            - ____stack___test___shared__libd
            - ____stack___test___shared__libd.o
          - __release__
            - ____stack___test___shared__lib
            - ____stack___test___shared__lib.o
        - ____stack___test___shared__lib.c
      - ____static___lib___test
        - Makefile
        - __build__
          - __debug__
            - ____stack___test___static__libs
            - ____stack___test___static__libd.o
          - __release__
            - ____stack___test___static__lib
            - ____stack___test___static_lib.o
        - ____stack___test____static_lib.c
    - ____no___lib___test
      - Makefile
      - __build__
        - __debug__
          - stack_testd
          - stack_testd.o
        - __release__
          - stack_test
          - stack_test.o
      - stack_test.c