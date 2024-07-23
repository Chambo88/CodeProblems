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
        ListNode* iterator = head;
        ListNode* prev = nullptr;
        while(iterator != nullptr) {
            ListNode* current = iterator;
            iterator = iterator->next;
            current->next = prev;
            prev = current;
        }
        return prev;
    }
};