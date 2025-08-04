sandpiles

markdown
Copier
Modifier
# Sandpiles

This project is a solution to the **sandpiles** task as part of Holberton School's technical interview preparation.

## Description

The goal is to implement a function that computes the **sum of two sandpiles** and stabilizes the result by applying toppling rules.

A sandpile is a 3x3 grid of integers where each cell can contain 0 or more grains of sand. If any cell exceeds 3 grains, it topples by distributing grains to its neighbors. This process continues until the grid becomes stable.

### Key Concepts:

- **Toppling:** If a cell > 3, it loses 4 grains and each of its 4 neighbors gains 1.
- **Stability:** A grid is stable when all its cells contain ≤ 3 grains.
- **No dynamic memory allocation** is allowed.

## File Structure

.
├── 0-sandpiles.c # Core logic for computing and stabilizing sandpiles
├── sandpiles.h # Header file with function prototypes
├── 0-main.c # Sample test file (for testing only)
├── README.md # Project description and usage

csharp
Copier
Modifier

## Prototype

```c
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
grid1 is updated in-place with the result.

Example Output
Input:

makefile
Copier
Modifier
grid1 =         grid2 =

3 3 3           1 3 1
3 3 3     +     3 3 3
3 3 3           1 3 1
Output:

python-repl
Copier
Modifier
=
4 6 4
6 6 6
4 6 4
=
2 5 2
5 6 5
2 5 2
...
=
2 2 2
2 2 2
2 2 2
Compilation
Compile with:

bash
Copier
Modifier
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-sandpiles.c -o sandpiles
Requirements
OS: Ubuntu 14.04 LTS

Compiler: gcc 4.8.4

Style: Betty compliant

No global variables

No dynamic memory allocation

Author
Eya Zidi — Holberton School Interview Prep

yaml
Copier
Modifier

---

You can customize the **Author** and the links. Let me know if you want me to generate a fu
