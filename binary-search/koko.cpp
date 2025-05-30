
#include <vector>
using std::vector;

// Input: piles = [3,6,7,11], h = 8
// Output: 4
//

bool check(vector<int>& piles, int k, int h) {
    long hours = 0;
    for (int p : piles) {
        hours += std::ceil((p + k - 1) / k);
    }
    return hours <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    // left: min eat speed, right: max eat speed
    // open interval
    int left = 1, right = *max_element(piles.begin(), piles.end()) + 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (check(piles, mid, h)) {
            right = mid;
        } else {
            // speed up
            left = mid + 1;
        }
    }

    return left;
}
