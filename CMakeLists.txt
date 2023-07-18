cmake_minimum_required(VERSION 3.25)

project(minesweeper VERSION 0.1)

option(SPACE_INVADERS_TESTS "Build and register unit tests" ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE BOOL "" FORCE)
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

include(project_init)

#
# conan
#

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(
        STATUS
            "Downloading conan.cmake from https://github.com/conan-io/cmake-conan"
        )
    file(
        DOWNLOAD
        "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
        "${CMAKE_BINARY_DIR}/conan.cmake"
        TLS_VERIFY ON)
endif()

include(conan)

conan_cmake_configure(
    REQUIRES
    catch2/2.13.10
    eigen/3.4.0
    ftxui/4.1.1
    ncurses/6.4
    sdl/2.26.5
    GENERATORS
    CMakeToolchain
    CMakeDeps)
conan_cmake_autodetect(CONAN_SETTINGS)
conan_cmake_install(
    PATH_OR_REFERENCE
    .
    BUILD
    missing
    REMOTE
    conancenter
    SETTINGS
    ${CONAN_SETTINGS})

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

#
# subdirs
#

if(SPACE_INVADERS_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
add_subdirectory(game)
add_subdirectory(render)
add_subdirectory(app)
