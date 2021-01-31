#ifndef __TUI_H__
#define __TUI_H__

#ifdef __cplusplus
extern "C" {
#endif

/// Define color pair indexes to use with ncurses.
#define COLORPAIR_WHITE_BLACK	1
#define COLORPAIR_BLACK_WHITE	2
#define COLORPAIR_WHITE_BLUE	3
#define COLORPAIR_BLUE_WHITE	4


int tui_get_input();
int tui_handle_input(int input_char);
void tui_resize_handler(int sig);
void tui_init();
void tui_stop();
void tui_update_ui();

#ifdef __cplusplus
}
#endif

#endif
