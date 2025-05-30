
#include <vector>
using std::vector;

// Input: nums = [1,3,5,6], target = 7
// Output: 4

int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        const int mid = left + (right - left) / 2;
        const int val = nums[mid];

        if (val == target) return mid;

        if (val < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}
