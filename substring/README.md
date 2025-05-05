The substring directory in the Holberton School Interview repository contains a project titled "Substring with concatenated words". This task involves identifying all starting indices in a string s where a substring is a concatenation of each word from a list of words exactly once, without any intervening characters.
GitHub

Problem Overview
Given:

A string s

A list of words of the same length

The goal is to find all starting indices in s where a substring is a concatenation of each word in the list exactly once, with no intervening characters.

Example
For s = "barfoothefoobarman" and words = ["foo", "bar"], the function should return [0, 9], since:

At index 0: "barfoo" is a concatenation of "bar" and "foo"

At index 9: "foobar" is a concatenation of "foo" and "bar"
Glassdoor
+1
hackerrank.com
+1

Constraints
The length of s will be at least 1.

The length of each word in words will be greater than 0.

The number of words in words will be at least 1.

Approach
To solve this problem efficiently, consider the following approach:

Word Length Calculation: Determine the length of each word in words (assuming all words have the same length).

Sliding Window: Use a sliding window of size equal to the total length of all words combined.
GitHub
+3
Glassdoor
+3
hackerrank.com
+3

Word Counting: Maintain a count of each word in words using a hash map.

Window Validation: For each position in s, check if the substring starting at that position contains a valid concatenation of all words.

Result Collection: If a valid concatenation is found, record the starting index.

Time Complexity
The time complexity of this approach is O(n * m), where:

n is the length of the string s

m is the length of each word in words

