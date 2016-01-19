static int reset_uart_calltf(char*user_data)
{

	vpiHandle RESET = vpi_handle_by_name("module_tb.RESET", NULL);
	vpiHandle RX        = vpi_handle_by_name("module_tb.RX", NULL);
	vpiHandle TX	    = vpi_handle_by_name("module_tb.TX", NULL);

	reset.format=vpiIntVal;
	rx_value.format = vpiIntVal;
	tx_value.format = vpiIntVal;

	if(counter_reset < 5)
	{
		reset.value.integer = 1;
		vpi_put_value(RESET, &reset, NULL, vpiNoDelay);
		counter_reset = counter_reset + 1;

		tx_value.value.integer = SC_UART->read_tx();
		vpi_put_value(RX, &tx_value, NULL, vpiNoDelay);

		vpi_get_value(TX, &rx_value);
		SC_UART->write_rx(rx_value.value.integer);
	}
	else
	{	
		reset.value.integer = 0;
		vpi_put_value(RESET, &reset, NULL, vpiNoDelay);
		SC_UART->reset_set_low();
	}

	return 0;
}
