   //
   // GPIO
   //

   iob_gpio gpio0
     (
      .clk     (clk),
	// Registers interface
      .gpio_input (gpio_input),
      .gpio_sw (gpio_sw),
      .gpio_output (gpio_output),
      .gpio_output_enable (gpio_output_enable),
      .gpio_disp_an (gpio_disp_an),
      .gpio_disp_ca (gpio_disp_ca),

      // CPU interface
      .valid   (slaves_req[`valid(`GPIO)]),
      .address (slaves_req[`address(`GPIO,`iob_gpio_swreg_ADDR_W+2)-2]),
      .wdata   (slaves_req[`wdata(`GPIO)]),
      .wstrb   (slaves_req[`wstrb(`GPIO)]),
      .rdata   (slaves_resp[`rdata(`GPIO)]),
      .ready   (slaves_resp[`ready(`GPIO)])
      );
