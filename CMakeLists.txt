cmake_minimum_required(VERSION 3.17)
project(ADS2_PJ1)

set(CMAKE_CXX_STANDARD 20)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(ADS2_PJ1 main.cpp Gui/MainWindow.cpp Gui/MainWindow.h Node/Node.cpp Node/Node.h)
target_link_libraries(ADS2_PJ1 ${GTKMM_LIBRARIES})