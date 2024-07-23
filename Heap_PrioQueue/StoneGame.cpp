#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap{};
        int x = -1;
        int y = -1;
        int result = -1;

        for(int stone : stones) {
            max_heap.push(stone);
        }

        while(max_heap.size() > 1) {
            x = max_heap.top();
            max_heap.pop();
            y = max_heap.top();
            max_heap.pop();
            result = abs(x - y);
            if(result == 0) continue;
            max_heap.push(result);
        }

        if(max_heap.size()) return max_heap.top();
        return 0;
        
    }

};

int main() {
    vector<int> stones{5,4,1,2,4};
    Solution sol{};
    int val = sol.lastStoneWeight(stones);
    return 0;
}