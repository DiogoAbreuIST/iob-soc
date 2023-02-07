`timescale 1ns/1ps

`include "iob_lib.vh"
`include "iob_gpio_swreg_def.vh"

module iob_gpio 
  # (
     parameter GPIO_W = 32, //PARAM Number of GPIO (can be up to DATA_W)
     parameter DATA_W = 32, //PARAM CPU data width
     parameter ADDR_W = `iob_gpio_swreg_ADDR_W //MACRO CPU address section width
     )
   (

   //CPU interface
`include "iob_s_if.vh"

    // inputs and outputs have dedicated interface
    input [GPIO_W-1:0] gpio_input,
    input [11:0] gpio_sw,
    
    output [GPIO_W-1:0] gpio_output,
    // output enable can be used to tristate outputs on external module
    output [GPIO_W-1:0] gpio_output_enable,
    output [3:0] gpio_disp_an,
    output [6:0] gpio_disp_ca,

`include "iob_gen_if.vh"
    );



//BLOCK Register File & Configuration control and status register file.
`include "iob_gpio_swreg_gen.vh"

    // SWRegs

    
        `IOB_WIRE(GPIO_DATA_REG, 32)
    iob_reg #(32)
    data_reg      (
        .clk        (clk),
        .arst       (rst),
        .rst        (rst),
        .en         (GPIO_DATA_REG_en),
        .data_in    (GPIO_DATA_REG_wdata),
        .data_out   (GPIO_DATA_REG)
    );
  


    `IOB_WIRE(GPIO_OUTPUT_ENABLE, DATA_W)
    iob_reg #(.DATA_W(DATA_W))
    gpio_output_enable_reg (
        .clk        (clk),
        .arst       (rst),
        .rst        (rst),
        .en         (GPIO_OUTPUT_ENABLE_en),
        .data_in    (GPIO_OUTPUT_ENABLE_wdata),
        .data_out   (GPIO_OUTPUT_ENABLE)
    );

    `IOB_WIRE(GPIO_OUTPUT, DATA_W)
    iob_reg #(.DATA_W(DATA_W))
    gpio_output_reg      (
        .clk        (clk),
        .arst       (rst),
        .rst        (rst),
        .en         (GPIO_OUTPUT_en),
        .data_in    (GPIO_OUTPUT_wdata),
        .data_out   (GPIO_OUTPUT)
    );
    
    `IOB_WIRE(GPIO_DISP_AN, 8)
    iob_reg #(8)
    gpio_disp_an_reg      (
        .clk        (clk),
        .arst       (rst),
        .rst        (rst),
        .en         (GPIO_DISP_AN_en),
        .data_in    (GPIO_DISP_AN_wdata),
        .data_out   (GPIO_DISP_AN)
    );

    `IOB_WIRE(GPIO_DISP_CA, 8)
    iob_reg #(8)
    gpio_disp_ca_reg      (
        .clk        (clk),
        .arst       (rst),
        .rst        (rst),
        .en         (GPIO_DISP_CA_en),
        .data_in    (GPIO_DISP_CA_wdata),
        .data_out   (GPIO_DISP_CA)
    );


`IOB_WIRE(en,1)
`IOB_WIRE(reset,1)
`IOB_VAR(a,8)
`IOB_VAR(b,8)
`IOB_VAR(c,8)
`IOB_VAR(d,8)
`IOB_VAR(e,8)
`IOB_VAR(f,8)
`IOB_VAR_INIT(new_max,8,0)
`IOB_VAR_INIT(last_max,8,0)
`IOB_REG_ARRE(clk,rst,0,reset, 0,en,last_max,new_max)
 assign reset = GPIO_DATA_REG_RESET_wdata & GPIO_DATA_REG_RESET_en;
 assign en = ((new_max) > (last_max) ? 1 : 0);
`IOB_COMB begin

    a = GPIO_DATA_REG[31:24];
    b = GPIO_DATA_REG[23:16];
    c = GPIO_DATA_REG[15:8];
    d = GPIO_DATA_REG[7:0];
    e = `IOB_MAX(a,b);
    f = `IOB_MAX(c,d);
    new_max = `IOB_MAX(e,f);

end

   // Read GPIO
   assign GPIO_SWITCH_REG_rdata = gpio_sw;
   assign GPIO_RESULT_REG_rdata = last_max;
   assign GPIO_INPUT_rdata = gpio_input;

   // Write GPIO
   assign gpio_output = GPIO_OUTPUT;
   assign gpio_output_enable = GPIO_OUTPUT_ENABLE;
   assign gpio_disp_an = GPIO_DISP_AN;
   assign gpio_disp_ca = GPIO_DISP_CA;


endmodule
