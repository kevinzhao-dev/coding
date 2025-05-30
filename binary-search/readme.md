# 🔍 Binary Search Patterns in C++

This document summarizes standard binary search techniques in C++, including `lower_bound`, `upper_bound`, and exact-match binary search. The templates use **left-closed, right-open intervals** `[left, right)` to avoid common pitfalls.

---

## ✅ Problem Types & Intentions

| Type           | Goal                                 | STL Equivalent         |
|----------------|--------------------------------------|------------------------|
| Exact Match    | Find any index where `nums[i] == target` | —                      |
| Lower Bound    | Find the first index `i` such that `nums[i] >= target` | `std::lower_bound` |
| Upper Bound    | Find the first index `i` such that `nums[i] > target`  | `std::upper_bound`  |

---

## 🧱 Unified Binary Search Templates

All use **`[left, right)`** range with `right = nums.size()`.

### 1️⃣ Lower Bound

```cpp
int lower_bound(const vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int upper_bound(const vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int binary_search(const vector<int>& nums, int target) {
    int left = 0, right = nums.size(); // [left, right)
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return -1;
}

nums = {1, 4, 5, 9}

| target | `lower_bound` index | `upper_bound` index | Meaning                 |
| ------ | ------------------- | ------------------- | ----------------------- |
| 0      | 0                   | 0                   | All elements > 0        |
| 4      | 1                   | 2                   | First ≥ 4 is 4, >4 is 5 |
| 5      | 2                   | 3                   | First ≥ 5 is 5, >5 is 9 |
| 6      | 3                   | 3                   | First ≥ 6 and >6 is 9   |
| 10     | 4                   | 4                   | No element ≥ or > 10    |

🧠 Key Transition Conditions

| Condition             | Action           | Why                                  |
| --------------------- | ---------------- | ------------------------------------ |
| `nums[mid] < target`  | `left = mid + 1` | Discard mid, it's too small          |
| `nums[mid] <= target` | `left = mid + 1` | For upper\_bound: too small or equal |
| `nums[mid] >= target` | `right = mid`    | For lower\_bound: mid is a candidate |
| `nums[mid] > target`  | `right = mid`    | For upper\_bound: mid is a candidate |

⚠️ Why [left, right) (right = nums.size())?
* Includes full valid range, including nums.size() as a possible result

* Avoids off-by-one errors

* Naturally terminates when left == right, ensuring the loop exits cleanly

* Matches STL conventions (std::lower_bound, std::upper_bound)

| Comparison Aspect           | Closed Interval `[l, r]`                      | Open Interval `[l, r)`                                          |
| --------------------------- | --------------------------------------------- | --------------------------------------------------------------- |
| ✅ **Ease of Understanding** | ✅ More intuitive, commonly used in tutorials  | ⛔ More abstract, harder for beginners to grasp                  |
| ✅ **Ease of Correctness**   | ✅ Direct `return` on equality, fewer mistakes | ⛔ Requires additional post-check after loop                     |
| ✅ **Boundary Handling**     | ⛔ Prone to overflow with `mid = l + r`        | ✅ Safer and consistent with STL convention                      |
| 📦 **STL Similarity**       | ⛔ Does not match STL `lower_bound` semantics  | ✅ Aligns with STL `lower_bound` style                           |
| 💡 **Use Cases**            | Best for finding **exact match**              | Ideal for finding the **first position** satisfying a condition |
| 📏 **Interval Adjustment**  | `l = mid + 1`, `r = mid - 1`                  | `l = mid + 1`, `r = mid`                                        |

📚Summary
* Use binary search wisely by understanding:

* Your target condition (==, >=, >)

* Whether the current mid should be kept or discarded


