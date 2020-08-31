#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        unordered_map<int, int> hash{ make_pair(nums[0], 0) };
       
        for(int i = 1; i < nums.size(); i++) {       
            auto it = hash.find(target - nums[i]);
            if (it != hash.end() && it->second != i) {
                answer.push_back(it->second);
                answer.push_back(i);
                break;
            }
            hash[nums[i]] = i;
        }
        return answer;
    }    
};