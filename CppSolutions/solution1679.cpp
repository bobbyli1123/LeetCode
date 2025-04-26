// 2025-4-26
// 1679. K 和数对的最大数目 <Medium> [哈希表]

#include "environment.h"

using namespace std;

class Solution { 
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int res = 0;
        for (int x : nums) {
            if (cnt[k - x] > 0) {
                --cnt[k - x];
                ++res;
            } else ++cnt[x];
        }
        return res;
    }
};

int main() {
    return 0;
}