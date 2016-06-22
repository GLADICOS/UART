static int run_sim_calltf(char*user_data)
{
	vpiHandle i = vpi_handle_by_name("module_tb.i", NULL);

	vpiHandle RESET     = vpi_handle_by_name("module_tb.RESET", NULL);
	vpiHandle RX        = vpi_handle_by_name("module_tb.RX", NULL);
	vpiHandle START     = vpi_handle_by_name("module_tb.START", NULL);
	vpiHandle DATA_TX   = vpi_handle_by_name("module_tb.DATA_TX", NULL);
	vpiHandle WORK_FR   = vpi_handle_by_name("module_tb.WORK_FR", NULL);
	vpiHandle TX        = vpi_handle_by_name("module_tb.TX", NULL);
	vpiHandle DATA_RX   = vpi_handle_by_name("module_tb.DATA_RX", NULL);
	vpiHandle PARITY_RX = vpi_handle_by_name("module_tb.PARITY_RX", NULL);
	vpiHandle READY_TX  = vpi_handle_by_name("module_tb.READY_TX", NULL);
	vpiHandle READY     = vpi_handle_by_name("module_tb.READY", NULL);
	vpiHandle a         = vpi_handle_by_name("module_tb.a", NULL);
	
	v_generate.format=vpiIntVal;

	reset.format	= vpiIntVal;
	rx_value.format = vpiIntVal;
	tx_value.format = vpiIntVal;
	ready_rx.format = vpiIntVal;
	start_tx.format = vpiIntVal;
	ready_tx.format = vpiIntVal;

	if(SC_UART->finish_simulation())
	{
		v_generate.value.integer = 1;
		vpi_put_value(i, &v_generate, NULL, vpiNoDelay);
		SC_UART->stop_sim();
		destroy(SC_UART);
	}
	else
	{

		if(SC_UART->enable_change())
		{
			tx_value.value.integer = SC_UART->set_clock_rtl();
			vpi_put_value(a, &tx_value, NULL, vpiNoDelay);
		}

		SC_UART->run_sim();

		tx_value.value.integer = SC_UART->read_tx();
		vpi_put_value(RX, &tx_value, NULL, vpiNoDelay);

		vpi_get_value(TX, &rx_value);
		SC_UART->write_rx(rx_value.value.integer);

		
		if(SC_UART->reset_set())
		{
			data.clear();
			parity.clear();
		}
		else
		{
			//
			if(data.size()> 0)
			{
				vpi_get_value(READY_TX, &ready_tx);
				if(ready_tx.value.integer == 1)
				{
					start_tx.value.integer = 1;
					vpi_put_value(START, &start_tx, NULL, vpiNoDelay);
					start_tx.value.integer = data[0];
					data.erase(data.begin());
					parity.erase(parity.begin());
					vpi_put_value(DATA_TX, &start_tx, NULL, vpiNoDelay);
				}else
				{
					vpi_get_value(READY_TX, &ready_tx);
					if(ready_tx.value.integer == 0)
					{
						start_tx.value.integer = 0;
						vpi_put_value(START, &start_tx, NULL, vpiNoDelay);
					}
				}
			}
			//
			vpi_get_value(READY, &ready_rx);
			if(ready_rx.value.integer == 1)
			{
				vpi_get_value(DATA_RX, &ready_rx);
				data.push_back(ready_rx.value.integer);
				vpi_get_value(PARITY_RX, &ready_rx);
				parity.push_back(ready_rx.value.integer);
				SC_UART->get_value_sc_vlog(data[0],parity[0]);
			}
		}
	}
	return 0;
}
