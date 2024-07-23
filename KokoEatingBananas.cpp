#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm> 


using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int k, potential_k = - 1;
        while(l <= r)
        {
            k = (l + r) / 2;
            if (checkIfEatable(piles, k, h))
            {
                potential_k = k;
                r = k - 1;
            }
            else 
            {
                l = k + 1;
            }
        }
        return potential_k;
    }

    bool checkIfEatable(vector<int> nanas, int k,int h)
    {
        int hours_needed = 0;
        for(const auto& nana : nanas)
        {
            hours_needed += (nana + k - 1) / k;
            if (hours_needed > h) return false;
        }
        return true;
    }
};


int main() {
Solution solution;
    vector<int> board = {332484035,524908576,855865114,632922376,222257295,690155293,112677673,679580077,337406589,290818316,877337160,901728858,679284947,688210097,692137887,718203285,629455728,941802184};

    cout << solution.minEatingSpeed(board, 6) << endl;

    return 0;
}