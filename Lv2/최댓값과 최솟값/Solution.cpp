#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> nums;
    int num = 0;
    int sign = 1;

    for (char c : s) {
        if (c == '-') sign = -1;
        else if (c == ' ') {
            nums.push_back(sign * num);
            sign = 1;
            num = 0;
        }
        else {
            num *= 10;
            num += c - '0';
        }           
    }
    nums.push_back(sign * num);

    sort(nums.begin(), nums.end());
    answer = to_string(nums[0]) + " " + to_string(nums[nums.size() - 1]);

    return answer;
}