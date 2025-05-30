
#include <vector>
using std::vector;

// Input: nums = [1,2,5,9], threshold = 6
// Output: 5

bool check(vector<int>& nums, int v, int t) {
    long sum = 0;
    for (auto n : nums) {
        sum += (n + v - 1) / v;
    }
    return sum <= t;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    // search on val space
    // open interval condition
    int left = 1, right = *max_element(nums.begin(), nums.end()) + 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(nums, mid, threshold)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
