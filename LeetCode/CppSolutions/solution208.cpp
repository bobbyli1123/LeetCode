// 2025-5-29
// 208. 实现 Trie (前缀树) <Medium> [前缀树]

#include "environment.h"

using namespace std;

class Trie {
private:
    vector<vector<int>> trie;
    vector<bool> end;

public:
    Trie() {
        trie.emplace_back(26, 0);
        end.push_back(false);
    }
    
    void insert(string word) {
        int curr = 0;
        for (char c : word) {
            int next = trie[curr][c - 'a'];
            if (next == 0) {
                next = trie.size();
                trie.emplace_back(26, 0);
                trie[curr][c - 'a'] = next;
                end.push_back(false);
            }
            curr = next;
        }
        end[curr] = true;
    }
    
    bool search(string word) {
        int curr = 0;
        for (char c : word) {
            int next = trie[curr][c - 'a'];
            if (next == 0) return false;
            else curr = next;
        }
        return end[curr];
    }
    
    bool startsWith(string prefix) {
        int curr = 0;
        for (char c : prefix) {
            int next = trie[curr][c - 'a'];
            if (next == 0) return false;
            else curr = next;
        }
        return true;
    }
};
