#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        queue<pair<int,int>> q {};

        q.push({hand[0], hand[0]});
        int prev = hand[0];
        int building = 1;
        int built = 0;
        for(int i=1; i<hand.size(); i++) {
            if(hand[i] - prev >= 2 && building != 0) return false;
            if(q.empty()) {
                if(groupSize - built - building <= 0) return false;
                else { // We can
                    building++;
                    q.push({hand[i], hand[i]});
                }
            } else {
                pair<int, int> front = q.front();

                if(front.first == hand[i]) {
                    // Can we create another hand?
                    if(groupSize - built - building <= 0) return false;
                    else { // We can
                        building++;
                        q.push({hand[i], hand[i]});
                    }
                }
                else if(hand[i] - front.first >=2) {
                    return false;
                }
                // must be addable
                else {
                    front.first = hand[i];
                    if(front.first - front.second == groupSize - 1) {
                        building--;
                        built++;
                    } else {
                        q.push(front);
                    }
                    q.pop();

                }
            }
        }

        if(!q.empty()) return false;

        return true;
    }
};