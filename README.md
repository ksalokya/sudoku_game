# Sudoku Puzzle Solver

## Backtracking Algorithm
### Backtracking is a technique to solve problems where multiple choices are there and we don’t know the correct choice and hence we solve the problem with trial and error i.e. trying each option until goal is achieved.

## How the algorithm works?
### The main algorithm in this particular sudoku solver is the recursive solveSudoku method. The solving begins when the solve method is called on a 9x9 array of ints representing the sudoku puzzle that is to be solved. Every time solveSudoku is called, the algorithm inputs a valid number into the next cell of the Sudoku grid and calls the solveSudoku method on that resulting Sudoku grid. The algorithm "backtracks" when it reaches a point at which there are no valid numbers for a particular cell. At that point, the algorithm swaps its previous cell entry for a different valid value and continues filling in the grid as described. At last, the algorithm will have found every possible solution to a given puzzle, since the program ultimately inputs and thereby tests ALL valid values for a particular cell.


## Demo
 - Step 1 - Run the program
 <div align="center">
  <img src="https://github.com/ksalokya/sudoku_game/blob/main/assets/1.png">
 </div>
 
 - Step 2 - Enter the Sudoku Board to be solved
 <div align="center">
  <img src="https://github.com/ksalokya/sudoku_game/blob/main/assets/2.png">
 </div>
 
 - Step 3 - Voila!
 <div align="center">
  <img src="https://github.com/ksalokya/sudoku_game/blob/main/assets/3.png">
 </div>


