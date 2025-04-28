// 2025-4-28
// 933. 最近的请求次数 <Easy> [队列]

#include "environment.h"

using namespace std;

class RecentCounter {
private:
    queue<int> q; // 队列用于存储请求的时间戳
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while (!q.empty() && t - q.front() > 3000) {
            q.pop(); // 移除超过3000毫秒的请求
        }
        q.push(t); // 将当前请求的时间戳加入队列
        return q.size(); // 返回当前队列的大小，即在3000毫秒内的请求数量
    }
};
