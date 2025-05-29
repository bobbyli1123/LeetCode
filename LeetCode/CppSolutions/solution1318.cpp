// 2025-5-29
// 1318. 或运算的最小翻转次数 <Medium> [位运算]

#include "environment.h"

using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {

        unsigned int y0 = a & b & ~c;
        unsigned int y1 = (a | b) ^ c;
        return popcount(y0) + popcount(y1);
        
    }
};


/*
a b c y0 y1
0 0 1  0  1
0 0 0  0  0
1 0 1  0  0
0 1 1  0  0
1 0 0  0  1
0 1 0  0  1
1 1 1  0  0
1 1 0  1  1

y0 = a & b & ~c

y1 =
~a & ~b & c |
a & b & ~c |
a & ~b & ~c |
~a & b & ~c 
=
~a & ~b & c |
(a | b) & ~c
=
~(a | b) & c |
(a | b) & ~c
=
(a | b) ^ c


*/
