#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> quantity{};
        unordered_map<char, int> cool{};
        int counter = 0;

        auto comparator = [&](char a, char b) {
            return quantity[a] < quantity[b]; 
        };

        priority_queue<char, vector<char>, decltype(comparator)> pq(comparator);

        for(auto c: tasks) {
            quantity[c]++;
        }

        for(auto p: quantity) {
            pq.push(p.first);
            p.second--;
        }

          // Main loop to process the tasks
        while (!pq.empty() || !cool.empty()) {
            counter++;
            
            if (!pq.empty()) {
                char doing_task = pq.top();
                pq.pop();
                
                // Decrease the quantity of the task
                quantity[doing_task]--;
                
                // If there are more of the task left, put it in the cooldown
                if (quantity[doing_task] > 0) {
                    cool[doing_task] = n + 1; // +1 because we are in a new cycle
                }
            }

            // Decrease the cooldown for all tasks in the cooldown map
            vector<char> to_remove;
            for (auto& c : cool) {
                c.second--;
                if (c.second == 0) {
                    pq.push(c.first);
                    to_remove.push_back(c.first);
                }
            }

            // Remove tasks from the cooldown map whose cooldown period is over
            for (char c : to_remove) {
                cool.erase(c);
            }
        }
        return counter;
    }
};