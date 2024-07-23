#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //first is temperature, second is index
        stack<pair<int, int>> waitingList = {};
        vector<int> daysWaited(temperatures.size());
        for (int i=0;i<temperatures.size();i++) 
        {
                while (!waitingList.empty() && waitingList.top().first < temperatures[i])
                {
                    daysWaited[waitingList.top().second] = i - waitingList.top().second;
                    waitingList.pop();
                }
                waitingList.push({temperatures[i], i});


        }
        while (!waitingList.empty())
        {
            daysWaited[waitingList.top().second] = 0;
            waitingList.pop();
        }
        return daysWaited;
    }
};


int main() {
Solution solution;
    vector<int> board = {73,74,75,71,69,72,76,73
    };

    auto result = solution.dailyTemperatures(board);

    for (auto s : result)
    {
        cout << s;
    }

    return 0;
}