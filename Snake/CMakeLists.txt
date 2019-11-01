cmake_minimum_required(VERSION 2.8)

project(Game)
include_directories(inc)

file(GLOB SOURCES "src/*.cpp"
                   "inc/*.hpp")


# Define sources and executable
set(EXECUTABLE_NAME "platformer")
add_executable(${EXECUTABLE_NAME} ${SOURCES})
set(CMAKE_MODULE_PATH "/home/student/Pulpit/Projekt/Snake/SFML-2.4.2/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
