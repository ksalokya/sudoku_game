#include <bits/stdc++.h>

using namespace std;

/**
  *	@desc Checks if the value in the specified cell is valid or not.
  *	@param i (int) row of the required value
  *	@param j (int) col of the required value
  *	@param n (int) size of the board
  *	@param number (int) the required value
  *	@return (bool) whether the value is valid or not in the sudoku grid
*/
bool canPlace(int mat[][9], int i, int j, int number) {

    //row and column check
    for (int x = 0; x < 9; ++x) {
        if (mat[x][j] == number || mat[i][x] == number) {
            return false;
        }
    }

    //checking in sub-matrix
    int rn = 3;
    int sx = (i / rn) * rn;
    int sy = (j / rn) * rn;

    for (int x = sx; x < sx + rn; ++x) {
        for (int y = sy; y < sy + rn; ++y) {
            if (mat[x][y] == number)
                return false;
        }
    }
    return true;
}

/**
  *	@desc Displays the values stored in the grid with designs. We also use
  *	ANSI colors, using escape sequences, to display the grid.
  *	@param mat (int [][]) 2d-matrix with input values to be printed
  *	@return none
*/
void displayGrid(int mat[][9]) {

    cout << "\n\n++=====================================++";
    int rowIter, colIter;

    for (rowIter = 0; rowIter < 9; rowIter++) {
        int cellIter = 1;

        cout << "\n||";
        for (colIter = 0; colIter < 9; colIter++) {
            if (cellIter == 3) {
                cout << " ";
                if (mat[rowIter][colIter] != 0)
                    cout << mat[rowIter][colIter] << " ";
                else
                    cout << "  ";
                cout << "||";
                cellIter = 1;
            } else {
                cout << " ";
                if (mat[rowIter][colIter] != 0)
                    cout << mat[rowIter][colIter] << "  ";
                else
                    cout << "   ";
                cellIter++;
            }
        }

        if (rowIter % 3 != 2) cout << "\n++-----------++-----------++-----------++";
        else cout << "\n++=====================================++";
    }

    cout << " ";
}

/**
  *	@desc The recursive function which does all the work, this iterates over the
  *	possible values for the specified cell one-by-one. Once a value has been filled, it
  *	goes to the next cell. Here, the same thing happens. If none of the possible values
  *	work out, then the function backtracks to the previous cell.
    *
  *	@param mat (int [][]) 2d-matrix with input values to be solved
  *	@param i (int) row of the current cell
  *	@param j (int) col of the current cell
  *	@param n (int) size of the board
  *	@return (bool) whether the value put in the cell made it a SUCCESS or NOT
*/
bool solveSudoku(int mat[][9], int i, int j) {

    //base case
    if (i == 9) {
        //prints the sudoku board
        displayGrid(mat);
        return true;
    }

    //one column ends - shift to next row
    if (j == 9)
        return solveSudoku(mat, i + 1, 0);

    //skipping pre-filled cells
    if (mat[i][j] != 0)
        return solveSudoku(mat, i, j + 1);

    //recursive case
    //fills the current cell with possible option
    for (int number = 1; number <= 9; ++number) {
        if (canPlace(mat, i, j, number)) {
            //assume
            mat[i][j] = number;

            bool couldWeSolve = solveSudoku(mat, i, j + 1);

            if (couldWeSolve)
                return true;
        }
    }
    //backtrack
    mat[i][j] = 0;
    return false;

}

int main() {

    cout << "\n======================\n";
    cout << "    Sudoku Solver\n";
    cout << "======================\n\n";

    cout << "Welcome to Sudoku Solver!\n";
    cout << "Before we start, you will have to input the puzzle to be solved.\n\n";
    cout << "Note - Blank cells must be filled in as 0 (eg; 1 0 0  2 0 0 ...).\n\n";

    int arr[9][9];

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> arr[i][j];
        }
    }

    solveSudoku(arr, 0, 0);

    return 0;
}
