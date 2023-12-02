# 判断系统是linux还是windows
if(WIN32)
    message("windows")
    cmake_minimum_required(VERSION 3.28.0-rc4)
    project(test_win)
else()
    message("linux")
    cmake_minimum_required(VERSION 3.22.1)
    project(test_linux)
endif()

include(CTest)
enable_testing()

file(GLOB SRC_LIST ${PROJECT_SOURCE_DIR}/src/*.c)
include_directories(${PROJECT_SOURCE_DIR}/inc)
# 指定执行文件输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pthread  -fdiagnostics-color  -std=c17")

# 使用gcc命令
set(CMAKE_C_COMPILER gcc)

add_executable(${PROJECT_NAME} ${SRC_LIST})
