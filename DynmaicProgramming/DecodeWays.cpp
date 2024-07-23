#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int total = 0;
        int total_until_fixed = 0;
        for(int i=s.size()-1; i>=0; i-- ) {
            //reached fixed
            if(s[i] - '0' == 0) {
                if(i == 0 || (s[i-1] - '0' != 1 && s[i-1] - '0' != 2)) {
                    return 0;
                } 
                i--;
                total += fibbonacci(total_until_fixed);
                total_until_fixed = 0;
            }
            // 7 8 9
            else if(s[i] - '0' >= 7) {
                total += fibbonacci(total_until_fixed);
                total_until_fixed = 0;
            }
            // 3 4 5 6
            else if(s[i] - '0' >= 3){
                if(i > 0 && (s[i-1] - '0' == 2 || s[i-1] - '0' == 1)) {
                    total_until_fixed++;
                }
                else {
                    total += fibbonacci(total_until_fixed);
                    total_until_fixed = 0;
                }
            }
            // 1 2
            else {
                total_until_fixed++;
            }
        }
        total += fibbonacci(total_until_fixed);

        return total;
    }

    int fibbonacci(int n) {
        if(n == 0) return 0;
        int one = 0;
        int two = 1;
        for(int i=0; i<n; i++) {
            int temp = two;
            two = one + two;
            one = temp;
        }
        return two;
    }
};

// aaaa

// aa
// a a

// a aa 
// a a a
// aa a

// a aa a
// aa aa
// aa a a
// a a aa
// a a a a

// 2*2*2*2

// class Solution {
// public:
//     int numDecodings(string s) {
//         if(s.size() == 0) return 0;
//         if(s.size() == 1 && s[0] - '0' >= 3) return 1;

//         // 11106
//         int count = 0;
//         for(int i = s.size() - 1; i > 0; i--) {
//             if( s[i] - '0' >= 3 && s[i] - '0' <= 6) {
//                 cout << "what is in here?" << endl;
//                 if(s[i-1] - '0' == 2 || s[i-1] - '0' == 1) {
//                     count++;
//                 }
//             }
//             else if(s[i] - '0' == 0) {
//                 if(s[i-1] - '0' != 1 && s[i-1] - '0' != 2) {
//                     cout << "what is in here 2 ?" << endl;
//                     return 0;
//                 }
//                 else {
//                     i--;
//                 }
//             }
//             else if(s[i] - '0' >= 7) {
//                     i--;
//             }
//             else {
//                 count++;
//             }
//             cout << "what is count " << count << endl;

//         }

//         if(s[0] -'0' == 0) return 0;
//         if(s[0] -'0' == 1 || s[0] - '0' == 2) count++;
//         if (count == 0) return 1;

//         int one = 0;
//         int two = 1;
//         for(int i=0; i<count; i++) {
//             int temp = two;
//             two = one + two;
//             one = temp;
//         }

//         return two;
//     }
// };