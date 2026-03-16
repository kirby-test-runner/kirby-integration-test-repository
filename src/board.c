#include "board.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

void board_init(Board *board) {
    memset(board->cells, 0, sizeof(board->cells));
    board->score = 0;
    board->moved = 0;
    srand((unsigned)time(NULL));
    for (int i = 0; i < INITIAL_TILES; i++) {
        board_add_random_tile(board);
    }
}

int board_count_empty(const Board *board) {
    int count = 0;
    for (int r = 0; r < BOARD_SIZE; r++)
        for (int c = 0; c < BOARD_SIZE; c++)
            if (board->cells[r][c] == 0) count++;
    return count;
}

void board_add_random_tile(Board *board) {
    int empty = board_count_empty(board);
    if (empty == 0) return;
    int target = rand() % empty;
    int idx = 0;
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            if (board->cells[r][c] == 0) {
                if (idx == target) {
                    board->cells[r][c] = (rand() % 10 < 9) ? 2 : 4;
                    return;
                }
                idx++;
            }
        }
    }
}

static int merge_line(int line[BOARD_SIZE], int *score) {
    int moved = 0;
    /* Compact non-zero to front */
    int tmp[BOARD_SIZE] = {0};
    int pos = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (line[i] != 0) {
            if (pos != i) moved = 1;
            tmp[pos++] = line[i];
        }
    }
    /* Merge adjacent equal tiles */
    for (int i = 0; i < BOARD_SIZE - 1; i++) {
        if (tmp[i] != 0 && tmp[i] == tmp[i + 1]) {
            tmp[i] *= 2;
            *score += tmp[i];
            tmp[i + 1] = 0;
            moved = 1;
        }
    }
    /* Compact again after merge */
    pos = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (tmp[i] != 0) line[pos++] = tmp[i];
    }
    for (; pos < BOARD_SIZE; pos++) line[pos] = 0;
    return moved;
}

int board_move_left(Board *board) {
    int moved = 0;
    for (int r = 0; r < BOARD_SIZE; r++)
        moved |= merge_line(board->cells[r], &board->score);
    return moved;
}

int board_move_right(Board *board) {
    int moved = 0;
    for (int r = 0; r < BOARD_SIZE; r++) {
        int rev[BOARD_SIZE];
        for (int c = 0; c < BOARD_SIZE; c++) rev[c] = board->cells[r][BOARD_SIZE - 1 - c];
        moved |= merge_line(rev, &board->score);
        for (int c = 0; c < BOARD_SIZE; c++) board->cells[r][BOARD_SIZE - 1 - c] = rev[c];
    }
    return moved;
}

int board_move_up(Board *board) {
    int moved = 0;
    for (int c = 0; c < BOARD_SIZE; c++) {
        int col[BOARD_SIZE];
        for (int r = 0; r < BOARD_SIZE; r++) col[r] = board->cells[r][c];
        moved |= merge_line(col, &board->score);
        for (int r = 0; r < BOARD_SIZE; r++) board->cells[r][c] = col[r];
    }
    return moved;
}

int board_move_down(Board *board) {
    int moved = 0;
    for (int c = 0; c < BOARD_SIZE; c++) {
        int col[BOARD_SIZE];
        for (int r = 0; r < BOARD_SIZE; r++) col[r] = board->cells[BOARD_SIZE - 1 - r][c];
        moved |= merge_line(col, &board->score);
        for (int r = 0; r < BOARD_SIZE; r++) board->cells[BOARD_SIZE - 1 - r][c] = col[r];
    }
    return moved;
}

int board_is_game_over(Board *board) {
    if (board_count_empty(board) > 0) return 0;
    for (int r = 0; r < BOARD_SIZE; r++)
        for (int c = 0; c < BOARD_SIZE - 1; c++)
            if (board->cells[r][c] == board->cells[r][c + 1]) return 0;
    for (int c = 0; c < BOARD_SIZE; c++)
        for (int r = 0; r < BOARD_SIZE - 1; r++)
            if (board->cells[r][c] == board->cells[r + 1][c]) return 0;
    return 1;
}

int board_has_won(Board *board) {
    for (int r = 0; r < BOARD_SIZE; r++)
        for (int c = 0; c < BOARD_SIZE; c++)
            if (board->cells[r][c] == 2048) return 1;
    return 0;
}
