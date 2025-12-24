#include <bits/stdc++.h>
using namespace std;

void printPermutation(string str, int idx, string perm)
{
    if (str.length() == 0) // Base case: If the input string is empty, print the permutation
    {
        cout << perm << endl;
        return;
    }

    for (int i = 0; i < str.size(); i++) // Iterate through each character in the string
    {
        char currChar = str[i]; // Pick the current character
        string newStr = str.substr(0, i) + str.substr(i + 1); // Remove the current character from the string

        // Recursive call with the reduced string and updated permutation
        printPermutation(newStr, idx + 1, perm + currChar);
    }
}

int main()
{
    string str = "abc";
    printPermutation(str, 0, ""); // Start the recursion with the full string and an empty permutation
}

/*
Sure! Let's break down **5 permutations** of the string `"abcd"` in great detail to explain the **recursion** and **backtracking** steps. We'll go step by step for each combination generated, showing how the function navigates through the recursive tree and produces each permutation.

### Base Setup:
We have the string `"abcd"`, and the method `printPermutation(str, idx, perm)` generates permutations by recursively selecting characters from the string and adding them to the permutation `perm`.

### Key Recursive Ideas:
1. The **base case** is when the string is empty. This means we've used all characters in the permutation, and we print it.
2. The **recursive case** involves selecting a character at index `i`, adding it to the current permutation, removing it from the string, and recursively calling the method on the remaining string.

---

### Example: Full Detailed Execution for the First 5 Permutations

Let’s go through the first 5 permutations for `"abcd"`.

#### **1st Permutation: `"abcd"`**

1. **First call**: `printPermutation("abcd", 0, "")`
  - The string is `"abcd"`, and the current permutation is `""`.

  - Loop starts:

    - `i = 0`, `currChar = 'a'`
    - `newStr = "bcd"` (Remove 'a')
    - Recurse: `printPermutation("bcd", 1, "a")`

2. **Second call**: `printPermutation("bcd", 1, "a")`
  - The string is `"bcd"`, and the current permutation is `"a"`.

  - Loop starts:
    - `i = 0`, `currChar = 'b'`
    - `newStr = "cd"` (Remove 'b')
    - Recurse: `printPermutation("cd", 2, "ab")`

3. **Third call**: `printPermutation("cd", 2, "ab")`
  - The string is `"cd"`, and the current permutation is `"ab"`.

  - Loop starts:
    - `i = 0`, `currChar = 'c'`
    - `newStr = "d"` (Remove 'c')
    - Recurse: `printPermutation("d", 3, "abc")`

4. **Fourth call**: `printPermutation("d", 3, "abc")`
  - The string is `"d"`, and the current permutation is `"abc"`.

  - Loop starts:
    - `i = 0`, `currChar = 'd'`
    - `newStr = ""` (Remove 'd')
    - Recurse: `printPermutation("", 4, "abcd")`

5. **Fifth call**: `printPermutation("", 4, "abcd")`
  - The string is empty, and the current permutation is `"abcd"`.
  - **Print** the permutation: `abcd`
  - The recursion begins to unwind.

---

#### **2nd Permutation: `"abdc"`**

We now backtrack and explore other possibilities after `"abcd"` has been printed.

- Backtrack to the fourth call where `printPermutation("d", 3, "abc")` was called.
 - Now, try the next character (`i = 1`), `currChar = 'd'`.
 - `newStr = "c"`, and we call: `printPermutation("c", 3, "abd")`.

6. **Sixth call**: `printPermutation("c", 3, "abd")`
  - The string is `"c"`, and the current permutation is `"abd"`.
  - Loop starts:
    - `i = 0`, `currChar = 'c'`
    - `newStr = ""` (Remove 'c')
    - Recurse: `printPermutation("", 4, "abdc")`

7. **Seventh call**: `printPermutation("", 4, "abdc")`
  - The string is empty, and the current permutation is `"abdc"`.
  - **Print** the permutation: `abdc`
  - The recursion unwinds further.

---

#### **3rd Permutation: `"acbd"`**

Now, backtrack to the third call `printPermutation("cd", 2, "ab")`.

- Backtrack to `i = 1`, `currChar = 'c'`, and explore the next possibility:
 - `newStr = "bd"`, and we call: `printPermutation("bd", 2, "ac")`.

8. **Eighth call**: `printPermutation("bd", 2, "ac")`
  - The string is `"bd"`, and the current permutation is `"ac"`.
  - Loop starts:
    - `i = 0`, `currChar = 'b'`
    - `newStr = "d"` (Remove 'b')
    - Recurse: `printPermutation("d", 3, "acb")`

9. **Ninth call**: `printPermutation("d", 3, "acb")`
  - The string is `"d"`, and the current permutation is `"acb"`.
  - Loop starts:
    - `i = 0`, `currChar = 'd'`
    - `newStr = ""` (Remove 'd')
    - Recurse: `printPermutation("", 4, "acbd")`

10. **Tenth call**: `printPermutation("", 4, "acbd")`
   - The string is empty, and the current permutation is `"acbd"`.
   - **Print** the permutation: `acbd`
   - The recursion continues to unwind.

---

#### **4th Permutation: `"acdb"`**

Now, backtrack to the ninth call `printPermutation("d", 3, "acb")`.

- Backtrack to `i = 1`, `currChar = 'd'`, and we try the next possibility:
 - `newStr = "b"`, and we call: `printPermutation("b", 3, "acd")`.

11. **Eleventh call**: `printPermutation("b", 3, "acd")`
   - The string is `"b"`, and the current permutation is `"acd"`.
   - Loop starts:
     - `i = 0`, `currChar = 'b'`
     - `newStr = ""` (Remove 'b')
     - Recurse: `printPermutation("", 4, "acdb")`

12. **Twelfth call**: `printPermutation("", 4, "acdb")`
   - The string is empty, and the current permutation is `"acdb"`.
   - **Print** the permutation: `acdb`
   - The recursion continues unwinding.

---

#### **5th Permutation: `"adbc"`**

Finally, we backtrack further to earlier levels. After `"acdb"`, we go back to the second call (`printPermutation("bcd", 1, "a")`), where we previously selected `b` and `c`. Now, we try `i = 2`, `currChar = 'd'`.

- Backtrack to `printPermutation("bcd", 1, "a")`, we now try:
 - `newStr = "bcd"` with `currChar = 'd'`, and we call: `printPermutation("b", 3, "ad")`.

13. **Thirteenth call**: `printPermutation("b", 3, "ad")`
   - The string is `"b"`, and the current permutation is `"ad"`.
   - Loop starts:
     - `i = 0`, `currChar = 'b'`
     - `newStr = ""` (Remove 'b')
     - Recurse: `printPermutation("", 4, "adbc")`

14. **Fourteenth call**: `printPermutation("", 4, "adbc")`
   - The string is empty, and the current permutation is `"adbc"`.
   - **Print** the permutation: `adbc`

---

### Full Trace Summary of First 5 Permutations:
- **1st**: `abcd`
- **2nd**: `abdc`
- **3rd**: `acbd`
- **4th**: `acdb`
- **5th**: `adbc`

---

### Key Recursion Details:
- **Backtracking**: After generating each permutation, we backtrack by returning to the previous recursion level and trying the next possible character.
- **Recursive Tree Structure**: Every recursive call represents a new branch, and at each level, we loop over the string, picking one character at a time and generating a smaller string for further recursion.

*/