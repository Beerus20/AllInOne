cmake_minimum_required(VERSION 3.10)
project(ImageViewerPlugin)

set(CMAKE_CXX_STANDARD 17)

# Source files
set(SOURCES
    ImageViewerPlugin.cpp
)

# Create shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# Installation
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION plugins
)
