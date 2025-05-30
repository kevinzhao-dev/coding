
#include <vector>
using std::vector;

int search(vector<int> &nums, int target) {
    int left = 0, right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        auto n = nums[mid];
        if (n == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }

    return -1;
}

// Find first index > target
// [1, 4, 5, 9] target = 5 -> 3
// [1, 4, 5, 9] target = 6 -> 3
// [1, 4, 5, 9] target = 10 -> 4
int upper_bound(vector<int> &nums, int target) {
    // [left, right)
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

// Find first index >= target
int lower_bound(vector<int> &nums, int target) {
    // [left, right)
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
