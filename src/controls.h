#ifndef CONTROLS_H

#include <keypadc.h>
#include "pieces.h"
#include "grid.h"

bool wasPressed = false;
bool isPressed = false;

bool down   (Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]);
void left   (Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]);
void right  (Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]);

void solidify(Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]);

void rotateClockwise(Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]);
void rotateCounterClockwise(Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]);

#define CONTROLS_H
#endif
