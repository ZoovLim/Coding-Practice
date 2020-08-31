#include <cstdint>

class Solution {
public:
    int reverse(int x) {
        long long answer = 0;
        while (x != 0) {            
            answer *= 10;
            answer += x % 10;
            x /= 10;
        }
        if (answer > INT32_MAX || answer < INT32_MIN) return 0;
        return (x >= 0) ? answer : -answer;
    }
};