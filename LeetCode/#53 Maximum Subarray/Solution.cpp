#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LONG_MIN;
        long long second = LONG_MIN;
        long long third = LONG_MIN;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > first) {
                third = second;
                second = first;
                first = nums[i];
            }
            else if (nums[i] > second) {
                if (nums[i] == first) continue;
                third = second;
                second = nums[i];
            }
            else if (nums[i] > third) {
                if (nums[i] == second) continue;
                third = nums[i];
            }
        }

        return third == LONG_MIN ? first : third;
    }
};