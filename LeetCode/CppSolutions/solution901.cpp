// 2025-5-29
// 901. 股票价格跨度 <Medium> [单调栈]

#include "environment.h"

using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> ms; // <price, day>
    int day;
public:
    StockSpanner() {
        day = 0;
    }
    
    int next(int price) {
        ++day;
        while (!ms.empty() && price >= ms.top().first) {
            ms.pop();
        }
        int span = ms.empty() ? day : day - ms.top().second;
        ms.emplace(price, day);
        return span;
    }
};
