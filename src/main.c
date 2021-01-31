#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#include <signal.h>
#include <pthread.h>

#include <readline/readline.h>

#include "tui.h"
#include "circuitmodel.h"

/// Declare TUI thread id storage.
pthread_t tid_tui;

/// Declare bool for if we caught a signit.
volatile bool caught_sigint = false;
volatile bool do_exit = false;

/// Catches SIGINT, and flags an exit is requested.
void main_int_handler(int signum)
{
	caught_sigint = true;
}

/// Threaded function for TUI.
void *thread_tui_process(void *vargp) 
{  	
	// Initialize ncurses window.
	tui_init();

	// Loop and handle user input.
	while (true) {
		// Wait for 1/20 seconds.
		usleep(50000);

		// Update UI.
		tui_update_ui();

		// Handle non-blocking user input.
		int input_char = tui_get_input();
		if (tui_handle_input(input_char) != 0)
			do_exit = true;	

		if (caught_sigint || do_exit)
			break;
	}
	
	// Close ncurses window.
	tui_stop();

	return NULL;
} 

int main (int argc, char *argv[])
{
	// Set handler for tui resize.
	signal(SIGWINCH, tui_resize_handler);

	// Set handler for sigint, to kill threads.
	signal(SIGINT, main_int_handler);

	// Load verilog file from args.
	if (argc == 2)
	{
		cm_read_verilog_file(argv[1]);
		return 0;
	}
	else
	{
		printf("Usage: termschem <verilog_file>\n");
		return -1;
	}

	// Start TUI thread.
	pthread_create(&tid_tui, NULL, thread_tui_process, NULL);

	// Wait for TUI thread exit.
	pthread_join(tid_tui, NULL);
	
	return 0;
}


