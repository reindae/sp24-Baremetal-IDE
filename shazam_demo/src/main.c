/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include "chip_config.h"
#include "hal_DMA.h"
#include "hal_fft.h"
#include "meep.h"
//#include "tone_samples.h"
#define DMA_ADDR1 0x87000000L


// WAV file header structure
struct WAVHeader {
    char chunkID[4];   // Should be "RIFF"
    uint32_t chunkSize;
    char format[4];    // Should be "WAVEID"
    char junk[72];
    char subchunk1ID[4]; // Should be "fmt "
    uint32_t subchunk1Size;
    uint16_t audioFormat; // Usually 1 for PCM
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    char subchunk2ID[4]; // Should be "data"
    uint32_t subchunk2Size; // Size of audio data
};

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */


/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN PUC */


void app_init() {
  // torch::executor::runtime_init();
}





void app_main(uint32_t* data) {
  uint64_t mhartid = READ_CSR("mhartid");

    printf("\n[STARTING TEST]\n\n");

    reset_fft();
    enable_Crack();

    write_fft_dma(1, 128, data);
    uint64_t start_time = READ_CSR("mcycle");
    uint64_t start_instructions = READ_CSR("minstret");

    while(fft_busy() || fft_count_left()) {
      continue;
        printf("pain:%d, %d \n", fft_busy(), fft_count_left());
    }; // This is needed since fft is blocking and is not a very good block

    uint64_t end_time = READ_CSR("mcycle");
    uint64_t end_instructions = READ_CSR("minstret");

    printf("[DONE] Waiting Write\n");
    printf("mcycle = %lu\r\n", end_time - start_time);
    printf("minstret = %lu\r\n", end_instructions - start_instructions);
    read_fft_dma(1, 128, 0x08000000U);
    
    for (int i = 0; i < 128; i++) {
      printf("%d\r\n", (uint32_t*) 0x08000000U + 4*i);
    }

    printf("Starting CPU FFT\r\n");
    float* result_real;
    float* result_imag;
    fft1d((float*) data, 128, result_real, result_imag);

    for (int i = 0; i < 128; i += 1) {
      printf("Real index %d: %d\r\n", i, (float*) (result_real + i));
      printf("Real index %d: %d\r\n", i, (float*) (result_imag + i));
    }
    
    // uint32_t poll, real, imag;
    // for(int i=0; i<512; i++) {
    //     poll = reg_read32(DMA_ADDR1 + i*8);
    //     real = poll & 0xFFFF; 
    //     imag = (poll >> 16);
    //     printf("[%d]real: (%hd), imag: (%hd)\n", i, real, imag);
    // }
    // for(int i=0; i<256; i++) {
    //     poll = reg_read16(DMA_ADDR1 + i*4);
    //     printf("[%d]real: (%hd)\n", i, poll);
    // }
    
    printf("[DONE] Test\n");

}
/* USER CODE END PUC */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(int argc, char **argv) {
  /* MCU Configuration--------------------------------------------------------*/

  /* Configure the system clock */
  /* Configure the system clock */

  // if (argc != 2) {
  //       fprintf(stderr, "Usage: %s <wav_file>\n", argv[0]);
  //       return 1;
  //   }

  //   FILE *fp = fopen("twinkle_twinkle_as.wav", "rb");
  //   if (fp == NULL) {
  //       perror("Error opening file");
  //       return 1;
  //   }

  UART_InitType UART_init_config;
  UART_init_config.baudrate = 115200;
  UART_init_config.mode = UART_MODE_TX_RX;
  UART_init_config.stopbits = UART_STOPBITS_2;
  uart_init(UART0, &UART_init_config);

  struct WAVHeader* header = &HEADER;
  //fread(&header, sizeof(header), 1, fp);

  // Check if it's a valid WAV file
  if (strncmp(header->chunkID, "RIFF", 4) != 0 ||
      strncmp(header->format, "WAVE", 4) != 0) {
      fprintf(stderr, "Invalid WAV file\n");
      
      return 1;
  }

  printf("Channels: %u\r\n", header->numChannels);
  printf("Sample Rate: %u\r\n", header->sampleRate);
  printf("Bits per Sample: %u\r\n", header->bitsPerSample);

  // Read audio data
  uint32_t *data = header + sizeof(struct WAVHeader);
  printf("header size: %u\r\n", header->subchunk2Size);
  

  // Process the audio data here

  
  
  /* USER CODE BEGIN SysInit */
  // UART_InitType UART_init_config;
  // UART_init_config.baudrate = 115200;
  // UART_init_config.mode = UART_MODE_TX_RX;
  // UART_init_config.stopbits = UART_STOPBITS_2;
  // uart_init(UART0, &UART_init_config);
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */  
  /* USER CODE BEGIN Init */
  app_init();
  /* USER CODE END Init */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1) {
    app_main(data);
    return 0;
  }
  /* USER CODE END WHILE */
}

/*
 * Main function for secondary harts
 * 
 * Multi-threaded programs should provide their own implementation.
 */
void __attribute__((weak, noreturn)) __main(void) {
  while (1) {
   asm volatile ("wfi");
  }
}

// Naive implementation using little vectorization to get something going
void fft1d(float* samples, size_t N, float* result_real, float* result_imag) {
  if (N == 1) {
    return samples;
  }

  // float even[N / 2];
  // float odd[N / 2];
  float* even = (float*)malloc((N / 2) * sizeof(float));
  float* odd = (float*)malloc((N / 2) * sizeof(float));


  int evenIndex = 0;
  int oddIndex = 0;
  for (int i = 0; i < N; i += 1) {
    if ((i % 2) == 0) {
      even[evenIndex] = samples[i];
      evenIndex += 1;
    } else {
      odd[oddIndex] = samples[i];
      oddIndex += 1;
    }
  }

  float *real_twiddle;
  float *imag_twiddle;
  fft1d(even, N / 2, result_real, result_imag);
  fft1d(odd, N / 2, result_real, result_imag);

  // float real_twiddles[N];
  // float imag_twiddles[N];
  for (int i = 0; i < N; i += 1) {
    computeTwiddle(N, i, real_twiddle, imag_twiddle);
    // real_twiddles[i] = *real_twiddle;
    // imag_twiddles[i] = *imag_twiddle;
    result_real[i] = even[i % (N / 2)] + (*real_twiddle) * odd[i % (N / 2)];
    result_imag[i] = even[i % (N / 2)] + (*imag_twiddle) * odd[i % (N / 2)];
  }

}

void computeTwiddle(int N, int k, double *real, double *imag) {
    // Calculate the angle for the twiddle factor
    double angle = -(TWO_PI) * k / N;
    
    // Compute the real and imaginary parts of the twiddle factor
    *real = cos(angle);  // Real part: cos(2 * pi * k / N)
    *imag = sin(angle);  // Imaginary part: -sin(2 * pi * k / N)
}
