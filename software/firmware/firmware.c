#include "firmware.h"

void disp_num(int number);
int sel_array();

int main() {
  
  uart_init(UART_BASE, FREQ / BAUD);
  
  gpio_init(GPIO_BASE);
    
  timer_init(TIMER_BASE);
		    
  int loop, current_time = 0, digit1 = 0, digit2 = 0;
  int count = 0, array_size = 0;
  uint8_t x = 0, soft_max = 0;
  uint8_t *add_soft;
  uint32_t *add;

  uart_puts("\n\n--- GPIO Max value finder ---\n\n");
  uart_puts("Switches used:\nSW6 to Sw0: Select Array\nSW10: Hold Mode\n\nRunning...\n\n");
  
  while (true){   
    while((IOB_GPIO_GET_SWITCH_REG() & 0x400) == 1024){
      IOB_GPIO_SET_DISP_AN(0xE);
      IOB_GPIO_SET_DISP_CA(0x7E);
      IOB_GPIO_SET_DISP_AN(0xD);
      IOB_GPIO_SET_DISP_CA(0x7E);
      if((IOB_GPIO_GET_SWITCH_REG() & 0x400) == 0) break;
    }
    
    array_size = sel_array();
    
    IOB_GPIO_SET_DATA_REG_RESET(0xFF);
    IOB_GPIO_SET_DATA_REG_RESET(0x0);

    for (int c = 0; c < (array_size / 4) ; c++){
      switch(array_size){
      case 64: 
	add = array1 + c*4;
	break;
      case 128: 
	add = array2 + c*4;
	break;     
      case 256: 
	add = array3 + c*4;
	break;
      case 512: 
	add = array4 + c*4;
	break;
      case 1024: 
	add = array5 + c*4;
	break;
      case 2048: 
	add = array6 + c*4;
	break;
      case 4096: 
	add = array7 + c*4;
	break;
      default:
	add = array0 + c*4;
	break;
      }        
      IOB_GPIO_SET_DATA_REG (*add);
    }
    x = IOB_GPIO_GET_RESULT_REG();

    digit1 = x%10;
    digit2 = x/10;

    current_time = timer_time_ms();
    while((IOB_GPIO_GET_SWITCH_REG() & 0x400) == 0){
      if (timer_time_ms() >= current_time+2){
	    	
	if (count == 0){
	  IOB_GPIO_SET_DISP_AN(0xE);
	  disp_num(digit1);
	  count++;
	  current_time = timer_time_ms();
	}	
	    		
	else if (count == 1){
	    		
	  IOB_GPIO_SET_DISP_AN(0xD);
	  disp_num(digit2);
	  count = 0;
	  current_time = timer_time_ms();
	}
      }		 
    }
    current_time = timer_time_ms()+300;
    while(current_time>timer_time_ms()){
      x = x;
    }
  }
  uart_finish();
}

int sel_array(){
  switch(IOB_GPIO_GET_SWITCH_REG()) {
  case 1:
    return 64;
    break;
  case 2:
    return 128;
    break;
  case 4:
    return 256;
    break;
  case 8:
    return 512;
    break;	    
  case 16:
    return 1024;
    break;	    
  case 32:
    return 2048;
    break;	    
  case 64:
    return 4096;
    break;	    	  
  default:
    return 4;
    break;	   
  }
}

void disp_num(int number){
  switch(number) {
  case 0:
    IOB_GPIO_SET_DISP_CA(0x1);
    break;
  case 1:
    IOB_GPIO_SET_DISP_CA(0x4F);
    break;
  case 2:
    IOB_GPIO_SET_DISP_CA(0x12);
    break;
  case 3:
    IOB_GPIO_SET_DISP_CA(0x6);
    break;	    
  case 4:
    IOB_GPIO_SET_DISP_CA(0x4C);
    break;	    
  case 5:
    IOB_GPIO_SET_DISP_CA(0x24);
    break;	    
  case 6:
    IOB_GPIO_SET_DISP_CA(0x20);
    break;	    
  case 7:
    IOB_GPIO_SET_DISP_CA(0xF);
    break;	  
  case 8:
    IOB_GPIO_SET_DISP_CA(0x0);
    break;
  case 9:
    IOB_GPIO_SET_DISP_CA(0x4);
    break;	   
  }
}
