#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/ioctl.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define ESC "\x1b"
#define BEEP "\a"
#define SLEEP_TIME_UNIX 50000
#define SLEEP_TIME_WIN 500
#define LEN 30

#define set_background(color) printf(ESC"[%dm", color+40)
#define set_foreground(color) printf(ESC"[%dm", color+30)
#define set_window_witdth(width) printf(ESC"[=%dh", width)
#define clear_screen() system("clear")
#define hide_cursor() printf(ESC"[?25l")
#define print_square() printf("%s ", unit_sqare);

enum {
    BLACK,
    RED,
    GREEN,
    YELLOW, 
    BLUE,
    MAGENTA,
    CYAN, 
    WHITE,
    DEFAULT
};

extern int to_sort[LEN];
extern char stage_name[1024];

void draw_frame(int*, int, int);
void swap(int*, int, int);
void shuffle(int*);
void init_window(void);
void visu(void(int*, int), char*);