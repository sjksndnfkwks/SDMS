cmake_minimum_required(VERSION 3.10)
project(Student_Management_System)

# Add directory for header files
include_directories(include)

# Add the executable
add_executable(main src/student.cpp src/deleteData.cpp src/viewData.cpp src/mainpage.cpp)

# Set executable output path
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)