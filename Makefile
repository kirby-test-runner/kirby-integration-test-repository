CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = src/main.c src/board.c src/render.c src/input.c
OUT = game2048

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)

.PHONY: all clean
