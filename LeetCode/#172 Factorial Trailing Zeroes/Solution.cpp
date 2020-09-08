class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        long long tmp = 1;
        
        if (n == 0) return 0;

        while (true) {
            if (tmp * 5 <= n) tmp *= 5;
            else break;
        }

        while (tmp > 1) {
            ans += n / tmp;
            tmp /= 5;
        }

        return ans;
    }
};