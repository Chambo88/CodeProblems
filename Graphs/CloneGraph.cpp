#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> visited{};
        unordered_map<int, vector<Node*>> og_neighbours{};
        Node* first = new Node(node->val);
        queue<Node*> q{};

        og_neighbours[node->val] = node->neighbors;
        visited[node->val] = first;

        q.push(first);

        while(!q.empty()) {
            Node* front_node = q.front();
            q.pop();
            vector<Node*> copy_neighbours{};
            for(auto neighbour: og_neighbours[front_node->val]) {
                if (visited.find(neighbour->val) != visited.cend()) {
                    // we've seen this node before
                    copy_neighbours.push_back(visited[neighbour->val]);
                } else {
                    Node* copy_neighbour = new Node(neighbour->val);
                    copy_neighbours.push_back(copy_neighbour);
                    og_neighbours[neighbour->val] = neighbour->neighbors; 
                    q.push(copy_neighbour);
                }
            }
            front_node->neighbors = copy_neighbours;
        }

        return first;
    }
};