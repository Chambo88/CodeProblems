#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm> 
#include <queue>

using namespace std;

struct LinkNode {
    LinkNode* next;
    LinkNode* prev;
    int val;
    int key;
    LinkNode(
        int value,
        int key,
        LinkNode* prev,
        LinkNode* next) : 
        next(next),
        prev(prev),
        val(value),
        key(key) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        // access our map using key
        if (cache.find(key) != cache.cend())
        {
            put(key, cache[key]->val);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        cout << "current size is" << cache.size() << endl;
        if (cache.find(key) != cache.cend())
        {
            LinkNode* removeAndUpdate = cache[key];
            cache[key] = new LinkNode(value, key, end, nullptr);
            end->next = cache[key];
            if (removeAndUpdate->prev == nullptr)
            {
                front = front->next;
            }
            else
            {
                removeAndUpdate->prev->next = removeAndUpdate->next;
                removeAndUpdate->next->prev = removeAndUpdate->prev;
            }
        }
        else
        {
            cache.emplace(key, new LinkNode(value, key, nullptr, nullptr));
            if(!front)
            {
                end = cache[key];
                front = cache[key];
            }
            else
            {
                // move end across
                end->next = cache[key];
                cache[key]->prev = end;
                end = cache[key];
            }

            if (m_capacity < cache.size())
            {
                int key_to_erase = front->key;
                cout << "erassing" << key_to_erase << endl;

                front->next->prev = nullptr;
                if(front == end)
                {
                    end = front->next;
                }
                front = front->next;
                cache.erase(key_to_erase);
            }
        }
    }

private:
    int m_capacity;
    LinkNode* front = nullptr;
    LinkNode* end = nullptr;
    unordered_map<int, LinkNode*> cache = {};
};