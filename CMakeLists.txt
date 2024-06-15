cmake_minimum_required(VERSION 3.27)
project(blog)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps -finstrument-functions -O0 -Og -g3 -ggdb3 -Wpadded -fno-elide-constructors -fstandalone-debug")

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "-O0 -Og -g3 -ggdb3 -Wpadded -fno-elide-constructors -fstandalone-debug")
#SET(CMAKE_CXX_FLAGS "-O0 -fno-elide-constructors -ggdb3")
#SET(CMAKE_CXX_FLAGS "-O0")
set(CMAKE_VERBOSE_MAKEFILE ON)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_executable(blog blog.cpp)
#target_compile_options(blog PUBLIC -Wall -Wextra -Wpedantic -fno-elide-constructors -save-temps )
#target_compile_options(blog PUBLIC -Wall -Wextra -Wpedantic -fno-elide-constructors -save-temps )



add_executable(khud khud.cpp)
#target_compile_options(khud PUBLIC -Wall -Wextra -Wpedantic -fno-elide-constructors -save-temps )


