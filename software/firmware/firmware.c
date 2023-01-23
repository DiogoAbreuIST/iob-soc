#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "system.h"
#include "periphs.h"
#include "iob-uart.h"
#include "iob-gpio.h"
#include "printf.h"
#define ARRAY_SIZE 8

char *send_string = "Sending this string as a file to console.\n"
                    "The file is then requested back from console.\n"
                    "The sent file is compared to the received file to confirm "
                    "correct file transfer via UART using console.\n"
                    "Generating the file in the firmware creates an uniform "
                    "file transfer between pc-emul, simulation and fpga without"
                    " adding extra targets for file generation.\n";

// copy src to dst
// return number of copied chars (excluding '\0')
int string_copy(char *dst, char *src)
{
    if (dst == NULL || src == NULL)
    {
        return -1;
    }
    int cnt = 0;
    while (src[cnt] != 0)
    {
        dst[cnt] = src[cnt];
        cnt++;
    }
    dst[cnt] = '\0';
    return cnt;
}

// 0: same string
// otherwise: different
int compare_str(char *str1, char *str2, int str_size)
{
    int c = 0;
    while (c < str_size)
    {
        if (str1[c] != str2[c])
        {
            return str1[c] - str2[c];
        }
        c++;
    }
    return 0;
}

int main()
{

    srand(time(NULL));

    // init uart
    uart_init(UART_BASE, FREQ / BAUD);

    // gpio start
    gpio_init(GPIO_BASE);

    // int x = 0;
    // while(x=!1){
    // x = gpio_get();
    // }
    // print("%d \n",x)

    // test puts
    uart_puts("\n\n\nHello world!\n\n\n");
    int z = 0;
    uint8_t array[ARRAY_SIZE * ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE * ARRAY_SIZE; i++)
    {
            if (z == ARRAY_SIZE){
                 printf("\n");
                 z=0;
            }
            array[i] = rand() % 100;
            printf("%d ", array[i]);
            z++;
    }

    IOB_GPIO_SET_DATA_REG_RESET(1);
    IOB_GPIO_SET_DATA_REG_RESET(0);

    uint8_t x = 0;
    uint32_t *add;

    for (int c = 0; c < (ARRAY_SIZE * ARRAY_SIZE / 4) ; c++)
    {
        add = array + c*4;
        printf("adress: %d\n" , add);
        IOB_GPIO_SET_DATA_REG (*add);
        x = IOB_GPIO_GET_RESULT_REG();
        printf("value = %d \n", x);
    }

    /*
      //test printf with floats
      printf("Value of Pi = %f\n\n", 3.1415);

      //print fibonaci sequence

      int f0=0, f1=1, fout=0;
      int i;
      printf("Fibonaci sequence\n");
      printf("%d \n", f0);
      printf("%d \n", f1);

      for (i = 0; i <= 5; i++){
        fout = f0 + f1;
        printf("%d \n", fout);
        f0 = f1;
        f1 = fout;
        }


      //test file send
      char *sendfile = malloc(1000);
      int send_file_size = 0;
      send_file_size = string_copy(sendfile, send_string);
      uart_sendfile("Sendfile.txt", send_file_size, sendfile);

      //test file receive
      char *recvfile = malloc(10000);
      int file_size = 0;
      file_size = uart_recvfile("Sendfile.txt", recvfile);

      //compare files
      if (compare_str(sendfile, recvfile, send_file_size)) {
          printf("FAILURE: Send and received file differ!\n");
      } else {
          printf("SUCCESS: Send and received file match!\n");
      }

      free(sendfile);
      free(recvfile);
      */

    uart_finish();
}
