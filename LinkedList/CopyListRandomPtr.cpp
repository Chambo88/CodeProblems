#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm> 
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map = {};
        Node* front = head;
        if (head == nullptr) return nullptr; 
        while(head != nullptr)
        {
            map[head] = new Node(head->val);
            head = head->next;
        }
        head = front;
        while(head != nullptr)
        {
            if (head->random != nullptr) map[head]->random = map[head->random];
            if (head->next != nullptr) map[head]->next = map[head->next];
            head = head->next;
        }
        return map[front];
    }
};