cmake_minimum_required(VERSION 2.6)

#################################
########### EDIT HERE ###########

### Project information ###
set(VER_MAJOR "0")
set(VER_MINOR "0")
set(VER_PATCH "0")
project(ProjectName)

### Add or remove packages ###
set(CMAKE_CXX_FLAGS "-g -Wall -lglut -lGLU -lGL")

### Set the gtest location ###
set(GTEST_SRC /home/andr3/projects/cpp/gtest/gtest-1.6.0)

########### EDIT HERE ###########
#################################

set(VERSION "${VER_MAJOR}.${VER_MINOR}.${VER_PATCH}")
# So we can build outside of the main directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc ${CMAKE_CURRENT_SOURCE_DIR})

####################
## Begin building ##
####################

# Build tests
# Include all gtest files
include(${GTEST_SRC}/cmake/internal_utils.cmake)
config_compiler_and_linker()  # Defined in internal_utils.cmake.
include_directories(
  ${GTEST_SRC}/include
  ${GTEST_SRC})
link_directories(${gtest_BINARY_DIR}/src)

# Tell CMake about the libraries
cxx_library(gtest "${cxx_strict}" ${GTEST_SRC}/src/gtest-all.cc)
cxx_library(gtest_main "${cxx_strict}" ${GTEST_SRC}/src/gtest_main.cc)
target_link_libraries(gtest_main gtest)

# Tell CMake about source files
file(GLOB tests_SRC
  "tests/*.cc"
)
file(GLOB files_SRC
  "src/*.cc"
)

list(LENGTH files_SRC number_of_includes)
if(number_of_includes GREATER 0)
  add_executable(tests ${tests_SRC} ${files_SRC})
  target_link_libraries(tests gtest_main)
endif()


# Build the real deal
add_executable(main main.cc ${files_SRC})
