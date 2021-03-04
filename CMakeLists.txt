add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)

project(main)
file(GLOB main_src CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")
add_executable (main ${main_src})