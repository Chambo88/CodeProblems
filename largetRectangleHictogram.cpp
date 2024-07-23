#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        // In format, {position, height}
        stack<pair<int, int>> toMultiply{};
        int max = 0;
        heights.push_back(0);
        for(int i=0;i<heights.size();i++)
        {   
            // if the height of the bar by itself is greater we can just set the new max
            // if (heights[i] > max) max = heights[i];
            // if there is nothing in the stack we can just add our potential to the stack
            if (heights[i] >= 0 && toMultiply.empty())
            {
                toMultiply.push({i, heights[i]});
            }
            // if the most recently added and current are equal, ignore the new one and just test the new area
            // else if (toMultiply.top().second == heights[i])
            // {
            //     if (heights[i] * (1 + i - toMultiply.top().first));
            // }
            else if(toMultiply.top().second < heights[i])
            {
                toMultiply.push({i, heights[i]});
            }
            else 
            {
                int new_i = i;
                while(!toMultiply.empty() && toMultiply.top().second > heights[i])
                {
                    // test potential area
                    if (toMultiply.top().second * (i - toMultiply.top().first) > max)
                    {
                        max = toMultiply.top().second * (i - toMultiply.top().first);
                    }
                    // we need to shift the new potential back for future guesses
                    new_i = toMultiply.top().first;
                    toMultiply.pop();
                }
                if(heights[i] != 0) toMultiply.push({new_i, heights[i]});
            }
                // cout << "round: " << i << endl;

                // stack<pair<int, int>> copy(toMultiply);

                // while (!copy.empty())
                // {
                //     cout << copy.top().second << " ";
                //     copy.pop();
                // }
                // cout << endl;
        }
        return max;
    }
};


int main() {
Solution solution;
    vector<int> board = {3,6,5,7,4,8,1,0
    };

    auto result = solution.largestRectangleArea(board);

    cout << result << endl;

    // for (auto s : result)
    // {
    //     cout << s;
    // }

    return 0;
}