#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <functional>
#include <iostream>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> map{};
        int shortest_path = 0;
        unordered_map<string, bool> visited{};
        int count = 0;

        // Construct adjacency list
        for (const auto& word : wordList) {
            for (const auto& word2 : wordList) {
                if (isWithinOneLetter(word, word2)) {
                    map[word].push_back(word2);
                }
            }
            if (isWithinOneLetter(beginWord, word)) {
                map[beginWord].push_back(word);
            }
            visited[word] = false;
        }


        const function<void(string)> dfs = [&](string node) {
            if (node == endWord) {
                if(count + 1 < shortest_path) {
                    shortest_path = count + 1;
                }
                cout << "we found the end" << endl;
                return; 
            }
            // found cycle, go back
            if (visited[node]) {
                cout << "we found cycle" << endl;
                return;
            }
            visited[node] = true;
            count += 1;
            for(const auto& bud : map[node]) {
                dfs(bud);
            }
            count -= 1;
            visited[node] = false;
            return;
        };

        dfs(beginWord);

        return count;
    }

    bool isWithinOneLetter(const string& word1, const string& word2) {
        int diff = 0;
        for (int i = 0; i < word1.size(); ++i) {
            if (word1[i] != word2[i]) {
                diff++;
                if (diff > 1) return false;
            }
        }
        return diff == 1;
    }
};