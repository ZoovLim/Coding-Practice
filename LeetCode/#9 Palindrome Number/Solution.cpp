#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {   
        stack<char> digit;
     
        if (x < 0) return false;
        string s = to_string(x);

        for (int i = 0; i < s.size() / 2; i++) {
            digit.push(s[i]);
        }
        for (int i = (s.size() + 1) / 2; i < s.size(); i++) {
            if (s[i] != digit.top()) return false;
            digit.pop();
        }
        return true;
    }
};