#include <iostream>
#include <stack>
#include <vector>
#include <unordered_set>
#include <algorithm> 
#include <queue>

using namespace std;


struct ListNode {
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen = {};
        while(head)
        {
            if (seen.find(head) != seen.cend()) return true;
            seen.insert(head);
            head = head->next;
        }
        return false;
    }
};