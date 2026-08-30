#include "board.h"
#include "render.h"
#include "input.h"
#include "solver.h"
#include <unistd.h>

static void perform_move(Board *board, int direction) {
    int moved = 0;
    switch (direction) {
        case 0: moved = board_move_left(board);  break;
        case 1: moved = board_move_right(board); break;
        case 2: moved = board_move_up(board);    break;
        case 3: moved = board_move_down(board);  break;
    }
    if (moved) {
        board_add_random_tile(board);
    }
}

int main(void) {
    Board board;
    board_init(&board);
    input_enable_raw();

    int running = 1;
    int auto_play = 0;

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

        if (auto_play) {
            int dir = solver_best_move(&board);
            perform_move(&board, dir);
            usleep(100000);  /* 100ms delay for visibility */
            continue;
        }

        InputKey key = input_read();
        switch (key) {
            case INPUT_LEFT:  perform_move(&board, 0); break;
            case INPUT_RIGHT: perform_move(&board, 1); break;
            case INPUT_UP:    perform_move(&board, 2); break;
            case INPUT_DOWN:  perform_move(&board, 3); break;
            case INPUT_AUTO:  auto_play = !auto_play;  break;
            case INPUT_QUIT:  running = 0; break;
            default: break;
        }
    }

    input_disable_raw();
    return 0;
}
