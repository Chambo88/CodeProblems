#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <random>

using namespace std;

class Solution{
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count{};
        if(s.size() != t.size()) return false;
        for(auto& letter : s) {
            count[letter]++;
        }
        for(auto& letter : s) {
            count[letter]--;
            if(count[letter] < 0) return false;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        vector<pair<int, int>> add_original{};

        for(int it=0; it<nums.size(); it++) {
            add_original.push_back({nums[it], it});
        }
        sort(add_original.begin(), add_original.end());

        while(add_original[i].first + add_original[j].first != target) {
            if(add_original[i].first + add_original[j].first > target) j--;
            else i++;
        }

        return {add_original[i].second, add_original[j].second};
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups{};
        vector<vector<string>> ans{};

        for(const auto& str : strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            groups[sorted].push_back(str);
        }

        for(const auto& grp : groups) {
            ans.push_back(grp.second);
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(2001, vector<int>{});
        unordered_map<int, int> count_map;
        vector<int> ans{};

        for(auto num : nums) {
            count_map[num]++;
        }

        for(auto& [num, count] : count_map) {
            buckets[count].push_back(num);
        }

        int it = buckets.size() - 1;
        while(k > 0) {
            if(buckets[it].size() != 0) {
                for(auto val : buckets[it]) {
                    ans.push_back(val);
                    k--;
                    if(k == 0) return ans;
                }
            }
            it--;
        }
        return ans;
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        if(m==0) {
            nums1 = nums2;
            return;
        }
        int it_nums1 = 0;
        int it_nums2 = 0;
        vector<int> res{};
        while(it_nums1 + it_nums2!= m + n) {
            if(it_nums1 >= m) {
                res.push_back(nums2[it_nums2]);
                it_nums2++;
            } else if (it_nums2 >= n) {
                res.push_back(nums1[it_nums1]);
                it_nums1++;
            } else {
                if(nums1[it_nums1] >= nums2[it_nums2]) {
                    res.push_back(nums1[it_nums1]);
                    it_nums1++;
                } else {
                    res.push_back(nums2[it_nums2]);
                    it_nums2++;
                }
            }
        }
        nums1 = res;
        return;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> res{};
        int count = 0;
        int slow_ptr = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == val) count ++;
            else {
                nums[slow_ptr] = nums[i];
                slow_ptr++;
            }
        }

        return nums.size() - count;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> seen{};
        int slow_ptr = 0;

        for(int i=0; i<nums.size(); i++) {
            if(seen.find(nums[i]) == seen.end()) {
                seen.insert(nums[i]);
                nums[slow_ptr] = nums[i];
                slow_ptr++;
            }
        }

        return slow_ptr;
    }
};

class Solution {
public:
    int removeDuplicatesTwo(vector<int>& nums) {
        int j = 1;
        bool inserted_double = false;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] != nums[i]) {
                nums[j] = nums[i];
                inserted_double = false;
                j++;
            } else {
                if(!inserted_double) {
                    nums[j] = nums[i];
                    inserted_double = true;
                    j++;
                }
            }
        }
        return j;
    }
};

class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for(auto& str : strs) {
            encoded += to_string(str.length()) + "%" + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans{};
        string meta_data = "";
        auto start = s.begin();
        while(start != s.end()) {
            while(*start != '%') {
                meta_data += *start;
                start++;
            }
            start++;
            string new_string = "";
            for(int i=0; i<stoi(meta_data); i++) {
                new_string += *start;
                start++; 
            }
            meta_data = "";
            ans.push_back(new_string);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int value = nums[0];
        for(int i=1; i<nums.size(); i++) {
            ans[i] = value;
            value *= nums[i];
            
        }

        int value2 = nums[nums.size()-1];
        for(int i=nums.size()-2; i>=0; i--) {
            ans[i] = ans[i] * value2;
            value2 *= nums[i];
        }

        return ans;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // space 0 - 8 for boxes
        // space 9 - 17 for rows
        // space 18 - 26 for cols
        vector<vector<bool>> duplicate_checks(27, vector<bool>(9, false));

        for(int row=0; row<board.size(); row++) {
            for(int col=0; col<board[0].size(); col++) {
                int num  = board[row][col];
                // check box
                int index = (col / 3) + (row / 3) * 3;
                if(duplicate_checks[index][num]) return false;
                duplicate_checks[index][num] = true;

                // check row
                if(duplicate_checks[row + 9][num]) return false;
                duplicate_checks[row + 9][num] = true;

                // checl cols
                if(duplicate_checks[col + 18][num]) return false;
                duplicate_checks[col + 18][num] = true;
            }
        }

        return true;
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
    }
};

class RandomizedSet {
public:
    RandomizedSet() {
        std::random_device rd;
        m_gen = std::mt19937(rd());

        // Define a distribution for integers (e.g., between 1 and 100)

    }
    
    bool insert(int val) {
        m_set.insert(val);
    }
    
    bool remove(int val) {
        m_set.erase(val);
    }
    
    int getRandom() {
        std::uniform_int_distribution<> distrib(0, m_set.size());

        // Generate a random number
        int random_value = distrib(m_gen);
        auto it = m_set.begin();

        for(int i=0; i<random_value; i++) {
            it++;
        }
        return *it;
    }
private:
    unordered_set<int> m_set{};
    std::mt19937 m_gen;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


struct Node {
    Node(int va, Node* up) 
        :val(va), up(up){}

    Node* up = nullptr;
    int val = -1;
    bool is_bottom = false;
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, Node*> seen{};

        for(int i=0; i<nums.size(); i++) {
            // Are there no duplicates? 
            if(seen.find(nums[i]) == seen.cend()){
                Node* newNum = new Node(nums[i], nullptr);
                if(seen.find(nums[i] + 1) != seen.end()) {
                    newNum->up = seen[nums[i] + 1];
                    seen[nums[i] + 1]->is_bottom = false;
                }
                if(seen.find(nums[i] - 1) != seen.end()) {
                    seen[nums[i] - 1]->up = newNum;
                } else {
                    newNum->is_bottom = true;
                }
                seen[nums[i]] = newNum;
            }
        }

        int global_max = 0;
        for(auto [num, node] : seen) {
            int current_max = 1;
            if(node->is_bottom) {
                while(node->up != nullptr) {
                    node = node->up;
                    current_max++;
                }
                global_max = max(global_max, current_max);
            }
        }

        return global_max;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        int left_it = 0;
        int right_it = s.size() - 1;

        while(left_it < right_it) {
            if(!isalpha(s[left_it])) {
                left_it++;
                continue;
            }
            if(!isalpha(s[right_it])) {
                right_it--;
                continue;
            }
            if(tolower(s[left_it]) != tolower(s[right_it])) {
                return false;
            }
            left_it++;
            right_it--;
        }

        return true;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 1) return 0;
        int total = 0;
        int left_it = 0;
        int right_it = height.size() - 1;
        int current_left_peak = height[left_it];
        int current_right_peak = height[right_it];

        while(left_it < right_it) {
            if(current_left_peak <= current_right_peak) {
                current_left_peak = max(height[left_it], current_left_peak);
                total += current_left_peak - height[left_it];
                left_it++;
            } {
                current_right_peak = max(height[right_it], current_right_peak);
                total += current_right_peak - height[right_it];
                right_it--;
            }
        }

        return total;
    }
};

#include <stack>

class MinStack {
public:
    MinStack() {
        m_stack = {};
        m_min = -1;
    }
    
    void push(int val) {
        m_stack.
    }
    
    void pop() {
        
    }
    
    int top() {
        
    }
    
    int getMin() {
        return m_min;
    }
private:
    int m_min;
    stack<int> m_stack;
};