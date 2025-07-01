# 🧮 Find the Original Typed String I

## 🔗 Problem Description
Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.

Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.

You are given a string word, which represents the final output displayed on Alice's screen.

Return the total number of possible original strings that Alice might have intended to type.

Example 1:

- Input: word = "abbcccc"

- Output: 5

  Explanation:

  The possible strings are: "abbcccc", "abbccc", "abbcc", "abbc", and "abcccc".

Example 2:

- Input: word = "abcd"

- Output: 1

  Explanation:

  The only possible string is "abcd".

---

## 🧠 Topics You Should Know

- `String`
- `Character Comparison`
- `For Loop`
- `Variables and State Tracking`
- `Indexing`
- `Edge Case Handling`
- `Pair` *(optional)*
- `Vector` *(optional)*

---

## ✅ Approach

1. Start with first character as `prev`, initialize:
   - `count = 1` (for the first character)
   - `streak = 0`

2. Traverse the string from index 1:
   - If `word[i] == prev` → increase `streak`
   - Else:
     - Add `streak` to `count`
     - Reset `streak` to 0
     - Update `prev` to current character

3. After loop ends, add the final `streak` to `count`.

---

## ⏱ Time and Space Complexity

### Time Complexity: `O(n)`
- We traverse the string once → linear time.

### Space Complexity: `O(1)`
- No extra data structures used, only a few variables.

---

## 🧪 Dry Run

### Input: abbcccc


### Initial State:
- `prev = 'a'`
- `streak = 0`
- `count = 1`

---

| i | word[i] | prev | Equal? | streak | count | Action |
|---|---------|------|--------|--------|--------|--------|
| 1 | 'b'     | 'a'  | No     | 0      | 1      | count += 0 → count = 1, prev = 'b', streak = 0 |
| 2 | 'b'     | 'b'  | Yes    | 1      | 1      | streak++ |
| 3 | 'c'     | 'b'  | No     | 1      | 2      | count += 1 → count = 2, prev = 'c', streak = 0 |
| 4 | 'c'     | 'c'  | Yes    | 1      | 2      | streak++ |
| 5 | 'c'     | 'c'  | Yes    | 2      | 2      | streak++ |
| 6 | 'c'     | 'c'  | Yes    | 3      | 2      | streak++ |

---

### After Loop:
- Add final `streak` to `count`:  
  `count = 2 + 3 = 5`

---

### ✅ Final Output: 5