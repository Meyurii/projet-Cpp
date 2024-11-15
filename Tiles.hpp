#ifndef TILE_HPP
#define TILE_HPP

#include <vector>
#include "Color.hpp"

class Tile {
public:
    // attribu l'id joueur et couleur a la piece
    Tile(int playerID, int pieceID, Color color)
        : playerID(playerID), color(color) {
        setShape(pieceID);
    }

    // verifier si possible de placer
    bool canPlace(const std::vector<std::vector<int>>& board, int x, int y) const {
        int n = shape.size();
        if (x + n > board.size() || y + n > board[0].size()) return false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (shape[i][j] == 1 && board[x + i][y + j] != 0) return false;
            }
        }
        return true;
    }

    const std::vector<std::vector<int>>& getShape() const { return shape; }
    int getPlayerID() const { return playerID; }
    Color getColor() const { return color; }

private:
    int playerID;
    std::vector<std::vector<int>> shape;
    Color color;


    void setShape(int pieceID) {
        static const std::vector<std::vector<std::vector<int>>> shapes = {
            // Piece 1
            {{1, 0, 0}, {1, 1, 1}},
            // Piece 2
            {{0, 0, 1}, {1, 1, 1}, {0, 0, 1}},
            // Piece 3
            {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}},
            // Piece 4
            {{0, 0, 1}, {1, 1, 1}, {1, 0, 0}},
            // Piece 5
            {{0, 1, 0}, {1, 1, 1}},
            // Piece 6
            {{1, 1}, {1, 1}},
            // Piece 7
            {{1, 0, 1}, {1, 1, 1}},
            // Piece 8
            {{1, 1, 1}},
            // Piece 9
            {{0, 1}, {1, 1}, {1, 0}},
            // Piece 10
            {{1}, {1, 1}},
            // Piece 11
            {{0, 0, 1}, {0, 1, 1}, {1, 1}},
            // Piece 12
            {{1, 1}},
            // Piece 13
            {{0, 1}, {1, 1}, {1}},
            // Piece 14
            {{1, 1, 1}, {1}, {1}, {1}},
            // Piece 15
            {{0, 1}, {1, 1, 1}, {1, 1}},
            // Piece 16
            {{1, 1, 1}},
            // Piece 17
            {{1}, {1, 1}, {1}, {1}},
            // Piece 18
            {{0, 1, 1}, {1, 1}},
            // Piece 19
            {{0, 1}, {1, 1}, {1, 1, 1}},
            // Piece 20
            {{0, 0, 1}, {1, 1, 1}, {1}},
            // Piece 21
            {{1}, {1, 1}},
            // Piece 22
            {{1, 1}, {1, 1}, {1, 1}},
            // Piece 23
            {{1, 1, 1}, {0, 1}, {0, 1}},
            // Piece 24
            {{1}, {1, 1}, {0, 1, 1}},
            // Piece 25
            {{1, 1, 1, 1, 1}},
            // Piece 26
            {{1}, {1, 1, 1}, {0, 1}},
            // Piece 27
            {{1}, {1, 1}, {1}, {1, 1}},
            // Piece 28
            {{1}, {1, 1}, {1, 1}},
            // Piece 29
            {{1}, {1, 1, 1}, {1, 0, 1}},
            // Piece 30
            {{0, 1}, {1, 1}, {1}},
            // Piece 31
            {{1, 1}, {0, 1}, {0, 1, 1}},
            // Piece 32
            {{1}, {1}, {1, 1}, {1}},
            // Piece 33
            {{0, 1}, {1, 1}},
            // Piece 34
            {{1, 0, 0, 1}, {1, 1, 1, 1}},
            // Piece 35
            {{0, 1, 1}, {1, 0, 1, 1}},
            // Piece 36
            {{1}, {1}, {1, 1, 1}},
            // Piece 37
            {{1, 1}, {0, 1, 1}, {1}},
            // Piece 38
            {{1}, {1, 1}, {1, 1}},
            // Piece 39
            {{0, 1}, {1, 1, 1, 1}},
            // Piece 40
            {{1, 1}, {1, 1}},
            // Piece 41
            {{0, 1}, {1, 1}, {1}},
            // Piece 42
            {{1, 1, 1}, {0, 1}, {1, 1}},
            // Piece 43
            {{1}, {1}, {1, 1, 1, 1}},
            // Piece 44
            {{0, 1, 1}, {1, 1, 0, 1}},
            // Piece 45
            {{1, 0, 0, 1}, {1, 0, 0, 1}},
            // Piece 46
            {{1}, {1, 1, 1}},
            // Piece 47
            {{1}, {1, 1}, {1}},
            // Piece 48
            {{0, 1, 1, 1, 1}},
            // Piece 49
            {{0, 1, 1, 1, 1}},
            // Piece 50
            {{1, 1, 1, 1}},
            // Piece 51
            {{1, 1, 1}},
            // Piece 52
            {{0, 1, 1}, {1}},
            // Piece 53
            {{0, 1, 1}},
            // Piece 54
            {{1}, {1}, {1}},
            // Piece 55
            {{1, 1, 1, 1, 1}},
            // Piece 56
            {{0, 1}, {1}}
            // Piece 57
            {{0, 1, 1}, {0, 1}, {1, 1, 1}},
            // Piece 58
            {{1}, {1}, {1, 1}, {1}, {1}},
            // Piece 59
            {{1, 1}, {0, 1}, {0, 1, 0, 1}, {1, 1, 1, 1}},
            // Piece 60
            {{0, 0, 1}, {0, 1, 1}, {1, 1}, {1}, {1, 1}},
            // Piece 70
            {{0, 1, 1}, {0, 1}, {0, 1}, {1, 1}, {1}},
            // Piece 71
            {{1, 0, 0, 1}, {1, 1, 1, 1}},
            // Piece 72
            {{1, 1}, {0, 1, 0, 1}, {0, 1, 0, 1}, {1, 1, 1}},
            // Piece 73
            {{1}, {1, 1}, {1}, {1}, {1}},
            // Piece 74
            {{1}, {1, 0, 1}, {1, 1, 1, 1}, {0, 1}},
            // Piece 75
            {{1, 1}, {1}, {1}, {1}, {1}, {1}, {1}},
            // Piece 76
            {{0, 1}, {1, 1, 1}, {1}},
            // Piece 77
            {{1, 1}},
            // Piece 78
            {{0, 0, 1}, {1, 0, 1}, {1, 1, 1}},
            // Piece 79
            {{0, 1}, {1, 1, 1}, {1, 0, 1}},
            // Piece 80
            {{0, 0, 1}, {0, 0, 1}, {1, 1, 1, 1, 1}, {0, 0, 1}, {0, 0, 1}},
            // Piece 81
            {{0, 0, 0, 1}, {0, 1, 1}, {0, 1}, {0, 1}, {1, 1}, {1, 1}},
            // Piece 82
            {{1, 1}, {1}, {1, 1}, {1}, {1, 1}},
            // Piece 83
            {{0, 1}, {0, 1}, {0, 1}, {1, 1, 1, 1}, {0, 1}},
            // Piece 84
            {{0, 1}, {1, 1}, {1}, {1}, {1}},
            // Piece 85
            {{0, 1, 1}, {0, 1}, {1, 1}, {1}},
            // Piece 86
            {{0, 1, 1}, {0, 1}, {1, 1}, {0, 1, 1}, {0, 1}, {0, 1}},
            // Piece 87
            {{1, 1}, {1, 1}, {0, 1, 1}, {0, 1}, {0, 1}, {0, 1}},
            // Piece 88
            {{0, 1}, {0, 1, 1}, {1, 1}, {0, 1}},
            // Piece 89
            {{1, 1}, {1, 1, 1, 1}},
            // Piece 90
            {{0, 0, 1, 1}, {1, 1, 1}, {1}, {1, 1}},
            // Piece 91
            {{0, 0, 1, 1}, {0, 1}, {0, 1}, {1, 1}},
            // Piece 92
            {{0, 1}, {0, 1}, {1, 1, 1}, {0, 1}},
            // Piece 93
            {{1, 1, 1}, {1, 0, 1}, {1}, {1, 1}},
            // Piece 94
            {{0, 1}, {0, 1, 1}, {1, 1}, {1}},
            // Piece 95
            {{1}, {1, 1}, {1, 1, 1}},
            // Piece 96
            {{1}, {1}, {1}, {1, 1}},
            // Piece 97
            {{0, 1}, {1, 1, 1, 1}, {1}},
            // Piece 98
            {{0, 1, 1}, {1, 1}, {1}},
            // Piece 99
            {{0, 1}, {1, 1}, {1}, {1, 1}}
        };

        if (pieceID >= 1 && pieceID <= shapes.size()) {
            shape = shapes[pieceID - 1];
        } else {
            shape = {{1}};
        }
    }
};

#endif // TILES_HPP
