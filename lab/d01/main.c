#include <stdint.h>

volatile uint32_t *GPIOA_OUTPUT_VAL = (uint32_t*) 0x1001000CUL;
volatile uint32_t *GPIOA_INPUT_VAL  = (uint32_t*) 0x10010000UL;
volatile uint32_t *GPIOA_INPUT_EN   = (uint32_t*) 0x10010004UL;
volatile uint32_t *GPIOA_OUTPUT_EN  = (uint32_t*) 0x10010008UL;
volatile uint64_t *CLINT_MTIME      = (uint64_t*) 0x0200BFF8UL;

void delay(unsigned long ticks) {
  unsigned long mtime_start = *CLINT_MTIME;
  while (*CLINT_MTIME - mtime_start < ticks);
}

void main() {
    *GPIOA_OUTPUT_EN = 0b1;
    *GPIOA_INPUT_EN = 0b10;

    while (1) {
        if ((*GPIOA_INPUT_VAL & 0b10U)) {
            *GPIOA_OUTPUT_VAL = 0b1;
        } else {
            *GPIOA_OUTPUT_VAL = 0b0;
        }
    }
}

