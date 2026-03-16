#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 4
#define INITIAL_TILES 2

typedef struct {
    int cells[BOARD_SIZE][BOARD_SIZE];
    int score;
    int moved;
} Board;

void board_init(Board *board);
void board_add_random_tile(Board *board);
int board_move_left(Board *board);
int board_move_right(Board *board);
int board_move_up(Board *board);
int board_move_down(Board *board);
int board_is_game_over(Board *board);
int board_has_won(Board *board);
int board_count_empty(const Board *board);

#endif
