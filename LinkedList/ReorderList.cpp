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
    void reorderList(ListNode* head) {
        int count = 0;
        // ListNode front(-1, nullptr);

        ListNode* front = head;

        //get the length of list so we can half it
        while(head->next != nullptr)
        {
            head = head->next;
            count++;
        }
        head = front;

        // find the middle and cut the first half from the second half
        for(int i=0; i < (count + 1) / 2; i++)
        {
            head = head->next;
        }
        ListNode* right_list = head->next;
        head->next = nullptr;

        ListNode* prev_right_list = nullptr;
        ListNode* temp = nullptr;
        // reverse second half
        while(right_list != nullptr)
        {
            temp = right_list->next;
            right_list->next = prev_right_list;
            prev_right_list = right_list;
            right_list = temp;
        }
        right_list = prev_right_list;

        // merge left and right
        head = front;
        ListNode* temp2;
        while(right_list != nullptr)
        {
            temp = head->next; // new left ptr
            head->next = right_list;
            temp2 = right_list->next; // new right ptr
            right_list->next = temp;
            right_list = temp2;
            head = temp;
        }
    }
};