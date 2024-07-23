#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm> 
#include <queue>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* previous = nullptr;
        ListNode* temp = nullptr;
        while (current != nullptr)
        {
            temp = current->next;
            current->next = previous;
            previous = current;
            current = temp;
        }
        return current;
    }
};


int main() {
    Solution solution;
    string board = "ab";
    cout << solution.checkInclusion(board, "eidbaooo") << endl;

    return 0;
}