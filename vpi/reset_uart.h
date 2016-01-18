static int reset_uart_calltf(char*user_data)
{

	vpiHandle RESET = vpi_handle_by_name("module_tb.RESET", NULL);

	reset.format=vpiIntVal;

	if(counter_reset < 5)
	{
		reset.value.integer = 1;
		vpi_put_value(RESET, &reset, NULL, vpiNoDelay);
		counter_reset = counter_reset + 1;
	}
	else
	{	
		reset.value.integer = 0;
		vpi_put_value(RESET, &reset, NULL, vpiNoDelay);
		SC_UART->reset_set_low();
	}

	return 0;
}
