#include "pieces.h"

struct Piece createSquare() {
    return {
        // Blocks positions
        {
            { 4, 1 },
            { 5, 1 },
            { 4, 2 },
            { 5, 2 }
        },
        // Color
        0x7f
    };
}
