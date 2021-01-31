#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <string.h>

#include <ncurses.h>
#include <panel.h>
#include <locale.h>

#include "mtxhelper.h"
#include "arrayhelper.h"
#include "charhelper.h"

#include "tui.h"

// The base window for the UI.
WINDOW*	window_base;

// The last known row size of the terminal.
DECLARE_MUTEX_VAR(int, window_base_rows)

// The last known column size of the terminal.
DECLARE_MUTEX_VAR(int, window_base_cols)

// Contains a view of the verilog source for the current context.
PANEL*	panel_src_browser;	

// Contains the ascii represetation of the verilog source for the current context.
PANEL*	panel_schem_viewer;	

// Contains the current options selected.
PANEL*	panel_option_menu;	

// Contains information on the current context.
PANEL*	panel_info;	

// Contains a notifcation for the program.
PANEL*	panel_notify_exit;

void tui_draw_window_base()
{
	// Clear old panel window content.
	wclear(panel_window(panel_notify_exit));

	// Set panel window color.
	wattron(window_base, COLOR_PAIR(COLORPAIR_BLUE_WHITE));

	// Draw border.
	wborder(window_base,' ',' ',' ',' ',' ',' ',' ',' ');

	// Set panel window color again.
	wattroff(window_base, COLOR_PAIR(COLORPAIR_BLUE_WHITE));

	// Get max y and x of exit prompt.
	int exit_rows, exit_cols;
	getmaxyx(panel_window(panel_notify_exit), exit_rows, exit_cols);

	// Draw exit messages on exit notification panel, even if hidden.
	mvwprintw(panel_window(panel_notify_exit), 1, 1, "Quit");
	mvwprintw(panel_window(panel_notify_exit), (exit_rows / 2), (exit_cols / 6), "Press 'y'/'n'");
}

void tui_draw_panel_src_browser()
{
	// Clear old panel window content.
	wclear(panel_window(panel_option_menu));

	// Set panel window color.
	wattron(panel_window(panel_src_browser),COLOR_PAIR(COLORPAIR_WHITE_BLUE));

	// Draw border.
	box(panel_window(panel_src_browser),0,0);

	// Set panel window color again.
	wattroff(panel_window(panel_src_browser),COLOR_PAIR(COLORPAIR_WHITE_BLUE));
	
	// Print context of panel.
	mvwprintw(panel_window(panel_src_browser), 1, 1, "src: COLS = %d, LINES = %d", COLS, LINES);
}

void tui_draw_panel_schem_viewer()
{
	// Clear old panel window content.
	wclear(panel_window(panel_schem_viewer));

	// Set panel window color.
	wattron(panel_window(panel_schem_viewer),COLOR_PAIR(COLORPAIR_WHITE_BLUE));

	// Draw border.
	box(panel_window(panel_schem_viewer),0,0);

	// Set panel window color again.
	wattroff(panel_window(panel_schem_viewer),COLOR_PAIR(COLORPAIR_WHITE_BLUE));
	
	// Print context of panel.
	mvwprintw(panel_window(panel_schem_viewer), 1, 1, "schem: COLS = %d, LINES = %d", COLS, LINES);
}

void tui_draw_panel_info()
{
	// Clear old panel window content.
	wclear(panel_window(panel_info));

	// Set panel window color.
	wattron(panel_window(panel_info),COLOR_PAIR(COLORPAIR_WHITE_BLUE));

	// Draw border.
	box(panel_window(panel_info),0,0);

	// Set panel window color again.
	wattroff(panel_window(panel_info),COLOR_PAIR(COLORPAIR_WHITE_BLUE));

	// Print context of panel.
	mvwprintw(panel_window(panel_info), 1, 1, "info: COLS = %d, LINES = %d", COLS, LINES);
}

void tui_draw_panel_option_menu()
{
	// Clear old panel window content.
	wclear(panel_window(panel_option_menu));

	// Set panel window color.
	wattron(panel_window(panel_option_menu),COLOR_PAIR(COLORPAIR_WHITE_BLUE));

	// Draw border.
	box(panel_window(panel_option_menu),0,0);

	// Set panel window color again.
	wattroff(panel_window(panel_option_menu),COLOR_PAIR(COLORPAIR_WHITE_BLUE));

	// Print context of panel.
	mvwprintw(panel_window(panel_option_menu), 1, 1, "option: COLS = %d, LINES = %d", COLS, LINES);
}

void tui_draw_panel_notify_exit()
{
	// Clear old panel window content.
	wclear(panel_window(panel_notify_exit));

	// Set panel window color.
	wattron(panel_window(panel_notify_exit),COLOR_PAIR(COLORPAIR_WHITE_BLUE));

	// Draw border.
	box(panel_window(panel_notify_exit),0,0);

	// Set panel window color again.
	wattroff(panel_window(panel_notify_exit),COLOR_PAIR(COLORPAIR_WHITE_BLUE));

	// Get max y and x of exit prompt.
	int exit_rows, exit_cols;
	getmaxyx(panel_window(panel_notify_exit), exit_rows, exit_cols);

	// Draw exit messages on exit notification panel, even if hidden.
	mvwprintw(panel_window(panel_notify_exit), 1, 1, "Quit");
	mvwprintw(panel_window(panel_notify_exit), (exit_rows / 2), (exit_cols / 6), "Press 'y'/'n'");
}

int tui_get_input()
{
	return getch();
}

int tui_handle_input(int input_char)
{
	// Declare default return value.
	int val = 0;

	switch(input_char)
	{
		case KEY_F(10):	
			// Prompt user for exit on quit.
			// Rehide panel if exit prompt is up and user pressed 'quit' again.
			if (panel_hidden(panel_notify_exit) == false)
			{
				hide_panel(panel_notify_exit);
				break;
			}
			else
			{
				show_panel(panel_notify_exit);
				break;
			}
		case 'y':
			// Exit if exit prompt is up and use pressed 'y'.
			if (panel_hidden(panel_notify_exit) == false)
			{
				val = 1;
				break;
			}
		case 'n':
			// Rehide panel if exit prompt is up and user pressed 'n'.
			if (panel_hidden(panel_notify_exit) == false)
			{
				hide_panel(panel_notify_exit);
				break;
			}
		default:
			
			break;
	}

	return val;
}

// Resizes a panel window by replacing it's current window with a resized one.
void tui_resize_panel(PANEL* panel, int rows, int cols, int start_y, int start_x)
{	
	WINDOW* old_win_inst = panel_window(panel);
	WINDOW* new_win_inst = newwin(rows, cols, start_y, start_x);
	replace_panel(panel, new_win_inst);
	delwin(old_win_inst);
}

// Stores the row and column size of the base window; helpful if the terminal is resized.
void tui_update_terminal_size()
{
	// Declare vars for screen info.
	int rows = 0, cols = 0;

	// Get size of window.
	getmaxyx(window_base, rows, cols);

	// Set known row and col vars.
	SET_MUTEX_VAR(window_base_rows, rows)
	SET_MUTEX_VAR(window_base_cols, cols)	
}

void tui_resize_handler(int sig)
{
	// End ncurses and reinitialize with resized terminal.
	endwin();
	refresh();
	clear();
	
	// Update the size storage variables of the window.
	tui_update_terminal_size();

	// Make sure we don't overlap windows or menu bars by checking some values before resizing.
	int panel_src_browser_rows	= (window_base_rows / 4) + 2;
	int panel_src_browser_cols	= ((window_base_cols / 4) * 3) - 1;
	int panel_src_browser_stry	= ((window_base_rows / 4) * 3);
	int panel_src_browser_strx	= 1;
	int panel_src_browser_endy	= panel_src_browser_rows + panel_src_browser_stry; 
	//int panel_src_browser_endx	= panel_src_browser_cols + panel_src_browser_endx; 
	if (panel_src_browser_endy >= (window_base_rows - 1))
		panel_src_browser_rows -= (panel_src_browser_endy - (window_base_rows - 1));

	int panel_schem_viewer_rows	= ((window_base_rows / 4) * 3) - 1;
	int panel_schem_viewer_cols	= ((window_base_cols / 4) * 3) - 1;
	int panel_schem_viewer_stry	= 1;
	int panel_schem_viewer_strx	= 1;
	//int panel_schem_viewer_endy	= panel_schem_viewer_rows + panel_schem_viewer_stry; 
	//int panel_schem_viewer_endx	= panel_schem_viewer_cols + panel_schem_viewer_strx; 

	int panel_info_rows			= (window_base_rows / 2) + 1;
	int panel_info_cols			= (window_base_cols / 4) + 2;
	int panel_info_stry			= (window_base_rows / 2);
	int panel_info_strx			= ((window_base_cols / 4) * 3);
	int panel_info_endy			= panel_info_rows + panel_info_stry; 
	int panel_info_endx			= panel_info_cols + panel_info_strx; 
	if (panel_info_endy >= (window_base_rows - 1))
		panel_info_rows -= (panel_info_endy - (window_base_rows - 1));
	if (panel_info_endx >= (window_base_cols - 1))
		panel_info_cols -= (panel_info_endx - (window_base_cols - 1));

	int panel_option_menu_rows	= (window_base_rows / 2) - 1;
	int panel_option_menu_cols	= (window_base_cols / 4) + 2;
	int panel_option_menu_stry	= 1;
	int panel_option_menu_strx	= ((window_base_cols / 4) * 3);
	//int panel_option_menu_endy	= panel_option_menu_rows + panel_option_menu_stry; 
	int panel_option_menu_endx	= panel_option_menu_cols + panel_option_menu_strx; 
	if (panel_option_menu_endx >= (window_base_cols - 1))
		panel_option_menu_cols -= (panel_option_menu_endx - (window_base_cols - 1));

	int panel_notify_exit_rows	= (window_base_rows / 4) - 1;
	int panel_notify_exit_cols	= (window_base_cols / 4) - 1;
	int panel_notify_exit_stry	= ((window_base_rows / 8) * 3) - 1;
	int panel_notify_exit_strx	= ((window_base_cols / 8) * 3) - 1;
	//int panel_schem_viewer_endy	= panel_schem_viewer_rows + panel_schem_viewer_stry; 
	//int panel_schem_viewer_endx	= panel_schem_viewer_cols + panel_schem_viewer_strx; 

	// Resize panels.
	tui_resize_panel(panel_src_browser,
		panel_src_browser_rows, panel_src_browser_cols, 
		panel_src_browser_stry, panel_src_browser_strx);
	tui_resize_panel(panel_schem_viewer,
		panel_schem_viewer_rows, panel_schem_viewer_cols,
		panel_schem_viewer_stry, panel_schem_viewer_strx);
	tui_resize_panel(panel_info,
		panel_info_rows, panel_info_cols,
		panel_info_stry, panel_info_strx);
	tui_resize_panel(panel_option_menu, 
		panel_option_menu_rows, panel_option_menu_cols,
		panel_option_menu_stry, panel_option_menu_strx);
	tui_resize_panel(panel_option_menu, 
		panel_option_menu_rows, panel_option_menu_cols,
		panel_option_menu_stry, panel_option_menu_strx);
	tui_resize_panel(panel_notify_exit, 
		panel_notify_exit_rows, panel_notify_exit_cols,
		panel_notify_exit_stry, panel_notify_exit_strx);

	// Update the UI.
	tui_update_ui();
}

/// HIFN  Initializes the UI interface, and panels.
void tui_init()
{
	// Initialize base window.
	window_base = initscr();
	start_color();
	noecho();
	curs_set(FALSE);
	// Set getch as non-blocking.
	nodelay(stdscr, TRUE);
	// Allow use of function keys, plus others.
	keypad(stdscr, TRUE);

	// Set color pairs.
	init_pair(COLORPAIR_WHITE_BLACK, COLOR_WHITE, COLOR_BLACK);
	init_pair(COLORPAIR_BLACK_WHITE, COLOR_BLACK, COLOR_WHITE);
	init_pair(COLORPAIR_WHITE_BLUE,	COLOR_WHITE, COLOR_BLUE);
	init_pair(COLORPAIR_BLUE_WHITE,	COLOR_BLUE, COLOR_WHITE);

	// Update the size of the window once, for the init process.
	tui_update_terminal_size();

	/* Initialize windows for each TUI element:
	 * Option menu,		location: top-right,  height: 1/4 base_rows, width: 1/4 base_cols.
	 * Info Panel,		location: bottom-right,  height: 1/2 base_rows, width: 1/4 base_cols.
	 * Source Browser,	location: bottom,  height: 1/4 base_rows, width: base_cols.
	 * Schem Viewer,	location: top-left,  height: 3/4 base_rows, width: 3/4 base_cols.
	 */
	//window_option_menu 	= newwin(window_base_rows / 4, window_base_cols / 4, 0, window_base_cols / 2);
	//window_info 		= newwin(window_base_rows / 2, window_base_cols / 4, window_base_rows / 2, window_base_cols / 2);
	//window_src_browser 	= newwin(window_base_rows / 4, window_base_cols, (window_base_rows / 4) * 3, 0);
	//window_schem_viewer = newwin((window_base_rows / 4) * 3, (window_base_cols / 4) * 3, 0, 0);
	WINDOW* window_src_browser 	= newwin(window_base_rows - 1, window_base_cols - 1, 1, 1);
	WINDOW* window_schem_viewer = newwin(window_base_rows - 1, window_base_cols - 1, 1, 1);
	WINDOW* window_info 		= newwin(window_base_rows - 1, window_base_cols - 1, 1, 1);
	WINDOW* window_option_menu 	= newwin(window_base_rows - 1, window_base_cols - 1, 1, 1);
	WINDOW* window_notify	 	= newwin(window_base_rows - 1, window_base_cols - 1, 1, 1);

	// Initialize panels.
	panel_src_browser = new_panel(window_src_browser);
	panel_schem_viewer = new_panel(window_schem_viewer);
	panel_info = new_panel(window_info);
	panel_option_menu = new_panel(window_option_menu);
	panel_notify_exit = new_panel(window_notify);

	// Hide the notify panel on init.
	hide_panel(panel_notify_exit);

	// Set border for all windows.
	tui_resize_handler(0);
	
	// Move cursor and draw horizontal line from the bottom of the screen.
	//mvhline(window_base_rows - 3, 0, '-', window_base_rows);
}

/// HIFN  Deinitializes the UI interface and panels.
void tui_stop()
{
	// Close ncurses window.
	endwin();
}

void tui_draw_menu_main()
{
	// Draw menu bar background.
	attron(A_REVERSE); mvwhline(window_base, window_base_rows - 1, 0, ' ', window_base_cols); attroff(A_REVERSE); 

	// Define option strings.
	char* opts [] = {
		//"F1  Open",
		"F10 Quit"
		};

	// Draw function menu at the bottom of the screen.
	int y = (window_base_rows - 1);
	int x = 3;
	for (int i = 0; i < (int) ARRAY_SIZE(opts); i++)
	{
		// Print option.
		mvwprintw(window_base, y, x, opts[i]);	
		// Move cursor for next print.
		x += strlen(opts[i]) + 3;
	}
}

void tui_update_ui()
{	
	// Redraw base window.
	tui_draw_window_base();

	// Redraw src browser.
	tui_draw_panel_src_browser();

	// Redraw schem viewer.
	tui_draw_panel_schem_viewer();

	// Redraw info window.
	tui_draw_panel_info();

	// Redraw option menu.
	tui_draw_panel_option_menu();

	// Redraw exit notice panel.
	tui_draw_panel_notify_exit();

	// Redraw main menu on top of everything.
	tui_draw_menu_main();

	// Update panels.
	update_panels();

	// Show updates on screen.
	doupdate();

	// Refresh the screen.
	refresh();
}

