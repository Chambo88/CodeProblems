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


int main() {
    Solution solution;
    string board = "ab";
    cout << solution.checkInclusion(board, "eidbaooo") << endl;

    return 0;
}