cmake_minimum_required(VERSION 3.0.0)
project(CAR VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(CAR main.cpp motor.cpp hardware.cpp)
# Make sure the executable links to the wiringPi lib
target_link_libraries(CAR wiringPi)
target_link_libraries(CAR bcm2835)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 11)
include(CPack)
