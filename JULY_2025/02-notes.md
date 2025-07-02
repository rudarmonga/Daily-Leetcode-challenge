# 🧮 Find the Original Typed String II

## 🔗 Problem Description
Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.

You are given a string `word`, which represents the final output displayed on Alice's screen. You are also given a positive integer `k`.

Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least `k`.

Since the answer may be very large, return it modulo 10⁹ + 7.

---

### Example 1:

- Input: word = "aabbccdd", k = 7  
- Output: 5

  Explanation:  
  The possible strings are:  
  `"aabbccdd"`, `"aabbccd"`, `"aabbcdd"`, `"aabccdd"`, and `"abbccdd"`

---

### Example 2:

- Input: word = "aabbccdd", k = 8  
- Output: 1

  Explanation:  
  The only possible string is `"aabbccdd"`

---

### Example 3:

- Input: word = "aaabbb", k = 3  
- Output: 8

---

## 🧠 Topics You Should Know

- `Dynamic Programming`
- `Prefix Sum`
- `Difference Array`
- `State Transition`
- `Character Grouping`
- `Modular Arithmetic`

---

## ✅ Approach

1. Traverse the string and group repeated characters.
   - Store the length of each group in a vector `freq`.

   Example:  
   `"aaabbbc"` → `freq = [3, 3, 1]`

2. Total ways to build any original string:
   - For each group of size `x`, we can pick any number from `1 to x` → `x` ways.
   - Multiply all group sizes:  
     `total = freq[0] * freq[1] * ... * freq[n-1]`

3. Count invalid strings (length < k):
   - Use dynamic programming with sliding window prefix sums.
   - `f[j]` = number of ways to build string of length `j`
   - Use prefix sums to efficiently count valid transitions for each group

4. Subtract invalid strings from total:
   - `result = total - invalid[k - 1]`

---

## ⏱ Time and Space Complexity

### Time Complexity: `O(k * g)`  
- `g = number of groups`  
- `k` is max possible intended string length (≤ 2000)

### Space Complexity: `O(k)`  
- Using two 1D arrays: `f` and prefix sum `g`

---

## 🧪 Dry Run

### Input: `"aaabbb", k = 3`

---

### Step 1: Group Frequencies
- Groups = [3, 3]

---

### Step 2: Total Strings
- 3 ways to choose `a`s × 3 ways to choose `b`s = `3 × 3 = 9`

---

### Step 3: Count invalid strings of length < 3

| Intended Length | Valid? | Reason |
|------------------|--------|--------|
| 1                | No     | Must pick at least 1 from both groups |
| 2                | No     | Not enough total characters |
| 3–6              | Yes    | Valid combinations exist |

→ Only 1 way to make length 2 → subtract it.

---

### Step 4: Final Answer  
`9 (total)` − `1 (invalid)` = ✅ `8`

---

### ✅ Final Output: 8
