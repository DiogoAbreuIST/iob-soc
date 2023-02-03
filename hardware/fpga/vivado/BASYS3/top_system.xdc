# ----------------------------------------------------------------------------
#     _____
#    /     \
#   /____   \____
#  / \===\   \==/
# /___\===\___\/  AVNET Design Resource Center
#      \======/         www.em.avnet.com/drc
#       \====/
# ----------------------------------------------------------------------------
#
#  Disclaimer:
#     Avnet, Inc. makes no warranty for the use of this code or design.
#     This code is provided  "As Is". Avnet, Inc assumes no responsibility for
#     any errors, which may appear in this code, nor does it make a commitment
#     to update the information contained herein. Avnet, Inc specifically
#     disclaims any implied warranties of fitness for a particular purpose.
#                      Copyright(c) 2009 Avnet, Inc.
#                              All rights reserved.
#
# ----------------------------------------------------------------------------

## System Clock
set_property PACKAGE_PIN W5 [get_ports clk]
set_property IOSTANDARD LVCMOS33 [get_ports clk]

# System Reset
set_property PACKAGE_PIN T17 [get_ports reset]
set_property IOSTANDARD LVCMOS33 [get_ports reset]

create_clock -period 10.000 [get_ports clk]

## USB-UART Interface
set_property PACKAGE_PIN B18 [get_ports uart_rxd]
set_property IOSTANDARD LVCMOS33 [get_ports uart_rxd]
set_property PACKAGE_PIN A18 [get_ports uart_txd]
set_property IOSTANDARD LVCMOS33 [get_ports uart_txd]

## SWITCHES

set_property PACKAGE_PIN V17 [get_ports {gpio_sw[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_sw[0]}]
set_property PACKAGE_PIN V16 [get_ports {gpio_sw[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_sw[1]}]
set_property PACKAGE_PIN W16 [get_ports {gpio_sw[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_sw[2]}]
set_property PACKAGE_PIN W17 [get_ports {gpio_sw[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_sw[3]}]
set_property PACKAGE_PIN W15 [get_ports {gpio_sw[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_sw[4]}]
set_property PACKAGE_PIN V15 [get_ports {gpio_sw[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_sw[5]}]
set_property PACKAGE_PIN W14 [get_ports {gpio_sw[6]}]
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_sw[6]}]
set_property PACKAGE_PIN W13 [get_ports {gpio_sw[7]}]
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_sw[7]}]
set_property PACKAGE_PIN V2 [get_ports {gpio_sw[8]}]
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_sw[8]}]
set_property PACKAGE_PIN T3 [get_ports {gpio_sw[9]}]
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_sw[9]}]
set_property PACKAGE_PIN T2 [get_ports {gpio_sw[10]}]
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_sw[10]}]
set_property PACKAGE_PIN R3 [get_ports {gpio_sw[11]}]
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_sw[11]}]

## DISPLAY
## Anodes
set_property PACKAGE_PIN U2 [get_ports {gpio_disp_an[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_disp_an[0]}]
set_property PACKAGE_PIN U4 [get_ports {gpio_disp_an[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_disp_an[1]}]
set_property PACKAGE_PIN V4 [get_ports {gpio_disp_an[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_disp_an[2]}]
set_property PACKAGE_PIN W4 [get_ports {gpio_disp_an[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_disp_an[3]}]

## Cathodes
set_property PACKAGE_PIN W7 [get_ports {gpio_disp_ca[0]}] 	## A
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_disp_ca[0]}]
set_property PACKAGE_PIN W6 [get_ports {gpio_disp_ca[1]}] 	## B
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_disp_ca[1]}]
set_property PACKAGE_PIN U8 [get_ports {gpio_disp_ca[2]}] 	## C
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_disp_ca[2]}]
set_property PACKAGE_PIN V8 [get_ports {gpio_disp_ca[3]}] 	## D
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_disp_ca[3]}]
set_property PACKAGE_PIN U5 [get_ports {gpio_disp_ca[4]}] 	## E
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_disp_ca[4]}]
set_property PACKAGE_PIN V5 [get_ports {gpio_disp_ca[5]}] 	## F
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_disp_ca[5]}]
set_property PACKAGE_PIN U7 [get_ports {gpio_disp_ca[6]}] 	## G
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_disp_ca[6]}]
set_property PACKAGE_PIN V7 [get_ports {gpio_disp_ca[7]}] 	## Point
set_property IOSTANDARD LVCMOS33 [get_ports {gpio_disp_ca[7]}]





