// 2025-4-26
// 1456. 定长子串中元音的最大数目 <Medium> [滑动窗口]

#include "environment.h"

using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int l = 0, r = k;
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) ++cnt;
        }
        int maxC = cnt;
        while (r < s.size()) {
            if (isVowel(s[r])) ++cnt;
            if (isVowel(s[l])) --cnt;
            maxC = max(maxC, cnt);
            ++l;
            ++r;
        }
        return maxC;
    }
};

int main() {
    return 0;
}