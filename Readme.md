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

## Results

The following table presents the benchmark results for a Raspberry Pi Pico running at 125MHz. It shows the time per transformation for fixed and floating-point operations at different numbers of data points (N).

|    N | Floating Point |   Fixed Point |
| ---: | -------------: | ------------: |
|    8 |     76.44&mu;s |     12.6&mu;s |
|   16 |    196.25&mu;s |    33.52&mu;s |
|   32 |    476.32&mu;s |    87.18&mu;s |
|   64 |   1110.21&mu;s |   215.32&mu;s |
|  128 |   2529.58&mu;s |   516.06&mu;s |
|  256 |   5666.06&mu;s |  1203.62&mu;s |
|  512 |  12545.85&mu;s |  2754.44&mu;s |
| 1024 |  27511.37&mu;s |  6202.91&mu;s |
| 2048 |  59864.60&mu;s | 13799.99&mu;s |

The results at 200MHz show a linear reduction in the time per transformation with the increase in clock frequency.

|    N | Floating Point |  Fixed Point |
| ---: | -------------: | -----------: |
|    8 |     47.89&mu;s |    7.76&mu;s |
|   16 |    122.92&mu;s |   21.06&mu;s |
|   32 |    297.33&mu;s |   54.47&mu;s |
|   64 |    694.42&mu;s |  134.71&mu;s |
|  128 |   1579.52&mu;s |  322.59&mu;s |
|  256 |   3542.20&mu;s |  752.28&mu;s |
|  512 |   7839.84&mu;s | 1721.59&mu;s |
| 1024 |  17199.68&mu;s | 3876.85&mu;s |
| 2048 |  37417.36&mu;s | 8625.00&mu;s |

UPDATE: Here are the benchmark results for the new RP2350 processor running at 200MHz. It's worth noting that my [simple_fft](https://github.com/RafaelGCPP/simple_fft) library doesn't explicitly utilize the DSP and FPU instructions of the Cortex-M33 core, but relies on the GCC compiler to generate them. Despite this, the performance improvement is quite impressive.

|    N | Floating Point |  Fixed Point |
| ---: | -------------: | -----------: |
|    8 |      2.56&mu;s |    2.90&mu;s |
|   16 |      5.33&mu;s |    6.34&mu;s |
|   32 |     11.62&mu;s |   14.44&mu;s |
|   64 |     25.75&mu;s |   32.89&mu;s |
|  128 |     57.13&mu;s |   74.65&mu;s |
|  256 |    126.11&mu;s |  167.73&mu;s |
|  512 |    276.94&mu;s |  373.65&mu;s |
| 1024 |    603.82&mu;s |  824.42&mu;s |
| 2048 |   1309.23&mu;s | 1805.07&mu;s |
