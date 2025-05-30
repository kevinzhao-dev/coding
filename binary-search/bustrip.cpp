
#include <vector>
using std::vector;

// [1,2,3], 5 => 3

bool check(vector<int>& time, long long actualTime, int totalTrips) {
    long long trips = 0;
    for (auto it : time) {
        trips += actualTime / it;
        if (trips >= totalTrips) return true;
    }
    return trips >= totalTrips;
}

long long minimumTime(vector<int>& time, int totalTrips) {
    // open interval of time
    long long left = 1, right = (long long)*min_element(time.begin(), time.end()) * totalTrips;

    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (check(time, mid, totalTrips)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}
