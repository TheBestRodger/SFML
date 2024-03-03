cmake_minimum_required(VERSION 3.25)
project(SFML)

set(MPROJECT_VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(settings.cmake)

find_package(SFML 2.6.1 COMPONENTS graphics audio REQUIRED)
include_directories(${INCLUDE_PATH})

# Making file groups#
file(GLOB_RECURSE   HEADER     ${INCLUDE_PATH}/*.h*)

file(GLOB_RECURSE   SOURCE     ${SOURCE_PATH}/*.c*)


add_executable(SFML ${HEADER} ${SOURCE})

target_link_libraries(SFML sfml-graphics sfml-audio)
#set_target_properties(SFML PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE" LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")