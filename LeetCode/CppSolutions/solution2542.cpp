// 2025-5-6
// 2542. 最大子序列的分数 <Medium> [贪心][堆]

#include "environment.h"

using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        ranges::sort(indices, [&](int i, int j) {
            return nums2[i] > nums2[j];
        });

        priority_queue<int, vector<int>, greater<>> pq;
        long long sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums1[indices[i]];
            pq.push(nums1[indices[i]]);
        }

        long long ans = sum * nums2[indices[k - 1]];
        for (int i = k; i < n; ++i) {
            int x = nums1[indices[i]];
            if (x > pq.top()) {  
                // 由于后面的nums2[i]较小，那么加入的nums1[i]必须大于当前的堆顶元素才有可能
                // 使乘积增大，同时维持堆中是当前最大的k个nums1元素。
                sum += x - pq.top();
                pq.pop();
                pq.push(x);
                ans = max(ans, sum * nums2[indices[i]]);
            }           
        }
        return ans;
    }
};