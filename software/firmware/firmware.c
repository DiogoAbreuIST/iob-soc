#include "system.h"
#include "periphs.h"
#include "iob-uart.h"
#include "iob-gpio.h"
#include "printf.h"
#define ARRAY_SIZE 64

char *send_string = "Sending this string as a file to console.\n"
                    "The file is then requested back from console.\n"
                    "The sent file is compared to the received file to confirm "
                    "correct file transfer via UART using console.\n"
                    "Generating the file in the firmware creates an uniform "
                    "file transfer between pc-emul, simulation and fpga without"
                    " adding extra targets for file generation.\n";

int main()
{

    // init uart
    uart_init(UART_BASE, FREQ / BAUD);

    // gpio start
    gpio_init(GPIO_BASE);
    

    uart_puts("\n\n\nHello world!\n");
    int loop;
    uint8_t array[ARRAY_SIZE];
    
    //5 arrays for test 
    
    if (IOB_GPIO_GET_SWITCH_REG() == 0)
    {
    uart_puts("\n\n\nArray 1\n\n\n");
    	uint8_t temp[ARRAY_SIZE] =  {8, 73, 93, 50, 36, 81, 49, 54, 95, 30, 87, 13, 52, 75, 39, 19, 76, 23, 3, 2, 63, 37, 10, 71, 94, 41, 6, 74, 43, 62, 77, 56, 69, 88, 22, 14, 90, 78, 27, 84, 51, 80, 89, 91, 55, 83, 21, 82, 33, 97, 47, 61, 67, 5, 35, 86, 79, 98, 70, 28, 18, 16, 17, 34};
    	for(loop = 0; loop < ARRAY_SIZE; loop++) 
    	{
      		array[loop] = temp[loop];
    	}
    }
    else if(IOB_GPIO_GET_SWITCH_REG() == 1)
    {
    uart_puts("\n\n\nArray 2\n\n\n");
    	uint8_t temp[ARRAY_SIZE] =  {99, 11, 78, 57, 4, 98, 83, 17, 65, 6, 74, 73, 72, 45, 46, 70, 3, 33, 64, 80, 22, 84, 55, 75, 37, 32, 42, 66, 26, 54, 7, 35, 34, 61, 97, 2, 90, 43, 31, 40, 76, 8, 10, 41, 9, 95, 81, 92, 82, 13, 14, 15, 79, 62, 38, 51, 47, 60, 16, 28, 18, 24, 53, 44};
    	for(loop = 0; loop < ARRAY_SIZE; loop++) 
    	{
      		array[loop] = temp[loop];
    	}	
    }
        else if(IOB_GPIO_GET_SWITCH_REG() == 2)
    {
    uart_puts("\n\n\nArray 3\n\n\n");;
    	uint8_t temp[ARRAY_SIZE] =  {89, 63, 7, 40, 4, 64, 9, 30, 42, 3, 6, 10, 13, 47, 88, 19, 1, 26, 76, 60, 11, 55, 91, 82, 80, 32, 46, 21, 27, 67, 48, 2, 84, 20, 38, 5, 81, 28, 87, 54, 8, 52, 73, 12, 96, 77, 31, 41, 43, 62, 24, 58, 25, 16, 92, 70, 49, 14, 78, 56, 33, 86, 34, 98};
    	for(loop = 0; loop < ARRAY_SIZE; loop++) 
    	{
      		array[loop] = temp[loop];
    	}
    }
        else if(IOB_GPIO_GET_SWITCH_REG() == 4)
    {
    uart_puts("\n\n\nArray 4\n\n\n");
    	uint8_t temp[ARRAY_SIZE] =  {73, 36, 96, 66, 20, 28, 77, 54, 51, 74, 22, 59, 55, 93, 38, 18, 90, 44, 53, 68, 64, 23, 76, 89, 65, 35, 56, 45, 25, 99, 60, 85, 88, 21, 63, 97, 42, 72, 92, 49, 4, 80, 82, 39, 14, 58, 70, 78, 52, 79, 84, 7, 11, 69, 71, 30, 16, 12, 40, 1, 10, 67, 34, 86};
    	for(loop = 0; loop < ARRAY_SIZE; loop++) 
    	{
      		array[loop] = temp[loop];
    	}
    }
        else if(IOB_GPIO_GET_SWITCH_REG() == 8)
    {
    uart_puts("\n\n\nArray 5\n\n\n");
    	uint8_t temp[ARRAY_SIZE] =  {24, 5, 86, 35, 66, 39, 62, 65, 16, 76, 90, 21, 40, 83, 4, 13, 46, 37, 12, 26, 25, 60, 1, 53, 70, 19, 6, 72, 67, 48, 22, 11, 50, 28, 23, 81, 3, 10, 95, 71, 57, 92, 9, 59, 2, 93, 20, 61, 89, 77, 18, 97, 75, 82, 17, 38, 33, 58, 43, 79, 99, 55, 87, 42};
    	for(loop = 0; loop < ARRAY_SIZE; loop++) 
    	{
      		array[loop] = temp[loop];
    	}
    }
    	else
    	{
    	uart_puts("\n\n\n Invalid array\n\n\n");	
    	}

    IOB_GPIO_SET_DATA_REG_RESET(1);
    IOB_GPIO_SET_DATA_REG_RESET(0);

    uint8_t x = 0;
    uint32_t *add;

    for (int c = 0; c < (ARRAY_SIZE / 4) ; c++)
    {
        add = array + c*4;
        IOB_GPIO_SET_DATA_REG (*add);
    }
    x = IOB_GPIO_GET_RESULT_REG();
        printf("value = %d \n", x);
    uart_finish();
}
