#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* front;
        ListNode dummy(0, head);

        while(head != nullptr)
        {
            head = head->next;
            count++;
        }
        head = &dummy;
        front = head;
        for (int i=0; i< count - n; i++)
        {
            head = head->next;
        }

        ListNode* after_remove_node = head->next->next;
        head->next = after_remove_node;
        return front->next;
    }
};