#ifndef ENGINE
#define ENGINE

#define WIDTH   800
#define HEIGHT  600
#define ALIVE   1
#define DEAD    0


void initGameEngine();
int** Make2DArray(int cols, int rows);
void Free2DArray(int** grid, int rows);
void Draw2DGrid(int rows, int cols, int** grid, int cellSize);

#endif
