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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        else if(lists.size() == 1)
        {
            return lists[0];
        }
        else
        {
            //split list into two
            //             int mid = lists.size() / 2;
            // vector<ListNode*> left(lists.begin(), lists.begin() + mid);
            // vector<ListNode*> right(lists.begin() + mid, lists.end());
            // ListNode* leftList = mergeKLists(left);
            // ListNode* rightList = mergeKLists(right);
            // return mergeTwoLists(leftList, rightList);
            vector<ListNode*> v2(make_move_iterator(lists.begin() + lists.size() / 2), make_move_iterator(lists.end()));
            lists.erase(lists.begin() + lists.size() / 2, lists.end());
            ListNode* single_list = mergeKLists(lists);
            ListNode* single_list_two = mergeKLists(v2);
            return mergeTwoLists(single_list, single_list_two);
        }
    }

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode fakeFirst(-1, nullptr);
        ListNode * firstNode = &fakeFirst;
        ListNode * marker = firstNode;
        while (list1 != nullptr && list2 != nullptr)
        {
            if(list1->val > list2->val)
            {
                marker->next = list2;
                list2 = list2->next;
            }
            else
            {
                marker->next = list1;
                list1 = list1->next;
            }
            marker = marker->next;
        }
        marker->next = (list1 != nullptr) ? list1 : list2;
        return firstNode->next;
    }
};