cmake_minimum_required(VERSION 3.10)
project(Sorting_Vis)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread -lboost_thread")

if (WIN32)
set(CMAKE_PREFIX_PATH  "C:/Qt/5.15.0/mingw81_64/lib/cmake")
endif(WIN32)

find_package(Qt5Widgets REQUIRED)
find_package(Boost COMPONENTS thread system chrono REQUIRED)

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_executable(Sorting_Vis main.cpp "Sorting-Algorithms/BubbleSort.h" util/ArrayCB.cpp util/ArrayCB.h Window/MainWindow.cpp Window/MainWindow.h Window/RenderArea.cpp Window/RenderArea.h "Sorting-Algorithms/InsertionSort.h" "Sorting-Algorithms/sort.h")

target_link_libraries(Sorting_Vis Qt5::Widgets)
TARGET_LINK_LIBRARIES( Sorting_Vis ${Boost_LIBRARIES} )

