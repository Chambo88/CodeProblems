#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if (s.size() == 0) return 0;
        
        for(int i = 0; i < s.size(); i++) {
            getPalindromes(s, i, i);
            if(i != s.size() - 1) getPalindromes(s, i, i + 1);
        }
        return palindromes;
    }

    void getPalindromes(string& s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            palindromes += 1;
            left--;
            right++;
        }
        return;
    }
private:
    unordered_map<string, bool> is_palindrome{};    
    int palindromes;
};

// class Solution {
// public:
//     int countSubstrings(string s) {
//         if (s.size() == 0) return 0;
        
//         for(int i = 0; i < s.size(); i++) {
//             getPalindromes(s, i, i);
//             if(i != s.size() - 1) getPalindromes(s, i, i + 1);
//         }
//         return palindromes;
//     }

//     void getPalindromes(string& s, int left, int right) {
//         while(left >= 0 && right < s.size() && s[left] == s[right]) {
//             palindromes += 1;
//             left--;
//             right++;
//         }
//         return;
//     }
// private:
//     int palindromes;
// };