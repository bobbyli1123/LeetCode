// 2025-6-5 (daily)
// 1061. 按字典序排列最小的等效字符串 <Medium> [并查集]

#include "environment.h"

using namespace std;

class Solution {
private:
    vector<int> parents = vector<int>(26);
public:
    int find(int x) {
        return parents[x] == x ? x : (parents[x] = find(parents[x]));
    }
    void to_union(int x1, int x2) {
        int p1 = find(x1), p2 = find(x2);
        if (p1 != p2) {
            if (p1 < p2) parents[p2] = p1;
            else parents[p1] = p2;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        iota(parents.begin(), parents.end(), 0);
        for (int i = 0; i < s1.size(); ++i) {
            to_union(s1[i] - 'a', s2[i] - 'a');
        }
        for (auto &c : baseStr) {
            c = find(c - 'a') + 'a';
        }
        return baseStr;
    }
};