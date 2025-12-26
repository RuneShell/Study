// Project 4-1
// DFS : Recursion
// DFS.hpp

#include <iostream>
#define MAZE_SIZE 6

struct location {
    int col;
    int row;
    location(int r, int c) : row(r), col(c) {};
};

void printLocation(location l) {
    std::cout << "[ " << l.row << ", " << l.col << " ]\n";
}

bool mazeExplorerRecursive(char map[][MAZE_SIZE], location entryPoint, location exitPoint) {

    int adjacent_pair[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // (y, x)

    printLocation(entryPoint);
    int x = entryPoint.col;
    int y = entryPoint.row;
    map[y][x] = '.';

    // check if exitPoint
    if (entryPoint.row == exitPoint.row && entryPoint.col == exitPoint.col) {
        return true;
    }

    for (int i = 0; i < 4; i++) {
        int xx = x + adjacent_pair[i][0];
        int yy = y + adjacent_pair[i][1];

        // check if (range is valid)
        if (!(0 <= xx && xx < MAZE_SIZE && 0 <= yy && yy < MAZE_SIZE)) continue;
        // check if (unvisited)
        else if (map[yy][xx] == '0') {
            bool isFound = mazeExplorerRecursive(map, location(yy, xx), exitPoint);
            if (isFound) return true;
        }
    }

    return false;
}