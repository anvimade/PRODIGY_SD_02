#include <stdio.h>
#define N 9

// Function to print the solved Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%2d", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if the current number can be placed at grid[row][col]
int isSafe(int grid[N][N], int row, int col, int num) {
    // Check if the number is not already present in the current row, current column, and current 3x3 subgrid
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num || grid[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) {
            return 0;
        }
    }
    return 1;
}

// Function to solve the Sudoku puzzle using backtracking
int solveSudoku(int grid[N][N]) {
    int row, col;

    // Find an empty cell in the grid
    int isEmpty = 1;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = 0;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    // If there is no empty cell, the puzzle is solved
    if (isEmpty) {
        return 1;
    }

    // Try placing numbers 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num; // Place the number if it is safe

            // Recursively solve the rest of the puzzle
            if (solveSudoku(grid)) {
                return 1; // If the puzzle is solved, return true
            }

            grid[row][col] = 0; // If placing num does not lead to a solution, backtrack
        }
    }
    return 0; // No solution exists for the current configuration
}

int main() {
    int grid[N][N];

    printf("Enter the Sudoku grid (use 0 for empty cells):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    if (solveSudoku(grid)) {
        printf("\nSudoku solved successfully!\n\n");
        printGrid(grid);
    } else {
        printf("\nNo solution exists for the given Sudoku puzzle.\n");
    }

    return 0;
}
