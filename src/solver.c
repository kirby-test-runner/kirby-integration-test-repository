#include "solver.h"
#include <string.h>

/* Try a move on a copy of the board, return score delta + heuristic. */
static int try_move(const Board *board, int direction) {
    Board copy;
    memcpy(&copy, board, sizeof(Board));

    int moved = 0;
    switch (direction) {
        case 0: moved = board_move_left(&copy);  break;
        case 1: moved = board_move_right(&copy); break;
        case 2: moved = board_move_up(&copy);    break;
        case 3: moved = board_move_down(&copy);  break;
    }

    if (!moved) return -1;

    int score_gain = copy.score - board->score;
    int heuristic = evaluate_board_heuristic(&copy);
    return score_gain + heuristic;
}

int solver_best_move(const Board *board) {
    int best_dir = 0;
    int best_score = -1;

    for (int dir = 0; dir < 4; dir++) {
        int score = try_move(board, dir);
        if (score > best_score) {
            best_score = score;
            best_dir = dir;
        }
    }

    return best_dir;
}

/* NOTE: evaluate_board_heuristic is declared in solver.h but the
 * implementation is not yet written — this will cause a linker error.
 * The heuristic needs to evaluate empty cells, monotonicity, and
 * corner strategy. Planned for a follow-up commit. */
