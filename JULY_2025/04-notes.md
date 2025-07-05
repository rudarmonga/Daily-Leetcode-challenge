# 🧮 Find the K-th Character in String Game II

## 🔗 Problem Description
Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k. You are also given an integer array operations, where operations[i] represents the type of the ith operation.

Now Bob will ask Alice to perform all operations in sequence:

If operations[i] == 0, append a copy of word to itself.
If operations[i] == 1, generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word. For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
Return the value of the kth character in word after performing all the operations.

Note that the character 'z' can be changed to 'a' in the second type of operation.

---

### Example 1:

- Input: k = 5, operations = [0,0,0]

- Output: "a"

    Explanation:

    - Initially, word == "a". Alice performs the three operations as follows:

    - Appends "a" to "a", word becomes "aa".
    - Appends "aa" to "aa", word becomes "aaaa".
    - Appends "aaaa" to "aaaa", word becomes "aaaaaaaa".

---

### Example 2:

- Input: k = 10, operations = [0,1,0,1]

- Output: "b"

    Explanation:

    - Initially, word == "a". Alice performs the four operations as follows:

    - Appends "a" to "a", word becomes "aa".
    - Appends "bb" to "aa", word becomes "aabb".
    - Appends "aabb" to "aabb", word becomes "aabbaabb".
    - Appends "bbccbbcc" to "aabbaabb", word becomes "aabbaabbbbccbbcc".

---

## 🧠 Topics You Should Know

- `Binary Search Style Traversal`
- `Character Mapping via Modulo`
- `Prefix Doubling`
- `Mathematical Simulation`

---

## ✅ Approach

1. Start with the string `"a"` and a series of operations that double the string.

2. Each operation either:
   - Keeps characters the same (`0`)
   - Shifts each character forward by one (`1`), cycling `'z' → 'a'`.

3. Instead of generating the actual string, we simulate its length growth using a `lengths[]` array.

4. We go **backward** from the last operation and decide:
   - If `k` lies in the **second half** of the doubled string, we subtract the half length.
   - If the operation was a shift (`1`), we increment the `shift` count.

5. Finally, starting from `'a'`, apply all `shift % 26` to find the final character.

---

## ⏱ Time and Space Complexity

### Time Complexity: `O(n)`
- First loop: computing lengths array → `O(n)`
- Second loop: reverse traversal and shift simulation → `O(n)`

### Space Complexity: `O(n)`
- We store `lengths[]` for up to `n + 1` elements.

---

# Dry Run for k = 10, operations = [0, 1, 1, 0]

## Step 1: Precompute Lengths
Using the formula: `lengths[i + 1] = min(lengths[i] * 2, 1e14)`

| i | Operation | lengths[i+1] Calculation | lengths[i+1] Value |
|---|-----------|--------------------------|--------------------|
| 0 | 0         | min(1*2, 1e14)           | 2                  |
| 1 | 1         | min(2*2, 1e14)           | 4                  |
| 2 | 1         | min(4*2, 1e14)           | 8                  |
| 3 | 0         | min(8*2, 1e14)           | 16                 |

Final `lengths` array: `[1, 2, 4, 8, 16]`

## Step 2: Reverse Traverse to Track k = 10
Initial values:
- pos = 10
- shift = 0

Reverse traversal through operations:

| i | Operation | pos | half = lengths[i] | pos > half? | Action       | shift |
|---|-----------|-----|-------------------|-------------|--------------|-------|
| 3 | 0         | 10  | 8                 | ✅ Yes      | pos -= 8     | 0     |
| 2 | 1         | 2   | 4                 | ❌ No       | -            | 0     |
| 1 | 1         | 2   | 2                 | ❌ No       | -            | 0     |
| 0 | 0         | 2   | 1                 | ✅ Yes      | pos -= 1     | 0     |

Final values:
- pos = 1
- shift = 0

## Step 3: Get Final Character
Starting from 'a':
- result = 'a' + (shift % 26) = 'a' + 0 = 'a'

### ✅ Final Output: "a"