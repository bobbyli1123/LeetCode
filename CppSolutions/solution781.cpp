// 2025-4-20
// 781. 森林中的兔子 <Medium> [哈希表][数组]

#include "environment.h"

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> cnt;
        for (int x : answers) ++cnt[x + 1];
        int ans = 0;
        for (auto &[type, num] : cnt) {
            int group = num / type + (num % type != 0);
            ans += group * type;
        }
        return ans;
    }
};

void main() {

}