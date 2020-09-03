cmake_minimum_required(VERSION 3.10)
project(Sorting_Vis)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

if (WIN32)
set(CMAKE_PREFIX_PATH  "C:/Qt/5.15.0/mingw81_64/lib/cmake")
endif(WIN32)

find_package(Qt5Widgets REQUIRED)

add_executable(Sorting_Vis main.cpp BubbleSort.h ArrayCB.cpp ArrayCB.h MainWindow.cpp MainWindow.h RenderArea.cpp RenderArea.h)

target_link_libraries(Sorting_Vis Qt5::Widgets)
