#include <bits/stdc++.h>
using namespace std;

const int N = 9;

bool possible(int grid[N][N], int row, int col, int k) {
    for (int i = 0; i < N; i++) {
        if (grid[i][col] == k) {
            return false;
        }
        if (grid[row][i] == k) {
            return false;
        }
        if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == k) {
            return false;
        }
    }
    return true;
}

bool SolveSudoku(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                for (int k = 1; k <= 9; k++) {
                    if (possible(grid, i, j, k)) {
                        grid[i][j] = k;
                        if (SolveSudoku(grid)) {
                            return true;
                        } else {
                            grid[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int grid[N][N] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    if (SolveSudoku(grid)) {
        printGrid(grid);
    } else {
        cout << "Sudoku cannot be solved" << endl;
    }

    return 0;
}
