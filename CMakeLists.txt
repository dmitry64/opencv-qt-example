cmake_minimum_required(VERSION 3.1)

project(opencv-test)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} "main.cpp" "mainwindow.cpp" "mainwindow.h" "mainwindow.ui" "imageview.cpp" "imageview.h")

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets ${OpenCV_LIBS})
