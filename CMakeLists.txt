# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/rafael/pico/pico-sdk")

set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(pico-fft-benchmark C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

add_subdirectory(simple-fft)
# Add executable. Default name is the project name, version 0.1

add_executable(pico-fft-benchmark 
    pico-fft-benchmark.c 
    benchmark.c
    simple-fft/testset/complex_fft_tests.c
    simple-fft/testset/real_fft_tests.c
    simple-fft/testset/utils_tests.c)

pico_set_program_name(pico-fft-benchmark "pico-fft-benchmark")
pico_set_program_version(pico-fft-benchmark "0.1")

pico_enable_stdio_uart(pico-fft-benchmark 1)
pico_enable_stdio_usb(pico-fft-benchmark 1)

# Add the standard library to the build
target_link_libraries(pico-fft-benchmark
        pico_stdlib
        pico_rand
        fixed-fft 
        float-fft)

# Add the standard include files to the build
target_include_directories(pico-fft-benchmark PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
  simple-fft/include
)

# Add any user requested libraries
target_link_libraries(pico-fft-benchmark 
        fixed-fft
        float-fft
        )

pico_add_extra_outputs(pico-fft-benchmark)

