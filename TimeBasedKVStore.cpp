#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm> 


using namespace std;

class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) { b 
        int index = 0;
        if (!values[key].empty()) int index = binSearch(values[key], timestamp);
        values[key].insert(index + values[key].begin(), {timestamp, value});
    }
    
    string get(string key, int timestamp) {
        cout << "anything " <<endl;
        int index = binSearch(values[key], timestamp);
        if (index == -1) return "";

        return values[key][index].second;
    }

    int binSearch(vector<pair<int, string>>& searchList, int timestamp)
    {
        int l = 0;
        int r = searchList.size();
        int mid;
        if (searchList[0].first > timestamp)
        {
            return -1;
        }
        while (l <= r)
        {
            mid = (l + r) /2;
            if (searchList[mid].first == timestamp) return mid;
            if (r - l == 1) return l;
            if (searchList[mid].first > timestamp)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        return l;
    }

private:
    unordered_map<string, vector<pair<int, string>>> values = {};
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */


int main() {
    TimeMap solution;
    vector<int> board = {1,2,3,4};
    solution.set("key", "value", 1);

    cout << solution.get("key",0) << endl;

    return 0;
}