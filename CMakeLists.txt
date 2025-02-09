cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Youdith)
# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable
add_executable(Youdith src/main.cpp)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

#cmake ..  
#cmake --build .