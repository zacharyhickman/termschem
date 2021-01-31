





typedef unsigned chtype;

typedef unsigned mmask_t;



typedef unsigned char NCURSES_BOOL;

extern chtype acs_map[];

typedef struct screen SCREEN;

typedef struct _win_st WINDOW;



typedef chtype attr_t;

struct ldat;



struct _win_st

{

 short _cury, _curx;





 short _maxy, _maxx;

 short _begy, _begx;



 short _flags;





 attr_t _attrs;

 chtype _bkgd;





 

_Bool 

     _notimeout;

 

_Bool 

     _clear;

 

_Bool 

     _leaveok;

 

_Bool 

     _scroll;

 

_Bool 

     _idlok;

 

_Bool 

     _idcok;

 

_Bool 

     _immed;

 

_Bool 

     _sync;

 

_Bool 

     _use_keypad;

 int _delay;



 struct ldat *_line;





 short _regtop;

 short _regbottom;





 int _parx;

 int _pary;

 WINDOW *_parent;





 struct pdat

 {

     short _pad_y, _pad_x;

     short _pad_top, _pad_left;

     short _pad_bottom, _pad_right;

 } _pad;



 short _yoffset;















};

typedef int (*NCURSES_OUTC)(int);

extern int addch (const chtype);

extern int addchnstr (const chtype *, int);

extern int addchstr (const chtype *);

extern int addnstr (const char *, int);

extern int addstr (const char *);

extern int attroff (int);

extern int attron (int);

extern int attrset (int);

extern int attr_get (attr_t *, short *, void *);

extern int attr_off (attr_t, void *);

extern int attr_on (attr_t, void *);

extern int attr_set (attr_t, short, void *);

extern int baudrate (void);

extern int beep (void);

extern int bkgd (chtype);

extern void bkgdset (chtype);

extern int border (chtype,chtype,chtype,chtype,chtype,chtype,chtype,chtype);

extern int box (WINDOW *, chtype, chtype);

extern 

      _Bool 

                           can_change_color (void);

extern int cbreak (void);

extern int chgat (int, attr_t, short, const void *);

extern int clear (void);

extern int clearok (WINDOW *,

                                            _Bool

                                                );

extern int clrtobot (void);

extern int clrtoeol (void);

extern int color_content (short,short*,short*,short*);

extern int color_set (short,void*);

extern int COLOR_PAIR (int);

extern int copywin (const WINDOW*,WINDOW*,int,int,int,int,int,int,int);

extern int curs_set (int);

extern int def_prog_mode (void);

extern int def_shell_mode (void);

extern int delay_output (int);

extern int delch (void);

extern void delscreen (SCREEN *);

extern int delwin (WINDOW *);

extern int deleteln (void);

extern WINDOW * derwin (WINDOW *,int,int,int,int);

extern int doupdate (void);

extern WINDOW * dupwin (WINDOW *);

extern int echo (void);

extern int echochar (const chtype);

extern int erase (void);

extern int endwin (void);

extern char erasechar (void);

extern void filter (void);

extern int flash (void);

extern int flushinp (void);

extern chtype getbkgd (WINDOW *);

extern int getch (void);

extern int getnstr (char *, int);

extern int getstr (char *);

extern WINDOW * getwin (FILE *);

extern int halfdelay (int);

extern 

      _Bool 

                           has_colors (void);

extern 

      _Bool 

                           has_ic (void);

extern 

      _Bool 

                           has_il (void);

extern int hline (chtype, int);

extern void idcok (WINDOW *, 

                                            _Bool

                                                );

extern int idlok (WINDOW *, 

                                           _Bool

                                               );

extern void immedok (WINDOW *, 

                                              _Bool

                                                  );

extern chtype inch (void);

extern int inchnstr (chtype *, int);

extern int inchstr (chtype *);

extern WINDOW * initscr (void);

extern int init_color (short,short,short,short);

extern int init_pair (short,short,short);

extern int innstr (char *, int);

extern int insch (chtype);

extern int insdelln (int);

extern int insertln (void);

extern int insnstr (const char *, int);

extern int insstr (const char *);

extern int instr (char *);

extern int intrflush (WINDOW *,

                                              _Bool

                                                  );

extern 

      _Bool 

                           isendwin (void);

extern 

      _Bool 

                           is_linetouched (WINDOW *,int);

extern 

      _Bool 

                           is_wintouched (WINDOW *);

extern const char * keyname (int);

extern int keypad (WINDOW *,

                                           _Bool

                                               );

extern char killchar (void);

extern int leaveok (WINDOW *,

                                            _Bool

                                                );

extern char * longname (void);

extern int meta (WINDOW *,

                                         _Bool

                                             );

extern int move (int, int);

extern int mvaddch (int, int, const chtype);

extern int mvaddchnstr (int, int, const chtype *, int);

extern int mvaddchstr (int, int, const chtype *);

extern int mvaddnstr (int, int, const char *, int);

extern int mvaddstr (int, int, const char *);

extern int mvchgat (int, int, int, attr_t, short, const void *);

extern int mvcur (int,int,int,int);

extern int mvdelch (int, int);

extern int mvderwin (WINDOW *, int, int);

extern int mvgetch (int, int);

extern int mvgetnstr (int, int, char *, int);

extern int mvgetstr (int, int, char *);

extern int mvhline (int, int, chtype, int);

extern chtype mvinch (int, int);

extern int mvinchnstr (int, int, chtype *, int);

extern int mvinchstr (int, int, chtype *);

extern int mvinnstr (int, int, char *, int);

extern int mvinsch (int, int, chtype);

extern int mvinsnstr (int, int, const char *, int);

extern int mvinsstr (int, int, const char *);

extern int mvinstr (int, int, char *);

extern int mvprintw (int,int, const char *,...)

  ;

extern int mvscanw (int,int, const char *,...)

  ;

extern int mvvline (int, int, chtype, int);

extern int mvwaddch (WINDOW *, int, int, const chtype);

extern int mvwaddchnstr (WINDOW *, int, int, const chtype *, int);

extern int mvwaddchstr (WINDOW *, int, int, const chtype *);

extern int mvwaddnstr (WINDOW *, int, int, const char *, int);

extern int mvwaddstr (WINDOW *, int, int, const char *);

extern int mvwchgat (WINDOW *, int, int, int, attr_t, short, const void *);

extern int mvwdelch (WINDOW *, int, int);

extern int mvwgetch (WINDOW *, int, int);

extern int mvwgetnstr (WINDOW *, int, int, char *, int);

extern int mvwgetstr (WINDOW *, int, int, char *);

extern int mvwhline (WINDOW *, int, int, chtype, int);

extern int mvwin (WINDOW *,int,int);

extern chtype mvwinch (WINDOW *, int, int);

extern int mvwinchnstr (WINDOW *, int, int, chtype *, int);

extern int mvwinchstr (WINDOW *, int, int, chtype *);

extern int mvwinnstr (WINDOW *, int, int, char *, int);

extern int mvwinsch (WINDOW *, int, int, chtype);

extern int mvwinsnstr (WINDOW *, int, int, const char *, int);

extern int mvwinsstr (WINDOW *, int, int, const char *);

extern int mvwinstr (WINDOW *, int, int, char *);

extern int mvwprintw (WINDOW*,int,int, const char *,...)

  ;

extern int mvwscanw (WINDOW *,int,int, const char *,...)

  ;

extern int mvwvline (WINDOW *,int, int, chtype, int);

extern int napms (int);

extern WINDOW * newpad (int,int);

extern SCREEN * newterm (const char *,FILE *,FILE *);

extern WINDOW * newwin (int,int,int,int);

extern int nl (void);

extern int nocbreak (void);

extern int nodelay (WINDOW *,

                                            _Bool

                                                );

extern int noecho (void);

extern int nonl (void);

extern void noqiflush (void);

extern int noraw (void);

extern int notimeout (WINDOW *,

                                              _Bool

                                                  );

extern int overlay (const WINDOW*,WINDOW *);

extern int overwrite (const WINDOW*,WINDOW *);

extern int pair_content (short,short*,short*);

extern int PAIR_NUMBER (int);

extern int pechochar (WINDOW *, const chtype);

extern int pnoutrefresh (WINDOW*,int,int,int,int,int,int);

extern int prefresh (WINDOW *,int,int,int,int,int,int);

extern int printw (const char *,...)

  ;

extern int putwin (WINDOW *, FILE *);

extern void qiflush (void);

extern int raw (void);

extern int redrawwin (WINDOW *);

extern int refresh (void);

extern int resetty (void);

extern int reset_prog_mode (void);

extern int reset_shell_mode (void);

extern int ripoffline (int, int (*)(WINDOW *, int));

extern int savetty (void);

extern int scanw (const char *,...)

  ;

extern int scr_dump (const char *);

extern int scr_init (const char *);

extern int scrl (int);

extern int scroll (WINDOW *);

extern int scrollok (WINDOW *,

                                             _Bool

                                                 );

extern int scr_restore (const char *);

extern int scr_set (const char *);

extern int setscrreg (int,int);

extern SCREEN * set_term (SCREEN *);

extern int slk_attroff (const chtype);

extern int slk_attr_off (const attr_t, void *);

extern int slk_attron (const chtype);

extern int slk_attr_on (attr_t,void*);

extern int slk_attrset (const chtype);

extern attr_t slk_attr (void);

extern int slk_attr_set (const attr_t,short,void*);

extern int slk_clear (void);

extern int slk_color (short);

extern int slk_init (int);

extern char * slk_label (int);

extern int slk_noutrefresh (void);

extern int slk_refresh (void);

extern int slk_restore (void);

extern int slk_set (int,const char *,int);

extern int slk_touch (void);

extern int standout (void);

extern int standend (void);

extern int start_color (void);

extern WINDOW * subpad (WINDOW *, int, int, int, int);

extern WINDOW * subwin (WINDOW *, int, int, int, int);

extern int syncok (WINDOW *, 

                                            _Bool

                                                );

extern chtype termattrs (void);

extern char * termname (void);

extern void timeout (int);

extern int touchline (WINDOW *, int, int);

extern int touchwin (WINDOW *);

extern int typeahead (int);

extern int ungetch (int);

extern int untouchwin (WINDOW *);

extern void use_env (

                                    _Bool

                                        );

extern void use_tioctl (

                                       _Bool

                                           );

extern int vidattr (chtype);

extern int vidputs (chtype, NCURSES_OUTC);

extern int vline (chtype, int);

extern int vwprintw (WINDOW *, const char *,va_list) __attribute__((deprecated));

extern int vw_printw (WINDOW *, const char *,va_list);

extern int vwscanw (WINDOW *, const char *,va_list) __attribute__((deprecated));

extern int vw_scanw (WINDOW *, const char *,va_list);

extern int waddch (WINDOW *, const chtype);

extern int waddchnstr (WINDOW *,const chtype *,int);

extern int waddchstr (WINDOW *,const chtype *);

extern int waddnstr (WINDOW *,const char *,int);

extern int waddstr (WINDOW *,const char *);

extern int wattron (WINDOW *, int);

extern int wattroff (WINDOW *, int);

extern int wattrset (WINDOW *, int);

extern int wattr_get (WINDOW *, attr_t *, short *, void *);

extern int wattr_on (WINDOW *, attr_t, void *);

extern int wattr_off (WINDOW *, attr_t, void *);

extern int wattr_set (WINDOW *, attr_t, short, void *);

extern int wbkgd (WINDOW *, chtype);

extern void wbkgdset (WINDOW *,chtype);

extern int wborder (WINDOW *,chtype,chtype,chtype,chtype,chtype,chtype,chtype,chtype);

extern int wchgat (WINDOW *, int, attr_t, short, const void *);

extern int wclear (WINDOW *);

extern int wclrtobot (WINDOW *);

extern int wclrtoeol (WINDOW *);

extern int wcolor_set (WINDOW*,short,void*);

extern void wcursyncup (WINDOW *);

extern int wdelch (WINDOW *);

extern int wdeleteln (WINDOW *);

extern int wechochar (WINDOW *, const chtype);

extern int werase (WINDOW *);

extern int wgetch (WINDOW *);

extern int wgetnstr (WINDOW *,char *,int);

extern int wgetstr (WINDOW *, char *);

extern int whline (WINDOW *, chtype, int);

extern chtype winch (WINDOW *);

extern int winchnstr (WINDOW *, chtype *, int);

extern int winchstr (WINDOW *, chtype *);

extern int winnstr (WINDOW *, char *, int);

extern int winsch (WINDOW *, chtype);

extern int winsdelln (WINDOW *,int);

extern int winsertln (WINDOW *);

extern int winsnstr (WINDOW *, const char *,int);

extern int winsstr (WINDOW *, const char *);

extern int winstr (WINDOW *, char *);

extern int wmove (WINDOW *,int,int);

extern int wnoutrefresh (WINDOW *);

extern int wprintw (WINDOW *, const char *,...)

  ;

extern int wredrawln (WINDOW *,int,int);

extern int wrefresh (WINDOW *);

extern int wscanw (WINDOW *, const char *,...)

  ;

extern int wscrl (WINDOW *,int);

extern int wsetscrreg (WINDOW *,int,int);

extern int wstandout (WINDOW *);

extern int wstandend (WINDOW *);

extern void wsyncdown (WINDOW *);

extern void wsyncup (WINDOW *);

extern void wtimeout (WINDOW *,int);

extern int wtouchln (WINDOW *,int,int,int);

extern int wvline (WINDOW *,chtype,int);









extern int tigetflag (const char *);

extern int tigetnum (const char *);

extern char * tigetstr (const char *);

extern int putp (const char *);





extern char * tparm (const char *, ...);











extern char * tiparm (const char *, ...);

extern int getattrs (const WINDOW *);

extern int getcurx (const WINDOW *);

extern int getcury (const WINDOW *);

extern int getbegx (const WINDOW *);

extern int getbegy (const WINDOW *);

extern int getmaxx (const WINDOW *);

extern int getmaxy (const WINDOW *);

extern int getparx (const WINDOW *);

extern int getpary (const WINDOW *);

typedef int (*NCURSES_WINDOW_CB)(WINDOW *, void *);

typedef int (*NCURSES_SCREEN_CB)(SCREEN *, void *);

extern 

      _Bool 

                           is_term_resized (int, int);

extern char * keybound (int, int);

extern const char * curses_version (void);

extern int alloc_pair (int, int);

extern int assume_default_colors (int, int);

extern int define_key (const char *, int);

extern int extended_color_content(int, int *, int *, int *);

extern int extended_pair_content(int, int *, int *);

extern int extended_slk_color(int);

extern int find_pair (int, int);

extern int free_pair (int);

extern int get_escdelay (void);

extern int init_extended_color(int, int, int, int);

extern int init_extended_pair(int, int, int);

extern int key_defined (const char *);

extern int keyok (int, 

                                      _Bool

                                          );

extern void reset_color_pairs (void);

extern int resize_term (int, int);

extern int resizeterm (int, int);

extern int set_escdelay (int);

extern int set_tabsize (int);

extern int use_default_colors (void);

extern int use_extended_names (

                                              _Bool

                                                  );

extern int use_legacy_coding (int);

extern int use_screen (SCREEN *, NCURSES_SCREEN_CB, void *);

extern int use_window (WINDOW *, NCURSES_WINDOW_CB, void *);

extern int wresize (WINDOW *, int, int);

extern void nofilter(void);











extern WINDOW * wgetparent (const WINDOW *);

extern 

      _Bool 

                           is_cleared (const WINDOW *);

extern 

      _Bool 

                           is_idcok (const WINDOW *);

extern 

      _Bool 

                           is_idlok (const WINDOW *);

extern 

      _Bool 

                           is_immedok (const WINDOW *);

extern 

      _Bool 

                           is_keypad (const WINDOW *);

extern 

      _Bool 

                           is_leaveok (const WINDOW *);

extern 

      _Bool 

                           is_nodelay (const WINDOW *);

extern 

      _Bool 

                           is_notimeout (const WINDOW *);

extern 

      _Bool 

                           is_pad (const WINDOW *);

extern 

      _Bool 

                           is_scrollok (const WINDOW *);

extern 

      _Bool 

                           is_subwin (const WINDOW *);

extern 

      _Bool 

                           is_syncok (const WINDOW *);

extern int wgetdelay (const WINDOW *);

extern int wgetscrreg (const WINDOW *, int *, int *);

typedef int (*NCURSES_OUTC_sp)(SCREEN*, int);



extern SCREEN * new_prescr (void);



extern int baudrate_sp (SCREEN*);

extern int beep_sp (SCREEN*);

extern 

      _Bool 

                           can_change_color_sp (SCREEN*);

extern int cbreak_sp (SCREEN*);

extern int curs_set_sp (SCREEN*, int);

extern int color_content_sp (SCREEN*, short, short*, short*, short*);

extern int def_prog_mode_sp (SCREEN*);

extern int def_shell_mode_sp (SCREEN*);

extern int delay_output_sp (SCREEN*, int);

extern int doupdate_sp (SCREEN*);

extern int echo_sp (SCREEN*);

extern int endwin_sp (SCREEN*);

extern char erasechar_sp (SCREEN*);

extern void filter_sp (SCREEN*);

extern int flash_sp (SCREEN*);

extern int flushinp_sp (SCREEN*);

extern WINDOW * getwin_sp (SCREEN*, FILE *);

extern int halfdelay_sp (SCREEN*, int);

extern 

      _Bool 

                           has_colors_sp (SCREEN*);

extern 

      _Bool 

                           has_ic_sp (SCREEN*);

extern 

      _Bool 

                           has_il_sp (SCREEN*);

extern int init_color_sp (SCREEN*, short, short, short, short);

extern int init_pair_sp (SCREEN*, short, short, short);

extern int intrflush_sp (SCREEN*, WINDOW*, 

                                                                        _Bool

                                                                            );

extern 

      _Bool 

                           isendwin_sp (SCREEN*);

extern const char * keyname_sp (SCREEN*, int);

extern char killchar_sp (SCREEN*);

extern char * longname_sp (SCREEN*);

extern int mvcur_sp (SCREEN*, int, int, int, int);

extern int napms_sp (SCREEN*, int);

extern WINDOW * newpad_sp (SCREEN*, int, int);

extern SCREEN * newterm_sp (SCREEN*, const char *, FILE *, FILE *);

extern WINDOW * newwin_sp (SCREEN*, int, int, int, int);

extern int nl_sp (SCREEN*);

extern int nocbreak_sp (SCREEN*);

extern int noecho_sp (SCREEN*);

extern int nonl_sp (SCREEN*);

extern void noqiflush_sp (SCREEN*);

extern int noraw_sp (SCREEN*);

extern int pair_content_sp (SCREEN*, short, short*, short*);

extern void qiflush_sp (SCREEN*);

extern int raw_sp (SCREEN*);

extern int reset_prog_mode_sp (SCREEN*);

extern int reset_shell_mode_sp (SCREEN*);

extern int resetty_sp (SCREEN*);

extern int ripoffline_sp (SCREEN*, int, int (*)(WINDOW *, int));

extern int savetty_sp (SCREEN*);

extern int scr_init_sp (SCREEN*, const char *);

extern int scr_restore_sp (SCREEN*, const char *);

extern int scr_set_sp (SCREEN*, const char *);

extern int slk_attroff_sp (SCREEN*, const chtype);

extern int slk_attron_sp (SCREEN*, const chtype);

extern int slk_attrset_sp (SCREEN*, const chtype);

extern attr_t slk_attr_sp (SCREEN*);

extern int slk_attr_set_sp (SCREEN*, const attr_t, short, void*);

extern int slk_clear_sp (SCREEN*);

extern int slk_color_sp (SCREEN*, short);

extern int slk_init_sp (SCREEN*, int);

extern char * slk_label_sp (SCREEN*, int);

extern int slk_noutrefresh_sp (SCREEN*);

extern int slk_refresh_sp (SCREEN*);

extern int slk_restore_sp (SCREEN*);

extern int slk_set_sp (SCREEN*, int, const char *, int);

extern int slk_touch_sp (SCREEN*);

extern int start_color_sp (SCREEN*);

extern chtype termattrs_sp (SCREEN*);

extern char * termname_sp (SCREEN*);

extern int typeahead_sp (SCREEN*, int);

extern int ungetch_sp (SCREEN*, int);

extern void use_env_sp (SCREEN*, 

                                                              _Bool

                                                                  );

extern void use_tioctl_sp (SCREEN*, 

                                                                 _Bool

                                                                     );

extern int vidattr_sp (SCREEN*, chtype);

extern int vidputs_sp (SCREEN*, chtype, NCURSES_OUTC_sp);



extern char * keybound_sp (SCREEN*, int, int);

extern int alloc_pair_sp (SCREEN*, int, int);

extern int assume_default_colors_sp (SCREEN*, int, int);

extern int define_key_sp (SCREEN*, const char *, int);

extern int extended_color_content_sp (SCREEN*, int, int *, int *, int *);

extern int extended_pair_content_sp (SCREEN*, int, int *, int *);

extern int extended_slk_color_sp (SCREEN*, int);

extern int get_escdelay_sp (SCREEN*);

extern int find_pair_sp (SCREEN*, int, int);

extern int free_pair_sp (SCREEN*, int);

extern int init_extended_color_sp (SCREEN*, int, int, int, int);

extern int init_extended_pair_sp (SCREEN*, int, int, int);

extern 

      _Bool 

                           is_term_resized_sp (SCREEN*, int, int);

extern int key_defined_sp (SCREEN*, const char *);

extern int keyok_sp (SCREEN*, int, 

                                                                _Bool

                                                                    );

extern void nofilter_sp (SCREEN*);

extern void reset_color_pairs_sp (SCREEN*);

extern int resize_term_sp (SCREEN*, int, int);

extern int resizeterm_sp (SCREEN*, int, int);

extern int set_escdelay_sp (SCREEN*, int);

extern int set_tabsize_sp (SCREEN*, int);

extern int use_default_colors_sp (SCREEN*);

extern int use_legacy_coding_sp (SCREEN*, int);

extern WINDOW * curscr;

extern WINDOW * newscr;

extern WINDOW * stdscr;

extern char ttytype[];

extern int COLORS;

extern int COLOR_PAIRS;

extern int COLS;

extern int ESCDELAY;

extern int LINES;

extern int TABSIZE;

typedef struct

{

    short id;

    int x, y, z;

    mmask_t bstate;

}

MEVENT;



extern 

      _Bool 

                              has_mouse(void);

extern int getmouse (MEVENT *);

extern int ungetmouse (MEVENT *);

extern mmask_t mousemask (mmask_t, mmask_t *);

extern 

      _Bool 

                              wenclose (const WINDOW *, int, int);

extern int mouseinterval (int);

extern 

      _Bool 

                              wmouse_trafo (const WINDOW*, int*, int*, 

                                                                       _Bool

                                                                           );

extern 

      _Bool 

                              mouse_trafo (int*, int*, 

                                                       _Bool

                                                           );





extern 

      _Bool 

                              has_mouse_sp (SCREEN*);

extern int getmouse_sp (SCREEN*, MEVENT *);

extern int ungetmouse_sp (SCREEN*,MEVENT *);

extern mmask_t mousemask_sp (SCREEN*, mmask_t, mmask_t *);

extern int mouseinterval_sp (SCREEN*, int);

extern int mcprint (char *, int);

extern int has_key (int);





extern int has_key_sp (SCREEN*, int);

extern int mcprint_sp (SCREEN*, char *, int);









extern void _tracef (const char *, ...) ;

extern char * _traceattr (attr_t);

extern char * _traceattr2 (int, chtype);

extern char * _tracechar (int);

extern char * _tracechtype (chtype);

extern char * _tracechtype2 (int, chtype);

extern void trace (const unsigned int);
