#include "engine.h"
#include "raylib.h"
#include <stdlib.h>
#include <unistd.h>

int** Make2DArray(int cols, int rows){
    int** grid = (int**)malloc(rows * sizeof(int*));

    for(int i = 0; i < rows; i++){
        grid[i] = (int*)malloc(cols * sizeof(int));
    }

    for(int y = 0; y < rows; y++){
        for(int x = 0; x < cols; x++){
            grid[y][x] = DEAD;
        }
    }

    return grid;
}

void Free2DArray(int** grid, int rows){
    for (int i = 0; i < rows; i++){
        free(grid[i]);
    }
    free(grid);
}

void Draw2DGrid(int rows, int cols, int** grid, int cellSize){
    Color AliveColor = {15, 56, 15, 255};
    for(int y = 0; y < rows; y++){
        for(int x = 0; x < cols; x++){
            int state = grid[y][x];
            if(state == 1){
                DrawRectangle(x * cellSize, y * cellSize, cellSize, cellSize, AliveColor);
            }
        }
    }
}

int CountVizinhos(int cols, int rows, int x, int y, int** grid){
    int soma = 0;
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            int row = (y + i + rows) % rows;
            int col = (x + j + cols) % cols;

            soma += grid[row][col];
        }
    }
    soma -= grid[y][x];
    return soma;
}

void initGameEngine(){
    //--Setup--
    InitWindow(WIDTH, HEIGHT, "Conway's Game of Life C&Raylib");
    SetTargetFPS(15);
    Color Background = {155, 188, 15, 255};


    int cellSize = 10;
    int cols = WIDTH / cellSize;
    int rows =  HEIGHT / cellSize;

    //Criando o Array2D
    int** mainGrid = Make2DArray(cols, rows);
    int** newArray = Make2DArray(cols, rows);
    //Populando esse Array
    for(int y = 0; y < rows; y++){
        for(int x = 0; x < cols; x++){
            mainGrid[y][x] = GetRandomValue(DEAD, ALIVE);
        }
    }


    //--Loop--
    while(!WindowShouldClose()){
        //--Update--

        for(int y = 0; y < rows; y++){
            for(int x = 0; x < cols; x++){
                int state = mainGrid[y][x];
                int vizinhos = CountVizinhos(cols, rows, x, y, mainGrid);

                if(state == DEAD && vizinhos == 3){
                    newArray[y][x] = ALIVE;
                } else if(state == ALIVE && vizinhos < 2 || vizinhos > 3){
                    newArray[y][x] = DEAD;
                } else {
                    newArray[y][x] = state;
                }
            }
        }
        int** temp = mainGrid;
        mainGrid = newArray;
        newArray = temp;

        //--Draw--
        BeginDrawing();
        ClearBackground(Background);
        Draw2DGrid(rows, cols, mainGrid, cellSize);

        EndDrawing();
    }

    //--Encerramento--
    Free2DArray(mainGrid, rows);
    Free2DArray(newArray, rows);
    CloseWindow();
}
