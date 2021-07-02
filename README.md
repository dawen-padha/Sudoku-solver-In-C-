# Sudoku-solver-In-C++
Sudoku is a logic puzzle, consisting of a 9×9 grid and further subdivided into ‘mini-grids’ of size 3×3. Each row, column, and 3×3 mini-grid contains the numbers 1 to 9 once, with a true Sudoku grid having a unique solution. 
In this program i have implemented the Sudoku solver using Backtracking approach.
# Backtracking
Sudoku puzzles using a backtracking algorithm, which is a type of brute force search .Backtracking is a depth-first search (in contrast to a breadth-first search), because it will completely explore one branch to a possible solution before moving to another branch. The algorithm will select the first empty square and try writing a “1”. If a “1” does not fit the algorithm will try a “2”, then a “3” and so forth up until “9”. When a number is found that works in the mini grid, the column and the row of the number the algorithm will move on to the next empty square and repeat the process of trying to enter a number. If no digit 1¬9 can exist in the current square the algorithm will backtrack to the previous one and try a new number. This process repeats until either the puzzle is solved or all possibilities have been exhausted, effectively proving that the puzzle is unsolvable. The fact that this algorithm tests its way to the answer makes it a kind of brute¬ force algorithm. 
# Complexity Analysis
1.6.	Complexity Analysis:  
•	Time complexity:  O(9^(n*n)). 
For every unassigned index, there are 9 possible options so the time complexity is O(9^(n*n)). The time complexity remains the same but there will be some early pruning so the time taken will be much less than the naive algorithm but the upper bound time complexity remains the same.
•	Space Complexity: O(n*n). 
To store the output array a matrix is needed.
# How to Run 
There are basically two cpp files 
1. Sudoku generate is used to generate a sudoku which will be stored in a text file named text which will be used in other cpp file
2. Sudoku solver is used to solve the generated sudoku 
3. Note: keep the text file in the same directory.
