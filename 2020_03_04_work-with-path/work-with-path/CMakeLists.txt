# CMakeList.txt : CMake project for work-with-path, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.15)

project ("work-with-path")

if (MSVC)  #use utf-8 in msvc
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif ()

include_directories(../../include)

# Add source to this project's executable.
add_executable (work-with-path "main.cpp" "work-with-path.cpp" "work-with-path.h")

# TODO: Add tests and install targets if needed.
