cmake_minimum_required(VERSION 3.16)
project(conan-test)
#[[

set(CONAN_CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
target_link_libraries(conan_test ${CONAN_LIBS})
]]
# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

#conan_cmake_run(REQUIRES catch2@catchorg/stable BASIC_SETUP)
conan_cmake_run( BASIC_SETUP)


add_executable(conan_test main.cpp)
target_link_libraries(conan_test ${CONAN_LIBS})



