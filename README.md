# SudokuSolver
Solve Sudoku puzzles using brute-forcing via C++.
This program was developed as a personal project to practice the fundamentals of C++ coding.
It also allowed for research to be done about the historical progression of algorithms being used to solve Sudoku puzzles.
While brute-forcing is the most basic approach, it functions efficiently enough as long as data is not formatted specifically to make the algorithm guess as many times as possible.

## Basic Flow
* Hints are received from the user, either from a formatted text file or manual input from the user.
  * This step could be improved with GUI elements to shield the user from dealing with numerical indexes.
* User is informed if they have provided less than 17 hints.
  * 17 hints is the minimum number for a solvable puzzle to have without multiple solutions being present.
* Empty cells (ones not given hints) are indexed properly into each group that they belong to (row, column, box).
* Solution is now processed using a brute-forcing method
  * The next blank index has a value guessed (start at 1).
  * If the value does not conflict with existing numbers in its groups, it will move to the next index.
    * Progresses from row to row, left to right.
  * If it does conflict, the number is incremented.
    * If it is incremented beyond the MAX (9 by default Sudoku rules), it will be reset to blank and move back to the previous index.
  * Pattern progresses until either:
    * The end of the puzzle is reached and the puzzle is populated.
    * The index moves to the left of the first index; puzzle is impossible to complete.
