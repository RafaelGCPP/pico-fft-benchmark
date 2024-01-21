#include <stdio.h>
#include "pico/stdlib.h"
#include "../testset/test_set.h"
#include "benchmark.h"
#include "hardware/clocks.h"

int main()
{
    stdio_init_all();
start:
    sleep_ms(10000);

    putchar(12); // FF - clears screen

    set_sys_clock_khz(200000, true);
    printf("Current clock speed: %6.2f MHz\n", (float)clock_get_hz(clk_sys) / 1000000);
    sleep_ms(2000);

    cordic_test();
    twiddle_test();
    fix_twiddle_test();
    complex_fft_test();
    real_fft_test();
    complex_fft_test_fix();
    real_fft_test_fix();

    fft_benchmark();
    fixed_fft_benchmark();

    puts("Testing restarts in 10 seconds.");
    goto start;

    return 0;
}
