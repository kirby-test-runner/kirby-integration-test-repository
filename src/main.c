#include "board.h"
#include "render.h"
#include "input.h"

int main(void) {
    Board board;
    board_init(&board);
    input_enable_raw();

    int running = 1;
    while (running) {
        render_board(&board);

        if (board_has_won(&board)) {
            render_win(&board);
            break;
        }
        if (board_is_game_over(&board)) {
            render_game_over(&board);
            break;
        }

        InputKey key = input_read();
        int moved = 0;
        switch (key) {
            case INPUT_LEFT:  moved = board_move_left(&board);  break;
            case INPUT_RIGHT: moved = board_move_right(&board); break;
            case INPUT_UP:    moved = board_move_up(&board);    break;
            case INPUT_DOWN:  moved = board_move_down(&board);  break;
            case INPUT_QUIT:  running = 0; break;
            default: break;
        }

        if (moved) {
            board_add_random_tile(&board);
        }
    }

    input_disable_raw();
    return 0;
}
