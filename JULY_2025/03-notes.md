# 🧮 Find the Original Typed String II

## 🔗 Problem Description
Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k.

Now Bob will ask Alice to perform the following operation forever:

Generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word.
For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".

Return the value of the kth character in word, after enough operations have been done for word to have at least k characters.

Note that the character 'z' can be changed to 'a' in the operation.

---

### Example 1:

- Input: k = 5
- Output: "b"

  Explanation:

  Initially, word = "a". We need to do the operation three times:

  - Generated string is "b", word becomes "ab".
  - Generated string is "bc", word becomes "abbc".
  - Generated string is "bccd", word becomes "abbcbccd".

---

### Example 2:

- Input: k = 10
- Output: "c"

---

## 🧠 Topics You Should Know

- `Simulation`
- `String Construction`
- `Character Mapping`
- `Iterative Build`

---

## ✅ Approach

1. Start with the string `str = "a"`.

2. While the length of `str` is less than `k`:
   - For each character in `str`, compute its next character:
     - `'a' → 'b'`, `'b' → 'c'`, ..., `'z' → 'a'`
   - Append all next characters to `str`.

3. Return the character at position `k - 1` (0-indexed).

---

## ⏱ Time and Space Complexity

### Time Complexity: `O(k)`
- In each operation, we process the current string and generate its "next" version.
- The string approximately doubles each time.
- In the worst case, we keep going until string length ≥ `k`.

### Space Complexity: `O(k)`
- We store the full generated string up to length `k`.


## 🧪 Dry Run

### Input: `k = 10`

---

### Step 1: Initial Word
- `str = "a"`

---

### Step 2: Iterative Construction

| Iteration | New Characters Appended | Resulting String         | Length |
|-----------|--------------------------|---------------------------|--------|
| 1         | `"b"`                    | `"ab"`                    | 2      |
| 2         | `"bc"`                   | `"abbc"`                  | 4      |
| 3         | `"bccd"`                 | `"abbcbccd"`              | 8      |
| 4         | `"cccddee"`              | `"abbcbccdcccddee"`       | 15     |

---

### Step 3: Find the 10th Character

- Final string after 4 iterations: `"abbcbccdcccddee"`
- Character at index `9` (0-based) is `"c"`

---

### ✅ Final Output: `"c"`
