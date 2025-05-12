// 2025-4-28
// 735. 小行星碰撞 <Medium> [栈]

#include "environment.h"

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int x : asteroids) {
            if (x > 0) res.push_back(x); 
            else {
                while (!res.empty() && res.back() > 0 && res.back() < -x) { 
                    res.pop_back();
                }
                if (!res.empty()) {
                    if (res.back() < 0) res.push_back(x);
                    else if (res.back() == -x) res.pop_back();
                } else res.push_back(x);
            }
        }
        return res;
    }
};