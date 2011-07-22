About
-----
This is directory skeleton for writing c++ applications with help of
googletest (so, with [tdd](http://en.wikipedia.org/wiki/Test-driven_development) in mind).

How-to
------
First, edit the `./CMakeLists.txt` with your informations, and then start 
writing code. Make sure to put files in their dedicated directories (see 
"Project structure" for more information).

After you are done, cd into bin/ (`cd bin/`) directory and run `cmake ..`.
This should generate a Makefile. Running `make` inside `bin/` should then
generate `main` and `tests` binaries, which you can then run with `./main`
and `./tests`.

Project structure
-----------------
* .
  Directory should contain main.cc with main() function.
* inc/
  Directory containing *.h files
* src/
  Directory containing *.cc files.
* tests/
  Directory containing *_test.cc files for testing of classes.
  > these files should have `#include "gtest/gtest.h"` directive and are by
  > default linked with gtest_main, so that you do not have to specify a special
  > main() function for tests.
* bin/
  Directory containing binaries, generated with make.
