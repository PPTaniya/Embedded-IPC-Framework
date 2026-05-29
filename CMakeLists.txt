cmake_minimum_required(VERSION 3.16)

project(EmbeddedIPCFramework)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE SRC_FILES
    src/*.cpp
)

add_library(ipcframework SHARED ${SRC_FILES})

target_link_libraries(ipcframework
    pthread
    rt
)

# Applications

add_executable(sensor_service apps/sensor_service.cpp)
target_link_libraries(sensor_service ipcframework)

add_executable(dashboard_client apps/dashboard_client.cpp)
target_link_libraries(dashboard_client ipcframework)

add_executable(logger_service apps/logger_service.cpp)
target_link_libraries(logger_service ipcframework)

add_executable(ecu_gateway apps/ecu_gateway.cpp)
target_link_libraries(ecu_gateway ipcframework)
