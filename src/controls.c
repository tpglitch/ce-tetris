#include "controls.h"

typedef struct Pos Pos;
typedef struct Piece Piece;

bool down(Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]) {
    bool fit = true;

    for (int i = 0; i < 4; i++) {
        Pos block = piece->blocks[i];
        if (block.y+1 == GRID_HEIGHT || grid[block.y+1][block.x] != 0x00) {
            fit = false;
            break;
        }
    }

    if (fit) {
        for (int i = 0; i < 4; i++) {
            piece->blocks[i].y++;
        }
        return false;
    } else {
        solidify(piece, grid);
        return true;
    }
}

void left(Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]) {
    bool fit = true;

    for (int i = 0; i < 4; i++) {
        Pos block = piece->blocks[i];
        if (block.x-1 == -1 || grid[block.y][block.x-1] != 0x00) {
            fit = false;
            break;
        }
    }

    if (fit) for (int i = 0; i < 4; i++) {
        piece->blocks[i].x--;
    }
}

void right(Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]) {
    bool fit = true;

    for (int i = 0; i < 4; i++) {
        Pos block = piece->blocks[i];
        if (block.x+1 == GRID_WIDTH || grid[block.y][block.x+1] != 0x00) {
            fit = false;
            break;
        }
    }

    if (fit) for (int i = 0; i < 4; i++) {
        piece->blocks[i].x++;
    }
}

void solidify(Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]) {
    for (int i = 0; i < 4; i++) {
        Pos block = piece->blocks[i];
        grid[block.y][block.x] = piece->color;
    }

    Piece newPiece = {
        // Blocks positions
        {
            { 1, 1 },
            { 2, 1 },
            { 3, 1 },
            { 4, 1 }
        },
        // Anchor
        { 1, 1 },
        // Color
        0x3C
    };

    *piece = newPiece;
}
