# pico-fft-benchmark

This repository contains a benchmark for my [simple_fft](https://github.com/RafaelGCPP/simple_fft) library running on the Raspberry Pi Pico.

## Installation

To run the benchmark, you'll need to have the following prerequisites:

- Raspberry Pi Pico board
- simple-fft library

Follow these steps to install and run the benchmark:

1. Clone this repository:

    ```shell
    git clone --recursive https://github.com/your-username/pico-fft-benchmark.git
    ```

2. Connect your Raspberry Pi Pico board to your computer.

3. Build and flash the benchmark code to your Raspberry Pi Pico using your preferred development environment.

    ```cd pico-fft-benchmark
    mkdir build
    cd build
    cmake ..
    make
    ```


## Usage

Once the benchmark code is flashed to your Raspberry Pi Pico, you can run the benchmark by following these steps:

1. Power on your Raspberry Pi Pico.

2. Open a serial terminal to view the benchmark results.

3. The benchmark will run and display the performance metrics on the serial terminal.
4. The tests will restart automatically after 10 seconds.

