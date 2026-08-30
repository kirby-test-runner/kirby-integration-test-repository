#include "input.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

static struct termios orig_termios;

void input_enable_raw(void) {
    tcgetattr(STDIN_FILENO, &orig_termios);
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);
    raw.c_cc[VMIN] = 1;
    raw.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void input_disable_raw(void) {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

InputKey input_read(void) {
    char c;
    if (read(STDIN_FILENO, &c, 1) != 1) return INPUT_NONE;
    if (c == 'q' || c == 'Q') return INPUT_QUIT;
    if (c == 'a' || c == 'A') return INPUT_AUTO;
    if (c == '\033') {
        char seq[2];
        if (read(STDIN_FILENO, &seq[0], 1) != 1) return INPUT_NONE;
        if (read(STDIN_FILENO, &seq[1], 1) != 1) return INPUT_NONE;
        if (seq[0] == '[') {
            switch (seq[1]) {
                case 'A': return INPUT_UP;
                case 'B': return INPUT_DOWN;
                case 'C': return INPUT_RIGHT;
                case 'D': return INPUT_LEFT;
            }
        }
    }
    return INPUT_NONE;
}
