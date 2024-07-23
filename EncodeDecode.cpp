#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        // we want to encode the string qith length + # + word + length ....
    }

    vector<string> decode(string s) 
    {
        
    }
};


int main() {
    Solution test_class = Solution();
    vector<int> based = {1,1,1,2,2,3};
    vector<int>  returnee = test_class.topKFrequent(based, 3);
    cout <<" ell ";

    for(auto& group : returnee)
    {
        cout << group << " ";
        cout << endl;
    }
}