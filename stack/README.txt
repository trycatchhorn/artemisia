
CODENAME: Artemisia

#################################################################################################
# INTRO												#
#################################################################################################
The stack source provided here is part of the Artemisia library. Although, the stack project is
part of the Artemisia library, it is a self-contained API, which is build both as a static link 
library and as a shared dynamic library. Additionally, a small test suite is included showing 
how to use the stack API.

#################################################################################################
# COMPILING AND BUILDING THE SOURCE								#
#################################################################################################

The easiest way to build the source is to run 'make' in the root of the stack directory. This
will automatically compile and link everything related to the stack source. Additionally,
a static link library and a dynamic link library are build together with a small test suite. 

#################################################################################################
# DIRECTORY STRUCTURE										#
#################################################################################################

The directory structure for the stack project follows the layout shown below. 

+- stack/
|  |
|  +- Makefile
|  |
|  +- README.txt
|  |
|  +- CHANGES.txt
|  |
|  +- src/
|  |  |
|  |  +- Makefile
|  |  |
|  |  +- stack.c
|  |  |
|  |  +- build/
|  |  |	 |
|  |  |	 +- debug/
|  |  |	 |  |
|  |  |	 |  +- stackd.o
|  |  |	 |  |
|  |  |	 +- release/
|  |  |	 |  |
|  |  |	 |  +- stack.o
|  |
|  +- include/
|  |  |
|  |  +- stack.h
|  |  |
|  +- lib/
|  |  |
|  |  +- Makefile
|  |  |
|  |  +- shared_lib/
|  |  |	 |
|  |  |	 +- Makefile
|  |  |	 |
|  |  |	 +- install.sh
|  |  |	 |
|  |  |	 +- uninstall.sh
|  |  |	 |
|  |  |	 +- build/
|  |  |	 |  |
|  |  |	 |  +- debug/
|  |  |	 |  |  |
|  |  |	 |  |  +- libstackd.dylib
|  |  |	 |  |  |
|  |  |	 |  +- release/
|  |  |	 |  |  |
|  |  |	 |  |  +- libstack.dylib
|  |  |	 |  |  |
|  |  +- static_lib/
|  |  |	 |
|  |  |	 +- Makefile
|  |  |	 |
|  |  |	 +- build/
|  |  |	 |  |
|  |  |	 |  +- debug/
|  |  |	 |  |  |
|  |  |	 |  |  +- libstackd.a
|  |  |	 |  |  |
|  |  |	 |  +- release/
|  |  |	 |  |  |
|  |  |	 |  |  +- libstack.a
|  |
|  +- test/
|  |  |
|  |  +- Makefile
|  |  |
|  |  +- lib_test/
|  |  |	 |
|  |  |	 +- Makefile
|  |  |	 |
|  |  |  +- shared_lib_test/
|  |  |	 |  |
|  |  |	 |  +- Makefile
|  |  |	 |  |
|  |  |  |  +- build/
|  |  |	 |  |  |
|  |  |  |  |  +- debug/
|  |  |	 |  |  |  |
|  |  |  |  |  |  +- stack_test_shared_libd
|  |  |	 |  |  |  |
|  |  |  |  |  +- release/
|  |  |	 |  |  |  |
|  |  |  |  |  |  +- stack_test_shared_lib
|  |  |	 |  |  |  |
|  |  |  +- static_lib_test/
|  |  |	 |  |
|  |  |	 |  +- Makefile
|  |  |	 |  |
|  |  |  |  +- build/
|  |  |	 |  |  |
|  |  |  |  |  +- debug/
|  |  |	 |  |  |  |
|  |  |  |  |  |  +- stack_test_static_libd
|  |  |	 |  |  |  |
|  |  |  |  |  +- release/
|  |  |	 |  |  |  |
|  |  |  |  |  |  +- stack_test_static_lib
|  |  |	 |  |  |  |
|  |  +- no_lib_test/
|  |  |	 |
|  |  |	 +- Makefile
|  |  |	 |
|  |  |  +- build/
|  |  |	 |  |
|  |  |  |  +- debug/
|  |  |	 |  |  |
|  |  |  |  |  +- stack_testd
|  |  |	 |  |  |
|  |  |  |  +- release/
|  |  |	 |  |  |
|  |  |  |  |  +- stack_test
