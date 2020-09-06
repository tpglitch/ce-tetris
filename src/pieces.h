#ifndef PIECES_H

struct Pos {
    int x;
    int y;
};

struct Piece {
    struct Pos blocks[4];
    char color;
};

typedef struct Pos Pos;
typedef struct Piece Piece;

Piece createSquare          ();
Piece createBar             ();
Piece createL               ();
Piece createReverseL        ();
Piece createStairs          ();
Piece createReverseStairs   ();
Piece createT               ();
Piece createRandomPiece     ();

#define PIECES_H
#endif
