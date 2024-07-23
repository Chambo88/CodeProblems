#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) 
        : m_k(k) {
        for(int num : nums) {
            m_min_heap.push(num);
        }

        while(m_min_heap.size() >= k) {

        }
    }
    
    int add(int val) {
        int kth_value = m_min_heap.top();
        if(val > kth_value) {
            m_min_heap.pop();
            m_min_heap.push(val);
            return m_min_heap.top();
        }
        return kth_value;
    }
private:
    priority_queue<int, vector<int>, greater<int>> m_min_heap;
    int m_k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */