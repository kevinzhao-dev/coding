
#include <vector>
using std::vector;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    const int n = matrix.size(), m = matrix[0].size();
    int left = 0, right = n * m - 1;

    while (left <= right) {
        const int mid = left + (right - left) / 2;
        const int i = mid % m;
        const int j = mid / m;

        if (matrix[i][j] == target) return true;

        if (matrix[i][j] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

