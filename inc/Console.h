#include "main.h"

#ifndef __CONSOLE_H
#define __CONSOLE_H

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
typedef int32_t ColorType;
#define BLACK       0
#define DARKBLUE    1
#define DARKGREEN   2
#define DARKCYAN    3
#define DARKRED     4
#define DARKMAGENTA 5
#define DARKYELLOW  6
#define GRAY        7
#define DARKGRAY    8
#define BLUE        9
#define GREEN       10
#define CYAN        11
#define RED         12
#define MAGENTA     13
#define YELLOW      14
#define WHITE       15
#define RESET       15
#else
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
typedef const char* ColorType;
#define BLACK       "\x1b[30m"
#define DARKBLUE    "\x1b[34m"
#define DARKGREEN   "\x1b[32m"
#define DARKCYAN    "\x1b[36m"
#define DARKRED     "\x1b[31m"
#define DARKMAGENTA "\x1b[35m"
#define DARKYELLOW  "\x1b[33m"
#define GRAY        "\x1b[37m"
#define DARKGRAY    "\x1b[90m"
#define BLUE        "\x1b[94m"
#define GREEN       "\x1b[92m"
#define CYAN        "\x1b[96m"
#define RED         "\x1b[91m"
#define MAGENTA     "\x1b[95m"
#define YELLOW      "\x1b[93m"
#define WHITE       "\x1b[97m"
#define RESET       "\x1b[0m"
#endif

typedef struct Console {
    void (*setColor)(ColorType);
    void (*reset)(void);
    void (*clear)(void);
    int (*kbhit)(void);
} Console;

Console new_Console(void);

#endif