cmake_minimum_required(VERSION 3.14)
project(dz1 C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(weatherLib)

message("WEATHER_LIB_INCLUDE_DIRS = ${WEATHER_LIB_INCLUDE_DIRS}")
message("WEATHER_LIB_LIBRARIES = ${WEATHER_LIB_LIBRARIES}")

add_executable(${PROJECT_NAME} main.c)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

target_include_directories(${PROJECT_NAME} PUBLIC ${WEATHER_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${WEATHER_LIB_LIBRARIES})

add_subdirectory(tests)

