
cmake_minimum_required (VERSION 3.10)
project(googletrans CXX)

add_library(google src/google.cpp)

add_executable(${PROJECT_NAME} main.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) # Include Conan-generated file
conan_basic_setup(TARGETS) # Introduce Conan-generated targets

# depending on your conan and cmake configuration, you may need to set the used ABI:
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)  # uncomment/add this line if the build fails or you get a runtime error

target_link_libraries(google CONAN_PKG::cpr)
target_link_libraries(${PROJECT_NAME} google)
