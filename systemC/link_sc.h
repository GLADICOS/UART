#ifndef CONTROL_SC_H
#define CONTROL_SC_H

class Control_SC
{
	public:
	/*Constructor*/
	Control_SC();
	
	/*initialize systemC model*/
	virtual void init();

	/*Reset the model*/
	virtual void reset_set_high();
	virtual void reset_set_low();

	/*This is used to configure clock on systemC model note here you must put period  T = 1/F*/	
	virtual void set_period_clock_sc(unsigned value_freq);

	/*This must be used to set baud value on Env. Ex: 9600 / 50MHz"Only 50"*/
	virtual void set_baud_rate(unsigned int value_baud,unsigned frequency);
	/*Get the baud rate and set it to your DUT*/
	virtual int  get_baud_rate();

	/*We use functions to retreive values from RX / TX SytemC to Verilog*/
	virtual void write_rx(unsigned int a);
	virtual int read_tx();

	/*Run the Env for a mmount off time*/
	virtual void run_sim();

	/*Tell to SystemC to finish*/
	virtual void stop_sim();

};
#endif
