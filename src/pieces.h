#ifndef PIECES_H
#include "grid.h"

struct Piece createSquare           ();
struct Piece createBar              ();
struct Piece createL                ();
struct Piece createReverseL         ();
struct Piece createStairs           ();
struct Piece createReverseStairs    ();
struct Piece createT                ();

struct Piece createRandomPiece();

#define PIECES_H
#endif
