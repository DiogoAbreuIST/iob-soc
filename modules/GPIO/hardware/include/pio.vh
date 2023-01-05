   // GPIO
   input [31:0] DATA_IN,
   output [7:0] RESULT,
   
   
   
   input [`GPIO_INPUT_W-1:0] gpio_input,
   output [`GPIO_OUTPUT_W-1:0] gpio_output,
   output [`GPIO_OUTPUT_W-1:0] gpio_output_enable,
