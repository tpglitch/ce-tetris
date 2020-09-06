#ifndef GRID_H

#include "pieces.h"

#define GRID_HEIGHT 26
#define GRID_WIDTH 10
#define CELL_SIZE 8
#define GRID_MARGIN 16

void drawGrid(unsigned char grid[GRID_HEIGHT][GRID_WIDTH]);
void drawPiece(Piece *piece);

#define GRID_H
#endif
