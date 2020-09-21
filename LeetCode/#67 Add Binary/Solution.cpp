#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = 0;
        int carry = 0;
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());      

        while (i < a.size() || i < b.size()) {
            int n1 = 0, n2 = 0;
            if (i < a.size()) n1 = a[i] - '0';
            if (i < b.size()) n2 = b[i] - '0';
            ans.push_back('0' + (n1 + n2 + carry) % 2);
            carry = (n1 + n2 + carry) / 2;
            i++;
        }
        if (carry) ans.push_back('1');
        reverse(ans.begin(), ans.end());

        return ans;
    }
};