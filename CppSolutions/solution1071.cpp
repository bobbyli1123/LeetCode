// 2025-4-26
// 1071. 字符串的最大公因子 <Easy> [字符串][贪心]

#include "environment.h"

using namespace std;

class Solution {
public:
    bool check(string str1, string str2) {
        int times = str1.size() / str2.size();
        string temp = "";
        for (int i = 0; i < times; ++i) {
            temp += str2;
        }
        return temp == str1;
    }

    string gcdOfStrings(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        string p = str1.substr(0, __gcd(m, n));
        if (check(str1, p) && check(str2, p)) return p;
        return "";
    }
};

int main() {
    return 0;
}