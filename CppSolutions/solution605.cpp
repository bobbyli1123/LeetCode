// 2025-4-27
// 605. 种花问题 <Easy> [贪心]

#include "environment.h"

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int last = -2, res = 0;
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 1) {
                res += (i - last - 2) / 2;
                last = i;
            }
        }
        return res + (flowerbed.size() - last - 1) / 2 >= n;
    }
};

int main() {
    return 0;
}