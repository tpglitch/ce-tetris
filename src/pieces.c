#include <tice.h>

#include "pieces.h"

Piece createSquare() {
    Piece piece = {
        // Blocks positions
        // oa
        // aa
        {
            { 4, 1 },
            { 5, 1 },
            { 4, 2 },
            { 5, 2 }
        },
        // Color
        0xE6
    };

    return piece;
}

Piece createBar() {
    Piece piece = {
        // Blocks positions
        // aoaa
        {
            { 4, 1 },
            { 3, 1 },
            { 5, 1 },
            { 6, 1 }
        },
        // Color
        0x33
    };

    return piece;
}

Piece createL() {
    Piece piece = {
        // Blocks positions
        // aoa
        // a
        {
            { 6, 1 },
            { 5, 1 },
            { 7, 1 },
            { 5, 2 }
        },
        // Color
        0x13
    };

    return piece;
}

Piece createReverseL() {
    Piece piece = {
        // Blocks positions
        // aoa
        //   a
        {
            { 6, 1 },
            { 5, 1 },
            { 7, 1 },
            { 7, 2 }
        },
        // Color
        0xE3
    };

    return piece;
}

Piece createStairs() {
    Piece piece = {
        // Blocks positions
        //  oa
        // aa
        {
            { 5, 1 },
            { 6, 1 },
            { 4, 2 },
            { 5, 2 }
        },
        // Color
        0x25
    };

    return piece;
}

Piece createReverseStairs() {
    Piece piece = {
        // Blocks positions
        // ao
        //  aa
        {
            { 5, 1 },
            { 4, 1 },
            { 5, 2 },
            { 6, 2 }
        },
        // Color
        0xC0
    };

    return piece;
}

Piece createT() {
    Piece piece = {
        // Blocks positions
        // aoa
        //  a
        {
            { 6, 1 },
            { 5, 1 },
            { 7, 1 },
            { 6, 2 }
        },
        // Color
        0x51
    };

    return piece;
}

Piece createRandomPiece() {
    unsigned int rand = randInt(0, 6);
    switch (rand) {
        case 0:
            return createSquare();
        case 1:
            return createBar();
        case 2:
            return createL();
        case 3:
            return createReverseL();
        case 4:
            return createStairs();
        case 5:
            return createReverseStairs();
        case 6:
        default:
            return createT();
    }
}
