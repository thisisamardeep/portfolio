cmake_minimum_required(VERSION 3.27)
project(blog)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "-O0 -fno-elide-constructors")
#SET(CMAKE_CXX_FLAGS "-O0")
set(CMAKE_VERBOSE_MAKEFILE ON)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_executable(blog blog.cpp)
#target_compile_options(blog PUBLIC -Wall -Wextra -Wpedantic -fno-elide-constructors -save-temps )
#target_compile_options(blog PUBLIC -Wall -Wextra -Wpedantic -fno-elide-constructors -save-temps )



add_executable(khud khud.cpp)
#target_compile_options(khud PUBLIC -Wall -Wextra -Wpedantic -fno-elide-constructors -save-temps )


