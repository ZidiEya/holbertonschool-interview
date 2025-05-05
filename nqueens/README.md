                                                   GitHub repository: holbertonschool-interview
                                                            Directory: nqueens



The N Queens problem is a classic algorithmic challenge that involves placing N chess queens on an N×N chessboard such that no two queens threaten each other. This means no two queens can share the same row, column, or diagonal.

🧩 Problem Breakdown
Input: An integer N representing the size of the chessboard (N×N).

Output: All possible solutions where N queens are placed on the board without threatening each other. Each solution is a list of N strings, where each string represents a row of the board.

🧠 Approach
The problem is typically solved using backtracking, a form of recursion that builds solutions incrementally and abandons a solution as soon as it determines that the solution cannot be completed.

Steps:
Start from the first row and try placing a queen in each column.

Check for conflicts: Ensure that placing a queen does not result in two queens sharing the same column or diagonal.

Move to the next row: If placing a queen is safe, move to the next row and repeat the process.

Backtrack if necessary: If placing a queen leads to a conflict later, remove the queen and try the next column in the current row.

Repeat until all rows are filled: Once all rows have queens placed safely, record the solution.

