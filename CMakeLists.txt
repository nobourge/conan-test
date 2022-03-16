cmake_minimum_required(VERSION 3.16)
project(conan-test)


set(CONAN_CMAKE_CXX_STANDARD 20)
#[[
CMake Error at cmake-build-debug/conanbuildinfo.cmake:404 (message):
  Detected a mismatch for the compiler version between your conan profile
  settings and CMake:

  Compiler version specified in your conan profile: 8

  Compiler version detected in CMake: 9.4

  Please check your conan profile settings (conan profile show
  [default|your_profile_name])

  P.S.  You may set CONAN_DISABLE_CHECK_COMPILER CMake variable in order to
  disable this check.
  ]]
set(CONAN_DISABLE_CHECK_COMPILER true)
message(STATUS "CONAN_DISABLE_CHECK_COMPILER")

#[[
#todo
# conan package manager automatic Download
if(NOT EXISTS "${HOME}/conan")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
    sudo apt-get install pip
    pip install conan
endif()
]]

# Download automatic conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")

endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_configure(REQUIRES
        fmt/6.1.2
        boost/1.73.0
        poco/1.11.1

        GENERATORS cmake_find_package)

conan_cmake_autodetect(settings)

#conan install : Installs the requirements specified in a recipe (conanfile.py or conanfile.txt).
#conan_cmake_install is a wrapper for conan install
conan_cmake_install(PATH_OR_REFERENCE .
        BUILD missing
        REMOTE conancenter
        SETTINGS ${settings})

set(CMAKE_MODULE_PATH /home/noe/Github/conan-test/cmake-build-debug)

find_package(fmt)

add_executable(main main.cpp)
#target_link_libraries(main fmt::fmt)
target_link_libraries(main ${CONAN_LIBS})

#[[
cmake_minimum_required(VERSION 2.8)
project(myproject CXX)

# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(REQUIRES Catch2/2.6.0@catchorg/stable
        BASIC_SETUP)

add_executable(main main.cpp)
target_link_libraries(main ${CONAN_LIBS})
]]