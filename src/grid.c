#include <graphx.h>

#include "grid.h"

void drawGrid(unsigned char grid[GRID_HEIGHT][GRID_WIDTH]) {
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            gfx_SetColor(grid[y][x]);
            gfx_FillRectangle_NoClip(x*CELL_SIZE+GRID_MARGIN, y*CELL_SIZE+GRID_MARGIN, CELL_SIZE, CELL_SIZE);
        }
    }
}

void drawPiece(Piece *piece) {
    // Loops through the blocks of the piece
    for (int i = 0; i < 4; i++) {
        Pos position = piece->blocks[i];
        gfx_SetColor(piece->color);
        gfx_FillRectangle_NoClip(position.x*CELL_SIZE+GRID_MARGIN, position.y*CELL_SIZE+GRID_MARGIN, CELL_SIZE, CELL_SIZE);
    }
}

void checkForLines(unsigned char grid[GRID_HEIGHT][GRID_WIDTH]) {
    int offset = 0;
    for (int y = GRID_HEIGHT-1; y >= 0; y--) {
        int cells = 0;
        for (int i = 0; i < GRID_WIDTH; i++) {
            if (grid[y][i] != 0x00) cells++;
        }

        if (cells == GRID_WIDTH) {
            offset++;
        }

        for (int x = 0; x < GRID_WIDTH; x++) {
            grid[y+offset][x] = grid[y][x];
        }
    }
}
