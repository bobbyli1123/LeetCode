// 2025-5-28
// 374. 猜数字大小 <Easy> [二分]

#include "environment.h"

using namespace std;

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int res = guess(mid);
            if (res == 0) return mid;
            else if (res < 0) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};

// dummy guess API
int guess(int num) {
    return 0;
}