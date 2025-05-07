// 2025-5-6
// 2462. 雇佣 K 位工人的总代价 <Medium> [堆]

#include "environment.h"

using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        if (2 * candidates + k > n) {
            // n - k < 2 * candidates，剩下的candidates会有重叠的情况，直接找最小的k个值
            ranges::nth_element(costs, costs.begin() + k);
            return accumulate(costs.begin(), costs.begin() + k, 0LL);
        }
        priority_queue<int, vector<int>, greater<>> pre, suf;
        for (int i = 0; i < candidates; ++i) {
            pre.push(costs[i]);
            suf.push(costs[n - 1 - i]);
        }
        long long ans = 0;
        int i = candidates, j = n - 1 - candidates;
        while (k--) {
            if (pre.top() <= suf.top()) {
                ans += pre.top();
                pre.pop();
                pre.push(costs[i++]);
            } else {
                ans += suf.top();
                suf.pop();
                suf.push(costs[j--]);
            }
        }
        return ans;
    }
};