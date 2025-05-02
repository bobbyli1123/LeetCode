// 2025-5-2
// 838. 推多米诺 <Medium> [模拟]

#include "environment.h"

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int curr = 0, n = dominoes.length();
        bool right = (dominoes[curr] == 'R');
        while (curr < n) {
            int next = curr + 1;
            while (next < n && dominoes[next] == '.') ++next;
            if (right) {
                if (next == n || dominoes[next] == 'R') {
                    while (curr < next) {
                        dominoes[curr++] = 'R';
                    } 
                } else {
                    if (next != n) {
                        int d = next - curr;
                        int step = 1;
                        while (2 * step < d) {
                            dominoes[curr + step] = 'R';
                            dominoes[next - step] = 'L';
                            ++step;
                        }
                    }
                    right = false;
                }
            } else {
                if (next != n && dominoes[next] == 'L') {
                    while (curr < next) {
                        dominoes[curr++] = 'L';
                    }
                } else {
                    right = true;
                }
            }
            curr = next;
        }
        return dominoes;
    }
};