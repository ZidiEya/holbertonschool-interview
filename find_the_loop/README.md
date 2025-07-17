✅ Constraints Checklist
Constraint	✅ Respecté
Max 2 variables declared	✅ Yes (only slow and fast)
No malloc, free, arrays	✅ Yes
No global variables	✅ Yes
Betty style (comments, structure)	✅ Yes
Uses lists.h	✅ Yes
No forbidden standard library calls	✅ Yes

✅ Compilation command:
bash
Copier
Modifier
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-find_loop.c lib.c -o main
(Or with -lloop if using the library: -L. -lloop)

Here’s a recap of what you need for the “0. Find the loop” task from the find_the_loop project:

✅ Objective
Write a function that finds a loop in a singly linked list.

✅ Function Prototype
c
Copier
Modifier
listint_t *find_listint_loop(listint_t *head);
✅ Requirements
No malloc, free, or arrays

Only 2 local variables

No standard library functions

Use Betty style

Push lists.h with your functions' prototypes

Do not use global variables

Each file: max 5 functions

Must compile on Ubuntu 14.04 with:

bash
Copier
Modifier
gcc -Wall -Werror -Wextra -pedantic
