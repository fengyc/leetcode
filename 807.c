#include <stdlib.h>
#include <string.h>

int maxIncreaseKeepingSkyline(int **grid, int gridRowSize, int *gridColSizes) {
    int sum = 0;
    int *rowH = malloc(sizeof(int) * gridRowSize);

    int gridColSize = gridColSizes[0];
    int *colH = malloc(sizeof(int) * gridColSizes[0]);

    for (int i = 0; i < gridRowSize; i++) {
        rowH[i] = 0;
        int *row = grid[i];
        for (int j = 0; j < gridColSize; j++) {
            int h = row[j];
            if (rowH[i] < h) {
                rowH[i] = h;
            }
        }
    }

    for (int i = 0; i < gridColSize; i++) {
        colH[i] = 0;
        for (int j = 0; j < gridRowSize; j++) {
            int *row = grid[j];
            int h = row[i];
            if (colH[i] < h) {
                colH[i] = h;
            }
        }
    }

    for (int i = 0; i < gridRowSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            int *row = grid[i];
            int m = rowH[i] < colH[j] ? rowH[i] : colH[j];
            sum += m - row[j];
        }
    }

    return sum;
}

int main() {
    int *g[4];
    g[0] =
            {3, 0, 8, 4};
            {2, 4, 5, 7},
            {9, 2, 6, 3},
            {0, 3, 1, 0}
    };
    int cols[4] = {
            4, 4, 4, 4
    };
    int r = maxIncreaseKeepingSkyline(g, 4, cols);
    return 0;
}