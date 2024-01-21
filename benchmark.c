#include "pico/rand.h"
#include "pico/stdlib.h"
#include <fix_rfft.h>
#include <rfft.h>
#include <stdio.h>

void fixed_fft_benchmark()
{

    puts("-=-=-=-=-=-= Real FFT benchmark - fixed point =-=-=-=-=-=-");

    int l2n, n;
    int twiddle[2048];
    int data[2048];
    int bitrev[1024];

    puts("Generating sample data.");
    for (int i = 0; i < 2048; i++)
    {
        data[i] = (int)get_rand_32();
    }

    for (l2n = 3; l2n < 12; l2n++)
    {
        n = 1 << l2n;

        printf("%4d-points real-valued fixed-point FFT: ", n);
        precompute_bitrev_table_rfft_fix(bitrev, l2n);
        precompute_twiddle_factors_rfft_fix(twiddle, l2n);
        unsigned int start = time_us_32();
        for (int i = 0; i < 50; i++)
        {
            rfft_fix(data, l2n, twiddle, bitrev);
            irfft_fix(data, l2n, twiddle, bitrev);
        }
        unsigned int elapsed = time_us_32() - start;
        printf("%12.5fus per transform\n", (float)elapsed / 100);
    }
}

void fft_benchmark()
{

    puts("-=-=-=-=-=-= Real FFT benchmark - floating point =-=-=-=-=-=-");

    int l2n, n;
    float twiddle[2048];
    float data[2048];
    int bitrev[1024];

    puts("Generating sample data.");
    for (int i = 0; i < 2048; i++)
    {
        data[i] = (int)get_rand_32();
    }

    for (l2n = 3; l2n < 12; l2n++)
    {
        n = 1 << l2n;

        printf("%4d-points real-valued fixed-point FFT: ", n);
        precompute_bitrev_table_rfft(bitrev, n);
        precompute_twiddle_factors_rfft(twiddle, n);
        unsigned int start = time_us_32();
        for (int i = 0; i < 50; i++)
        {
            rfft(data, n, twiddle, bitrev);
            irfft(data, n, twiddle, bitrev);
        }
        unsigned int elapsed = time_us_32() - start;
        printf("%12.5fus per transform\n", (float)elapsed / 100);
    }
}
