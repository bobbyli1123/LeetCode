// 2025-4-26
// 1768. 交替合并字符串 <Easy> [双指针]

#include "environment.h"

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        string res;
        int i = 0, j = 0;
        while (i < m || j < n) {
            if (i < m) res += word1[i++];
            if (j < n) res += word2[j++];
        }
        return res;
    }
};

int main() {
    return 0;
}