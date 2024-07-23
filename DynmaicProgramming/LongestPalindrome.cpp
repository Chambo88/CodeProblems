#include <string>
#include <unordered_map>
#include <functional>
#include <stack>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string longest {s[0]};

        const function<void(string&)> findPalindrome = [&](string& evaluate) {
            if(isPalindrome(evaluate)) {
                if(evaluate.size() > longest.size()) {
                    longest = evaluate;
                }
                return;
            }
            string left(evaluate.begin(), evaluate.end() - 1);
            string right(evaluate.begin() + 1, evaluate.end());

            findPalindrome(left);
            findPalindrome(right);
        };

    }

    bool isPalindrome(string& s) {
        if(s.size() == 1) return true;
        if(m_palindrome_memoize.find(s) != m_palindrome_memoize.cend()) {
            return m_palindrome_memoize[s];
        }
        int iterator = 0;
        int end_iterator = s.size() - 1;
        while(iterator < end_iterator) {
            string test(s.begin() + iterator, s.end() - iterator);
            if(m_palindrome_memoize.find(test) != m_palindrome_memoize.cend()) {
                return m_palindrome_memoize[test];
            }
            if(s[iterator] != s[end_iterator]) {
                m_palindrome_memoize[s] = false;
                return false;
            }
            iterator++;
            end_iterator--;
        }
        m_palindrome_memoize[s] = true;
        return true;
    }

private:
    unordered_map<string, bool> m_palindrome_memoize{};
};