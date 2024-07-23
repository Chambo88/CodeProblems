#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int iterator = 0;
        int end = height.size();
        vector<int> subtract_counter = {};
        int max_of_subset_area = 0;
        int left_hand_height = 0;
        int distance = 0;
        int total = 0;
        while(iterator < end)
        {
            cout << iterator << ": ";
            // we've just set the left side boundry and found a bigger one with 
            if(height[iterator] >= left_hand_height  && distance == 0)
            {
                cout << "setting a new left hand side to - " << height[iterator] << endl;
                left_hand_height = height[iterator];
                distance = -1;
            }
            else if(height[iterator] >= left_hand_height && distance > 0)
            {
                cout << "found a new height thats bigger than the current left hand side. " ;
                cout << "adding area to total:" << left_hand_height * distance - subtract_counter << endl;
                total += left_hand_height * distance - subtract_counter;
                subtract_counter.empty();
                max_of_subset_area = 0;
                left_hand_height = height[iterator];
                distance = -1;
            }
            else if(left_hand_height != 0 && height[iterator] > height[iterator - 1])
            {
                cout << "We are on an incline so caclulating a potential new area to add" << endl;
                int potential_area = (height[iterator] * distance) - subtract_counter;
                if( potential_area > max_of_subset_area) max_of_subset_area = potential_area;
                subtract_counter.push_back(height[iterator]);
                cout << "current max of sub area" << max_of_subset_area << endl;
            }
            else if(left_hand_height !=0 && height[iterator] <= height[iterator -1])
            {
                cout << "We are on an decline so just add subtract value" << endl;
                subtract_counter.push_back(height[iterator]);
            }

            iterator++;
            distance++;
        }
        if(max_of_subset_area) total += max_of_subset_area;
        return total;

    }
};


int main() {
Solution solution;
    vector<int> board = {0,2,0,3,1,0,1,3,2,1
    };

        cout << solution.trap(board) << endl;

    return 0;
}