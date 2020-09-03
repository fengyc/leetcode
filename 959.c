#include <stdlib.h>
#include <string.h>

void fill(char **matrix, int rows, int cols, int i, int j) {
    matrix[i][j] = 1;
    if (i > 0 && matrix[i - 1][j] == 0) {
        fill(matrix, rows, cols, i - 1, j);
    }
    if (j < cols - 1 && matrix[i][j + 1] == 0) {
        fill(matrix, rows, cols, i, j + 1);
    }
    if (i < rows - 1 && matrix[i + 1][j] == 0) {
        fill(matrix, rows, cols, i + 1, j);
    }
    if (j > 0 && matrix[i][j - 1] == 0) {
        fill(matrix, rows, cols, i, j - 1);
    }
}

int regionsBySlashes(char **grid, int gridSize) {
    int grows = gridSize;
    int gcols = strlen(grid[0]);
    int mrows = grows * 3;
    int mcols = grows * 3;

    char **matrix = malloc(mrows * sizeof(char *));
    for (int i = 0; i < mrows; i++) {
        matrix[i] = calloc(mcols, sizeof(char));
    }

    for (int i = 0; i < grows; i++) {
        for (int j = 0; j < gcols; j++) {
            int mi = i * 3;
            int mj = j * 3;
            switch (grid[i][j]) {
                case '/':
                    matrix[mi][mj + 2] = 1;
                    matrix[mi + 1][mj + 1] = 1;
                    matrix[mi + 2][mj] = 1;
                    break;
                case '\\':
                    matrix[mi][mj] = 1;
                    matrix[mi + 1][mj + 1] = 1;
                    matrix[mi + 2][mj + 2] = 1;
                    break;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < mrows; i++) {
        for (int j = 0; j < mcols; j++) {
            if (matrix[i][j] == 0) {
                count++;
                fill(matrix, mrows, mcols, i, j);
            }
        }
    }
    return count;
}