// 2025-5-6
// 2336. 无限集中的最小数字 <Medium> [堆]

#include "environment.h"

using namespace std;

class SmallestInfiniteSet {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int thredshold = 1;
    unordered_set<int> s;
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if (pq.empty()) {
            return thredshold++;
        } else {
            int num = pq.top();
            pq.pop();
            s.erase(num);
            return num;
        }
    }
    
    void addBack(int num) {
        if (num < thredshold && s.count(num) == 0) {
            s.insert(num);
            pq.push(num);
        }
    }
};