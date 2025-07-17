🧩 Project Recap: slide_line (2048 Game Logic)
🎯 Goal:
Implement a function that simulates one row movement in the 2048 game.

🔧 Function:
c
Copier
Modifier
int slide_line(int *line, size_t size, int direction);
📌 Parameters:
line: An array of integers representing the row of the 2048 game board.

size: The number of elements in the array.

direction: Direction to slide:

SLIDE_LEFT (0)

SLIDE_RIGHT (1)

🔄 Behavior:
➡️ Slide:
Moves all non-zero numbers to the specified direction.

Zeros are skipped, effectively compressing values to one side.

➕ Merge:
If two adjacent equal numbers are next to each other after sliding, they’re merged into one by summing them.

Merging happens only once per pair per move.

🧼 Fill:
After merge, remaining empty spots are filled with 0.

🧪 Example:
Input:

c
Copier
Modifier
[2, 2, 0, 4], direction = SLIDE_LEFT
Steps:

Slide: [2, 2, 4]

Merge: [4, 4]

Fill: [4, 4, 0, 0]

Output:

c
Copier
Modifier
[4, 4, 0, 0]
📁 Files:
slide_line.c: Main function logic.

slide_line.h: Header file with constants and function prototype.

0-main.c: Testing file (optional).

✅ Return:
1 on success.

0 if line is NULL or direction is invalid.

📚 Key Concepts Used:
Arrays

In-place operations

Edge case handling

Directional logic

