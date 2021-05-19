cmake_minimum_required(VERSION 3.16)
project(piapp)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR armv8)
# set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
# set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)
set(PAHO_C_LIB paho-mqtt3as)
set(PAHO_CPP_LIB paho-mqttpp3)

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/inc)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/src/main.cpp)

target_compile_options(${PROJECT_NAME} PUBLIC
    -O2 -Wall)
target_link_libraries(${PROJECT_NAME}
    ${Boost_LIBRARIES}
    ${PAHO_C_LIB}
    ${PAHO_CPP_LIB})

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
