// 2025-4-27
// 11. 盛最多水的容器 <Medium> [双指针]

#include "environment.h"

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int ans = 0;
        while (left < right) {
            ans = max(ans, min(height[left], height[right]) * (right-left));
            if (height[left] < height[right]) ++left;
            else --right;
        }
        return ans;
    }
};

int main() {

}