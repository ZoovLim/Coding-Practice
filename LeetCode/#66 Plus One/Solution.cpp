#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] + carry >= 10) {
                digits[i] = 0;
            }
            else {
                digits[i] += carry;
                carry = 0;
            }
        }
        if (carry) digits.insert(digits.begin(), 1);
        return digits;
    }
      

};