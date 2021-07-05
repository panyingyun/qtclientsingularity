# Reference: http://qt-project.org/doc/qt-5.0/qtdoc/cmake-manual.html

cmake_minimum_required(VERSION 3.0)

# Add folder where are supportive functions
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Include Qt basic functions
include(QtCommon)

# Basic information about project

project(qtclient VERSION 1.0)

# Set PROJECT_VERSION_PATCH and PROJECT_VERSION_TWEAK to 0 if not present, needed by add_project_meta
fix_project_version()

# Set additional project information
set(COMPANY "qtclient")
set(COPYRIGHT "Copyright (c) 2020~2100 Michael Pan. All rights reserved.")
set(IDENTIFIER "com.michaelapp.qtclient")

set(SOURCE_FILES
    src/main.cpp
	src/mainwindow.h
    src/mainwindow.cpp
	src/mainwindow.ui
	src/json.h
	src/httpbody.h
)

# source_group("UI Files" FILES ${UI_FILES})

set(RESOURCE_FILES qtclient.qrc)

add_project_meta(META_FILES_TO_INCLUDE)

find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Gui)
find_package(Qt5Network)

add_executable(${PROJECT_NAME} ${OS_BUNDLE} # Expands to WIN32 or MACOS_BUNDLE depending on OS
    ${SOURCE_FILES} ${META_FILES_TO_INCLUDE} ${RESOURCE_FILES}
)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Network)
