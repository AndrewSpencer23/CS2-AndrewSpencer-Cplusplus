#include "gameOfLife.h"

/*
Function to clear terminal depending on OS
*/
void clearScreen()
{
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

/*
Function to initialize all cells in the board.
Takes in 2D array of pointers and size of array
Should create structs and populate the array
*/
void initCells(Cell* board[][10], int boardSize)
{
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            Cell* newCell = new Cell();
            board[i][j] = newCell;
        }
    }
}

/*
Function to read the board from a file
Prompt for the file to read inside of the function
Structure of file should consist of 10 lines of 0 or 1 to indicate cell state
*/
void readBoard(Cell* board[][10], int boardSize) 
{
    string fileName;
    cout << "Please enter a file name: ";
    cin >> fileName;

    ifstream fin;
    fin.open(fileName);
    string row;
    int rowCounter = 0;

    while (getline(fin, row)) {
        char currentCell;
        for(int i = 0; i < boardSize; i++) {
            currentCell = row.at(i) - '0';
            board[i][rowCounter]->state = currentCell;
        }
        rowCounter++;
    }
}

/*
Function to print out all cells to cout
*/
void printCells(Cell* board[][10], int boardSize)
{
    int rowCounter = 0;
    while(rowCounter < boardSize) {
        for (int i = 0; i < boardSize; i++) {
            cout << board[i][rowCounter]->state;
        }
        cout << endl;
        rowCounter++;
    }
}

/*
Function to count the number of live neighbors for each cell.
Must use the x, y position stored with each cell to determine which neighbors they have
*/
void findNumNeighbors(Cell* board[][10], int boardSize, Cell* curCell) 
{ 
    curCell->numLiveNeighbors = 0;
    for(int i = curCell->x - 1; i < curCell->x + 2; i++) {
        for(int j = curCell->y - 1; j < curCell->y + 2; j++) {
            curCell->numLiveNeighbors = 0;
            if(i > 9) {
               continue;
            }
            if (j > 9) {
                continue;
            }
            if(i < 0) {
                continue;
            }
            if(j < 0) {
                continue;
            }
            if(board[i][j]->state == 0) {
                continue;
            }
            if(board[i][j]->state == 1) {
                curCell->numLiveNeighbors++;
            }
        }
    }
}

//     for(int j = 0; j < boardSize; j++) {
//         for(int i = 0; i < boardSize; i++) {
//             if(i > 9) {
//                continue;
//             }
//             if (j > 9) {
//                 continue;
//             }
//             if(i < 0) {
//                 continue;
//             }
//             if(j < 0) {
//                 continue;
//             }
//             if(curCell->x == curCell->x + 1) {
//                 curCell->numLiveNeighbors++;
//             }
//             if(curCell->y == curCell->y + 1) {
//                 curCell->numLiveNeighbors++;
//             }
//         }
//     }
// }

/*
Function to update each cell's state based on number of neighbors
Must use following rules:

Any live cell with fewer than two live neighbors dies, as if by underpopulation.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by overpopulation.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Return if you updated cells or not to break out of while loop from main.
*/
bool updateCellState(Cell* board[][10], int boardSize) 
{
    bool updated = true;
    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++) {
            findNumNeighbors(board, boardSize, board[i][j]);
        }
    }

    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++) {
            if(board[i][j]->state == 1) {
                if(board[i][j]->numLiveNeighbors < 2) {
                    board[i][j]->state = 0;
                    updated = true;
                    continue;
                }
                else if(board[i][j]->numLiveNeighbors == 2) {
                    board[i][j]->state = 1;
                    updated = true;
                    continue;
                }
                else if(board[i][j]->numLiveNeighbors == 3) {
                    board[i][j]->state = 1;
                    updated = true;
                    continue;
                }
                else if(board[i][j]->numLiveNeighbors > 3) {
                    board[i][j]->state = 0;
                    updated = true;
                    continue;
                }
            }
            if(board[i][j] == 0) {
                if(board[i][j]->state == 0 && board[i][j]->numLiveNeighbors == 3) {
                    board[i][j]->state = 1;
                    updated = true;
                    continue;
                }
            }
            else{
                updated = false;
                continue;
            }
        }
    }
    return updated;
}