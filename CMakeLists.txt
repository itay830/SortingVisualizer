cmake_minimum_required(VERSION 4.1)
project(SortingVisualizer)

set(CMAKE_CXX_STANDARD 20)

add_executable(SortingVisualizer main.cpp
        src/Simulation.cpp
        include/Simulation.h
        src/SortingVisualizer.cpp
        include/SortingVisualizer.h
        src/SortingMethod.cpp
        include/SortingMethod.h
        src/sortingMethods/BubbleSort.cpp
        include/sortingMethods/BubbleSort.h
        src/drawingMethods/ColumnsDrawingMethod.cpp
        include/drawingMethods/ColumnsDrawingMethod.h
        src/DrawingMethod.cpp
        include/DrawingMethod.h
)

find_package(raylib CONFIG REQUIRED)
target_link_libraries(SortingVisualizer PRIVATE raylib)


