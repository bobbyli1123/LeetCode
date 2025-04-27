// 2025-4-27
// 1657. 确定两个字符串是否接近 <Medium> [哈希表]

#include "environment.h"

using namespace std;

class SolutionNotGood {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> count1, count2;
        for (char c : word1) {
            count1[c]++;
        }
        for (char c : word2) {
            if (!count1.count(c)) {
                return false;  // word2 中有 word1 中没有的字符
            }
            count2[c]++;
        }
        unordered_map<int, int> freq1, freq2;
        for (const auto& [c, f] : count1) {
            freq1[f]++;
        }
        for (const auto& [c, f] : count2) {
            freq2[f]++;
        }
        for (const auto& [f, c] : freq1) {
            if (freq2[f] != c) {
                return false;  // 频率不匹配
            }
        }
        return true;  // 所有字符的频率匹配且字符集相同
    }
};

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> count1(26), count2(26);
        for (char c : word1) {
            count1[c - 'a']++;
        }
        for (char c : word2) {
            count2[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            if ((count1[i] > 0) != (count2[i] > 0)) { // count1[i] 和 count2[i] 仅有一个为0的情况
                return false;  // 字符集不匹配
            }
        }
        sort(count1.begin(), count1.end()); 
        sort(count2.begin(), count2.end()); // 排序频率数组
        for (int i = 0; i < 26; ++i) {
            if (count1[i] != count2[i]) {
                return false;  // 频率不匹配
            }
        }
        return true;  // 所有字符的频率匹配且字符集相同
    }
};