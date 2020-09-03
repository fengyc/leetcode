#include <stdlib.h>

int areaOf(int **grid, int rows, int cols, int r, int c) {
    if (grid[r][c] != 1) {
        return 0;
    }
    int area = 1;
    grid[r][c] = 2;
    if (r > 0 && grid[r - 1][c] == 1) {
        area += areaOf(grid, rows, cols, r - 1, c);
    }
    if (c < cols - 1 && grid[r][c + 1] == 1) {
        area += areaOf(grid, rows, cols, r, c + 1);
    }
    if (r < rows - 1 && grid[r + 1][c] == 1) {
        area += areaOf(grid, rows, cols, r + 1, c);
    }
    if (c > 0 && grid[r][c - 1] == 1) {
        area += areaOf(grid, rows, cols, r, c - 1);
    }
    return area;
}

int maxAreaOfIsland(int **grid, int gridRowSize, int gridColSize) {
    int maxArea = 0;
    for (int r = 0; r < gridRowSize; r++) {
        for (int c = 0; c < gridColSize; c++) {
            int area = areaOf(grid, gridRowSize, gridColSize, r, c);
            maxArea = maxArea < area ? area : maxArea;
        }
    }
    return maxArea;
}

int main() {
    int **g = malloc(sizeof(int *) * 4);
}