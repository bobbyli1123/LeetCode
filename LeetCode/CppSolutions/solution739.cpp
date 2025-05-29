// 2025-5-29
// 739. 每日温度 <Medium> [单调栈]

#include "environment.h"

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> ms;
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            int curr = temperatures[i];
            while (!ms.empty() && curr > temperatures[ms.top()]) {
                res[ms.top()] = i - ms.top();
                ms.pop();
            }
            ms.push(i);
        }
        return res;
    }
};


