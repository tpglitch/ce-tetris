#ifndef GRID_H

#define GRID_HEIGHT 26
#define GRID_WIDTH 10
#define CELL_SIZE 8
#define GRID_MARGIN 16

struct Pos {
    int x;
    int y;
};

struct Piece {
    struct Pos blocks[4];
    char color;
};

void drawGrid(unsigned char grid[GRID_HEIGHT][GRID_WIDTH]);
void drawPiece(struct Piece *piece);

#define GRID_H
#endif
