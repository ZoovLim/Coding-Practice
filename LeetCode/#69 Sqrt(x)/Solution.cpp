#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long ans = 1;

        while (true) {
            if (ans * ans > x) return ans - 1;            
            else ans++;
        }
        return 0;
    }
};