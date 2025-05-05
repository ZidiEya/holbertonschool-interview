                                                                  GitHub repository: holbertonschool-interview
                                                                     Directory: linked_list_palindrome




                                                                     holbertonschool-interview/
└── linked_list_palindrome/
    ├── 0-is_palindrome.c      # Main palindrome-checking logic
    ├── lists.h                # Header file with struct and function prototypes
    ├── linked




🔍 How It Works
It uses the fast and slow pointer method to find the middle.

Then reverses the second half of the list.

Compares the first half with the reversed second half node by node.

If all values match, it's a palindrome.

This solution is efficient (O(n) time, O(1) space) and meets all C constraints (no global vars, etc.).
