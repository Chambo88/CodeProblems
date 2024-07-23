#include <functional>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int count = 0;
        
        const function<void(int)> recursive = [&](int current_total) {
            if(current_total == n) return count += 1;
            else if(current_total > n) return;
            recursive(current_total + 1);
            recursive(current_total + 2);
        };

        recursive(0);

        return count;        
    }
};