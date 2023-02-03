   // GPIO
   input [`GPIO_INPUT_W-1:0] gpio_input,
   input [11:0] gpio_sw,
   output [`GPIO_OUTPUT_W-1:0] gpio_output,
   output [`GPIO_OUTPUT_W-1:0] gpio_output_enable,
   output [3:0] gpio_disp_an,
   output [7:0] gpio_disp_ca,
