#include "Console.h"

void setColor(ColorType color) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
#else
    printf("%s", color);
#endif
}

void resetConsole(){
    #ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
    printf("\033[H\033[J");
    GetConsoleMode(hOut, &dwMode);
    dwMode &= ~ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
    #else
    printf("\033[H\033[J");
    #endif
}

void clearConsole(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

#ifndef _WIN32
int kbhit() {
    struct termios oldt, newt;
    int oldf;
    char ch;
    int byteswaiting;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    byteswaiting = read(STDIN_FILENO, &ch, 1);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (byteswaiting == 1) {
        return ch;
    }
    return 0; // No input
}
#endif

Console new_Console(void){
    Console console;
    console.setColor = setColor;
    console.resetConsole = resetConsole;
    console.clearConsole = clearConsole;
    console.kbhit = kbhit;
    return console;
}