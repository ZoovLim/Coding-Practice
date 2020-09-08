class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int empty = 0;

        while (numBottles > 0) {
            ans += numBottles;
            empty = numBottles + (empty % numExchange);
            numBottles = empty / numExchange;
        }

        return ans;
    }
};