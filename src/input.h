#ifndef INPUT_H
#define INPUT_H

typedef enum {
    INPUT_UP,
    INPUT_DOWN,
    INPUT_LEFT,
    INPUT_RIGHT,
    INPUT_QUIT,
    INPUT_AUTO,
    INPUT_NONE
} InputKey;

InputKey input_read(void);
void input_enable_raw(void);
void input_disable_raw(void);

#endif
