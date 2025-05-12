// 2025-4-28
// 649. Dota2 参议院 <Medium> [模拟]

#include "environment.h"

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        deque<char> q(senate.begin(), senate.end());
        int rbanned = 0, dbanned = 0, r = 0, d = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                char curr = q.front();
                q.pop_front();
                if (curr == 'R') {
                    if (rbanned > 0) --rbanned;
                    else {
                        ++dbanned;
                        ++r;
                        q.push_back('R');
                    }
                } else {
                    if (dbanned > 0) --dbanned;
                    else {
                        ++rbanned;
                        ++d;
                        q.push_back('D');
                    }
                }
            }
            if (r == q.size()) return "Radiant";
            else if (d == q.size()) return "Dire";
            else {
                d = r = 0;
            }
        }
        return "";
    }
};