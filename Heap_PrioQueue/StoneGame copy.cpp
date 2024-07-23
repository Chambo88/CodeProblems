#include <vector>
#include <queue>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
   
struct CustomComparator {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        return sqrt(a[0]*a[0] + a[1]*a[1]) > sqrt(b[0]*b[0] + b[1]*b[1]);
    }
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // Create the heap using custom comparator
    make_heap(points.begin(), points.end(), CustomComparator());

    // Initialize the priority queue with the heap data and custom comparator
    priority_queue<vector<int>, vector<vector<int>>, CustomComparator> pq(points.begin(), points.end());

    // Extract the k closest points
    vector<vector<int>> k_elements;
    for (int i = 0; i < k; ++i) {
        k_elements.push_back(pq.top());
        pq.pop();
    }

    return k_elements;
}
};


int main() {
    vector<int> stones{5,4,1,2,4};
    Solution sol{};
    int val = sol.lastStoneWeight(stones);
    return 0;
}