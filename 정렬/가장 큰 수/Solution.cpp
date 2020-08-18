#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> nums;

    for (int i : numbers) {
        nums.push_back(to_string(i));
    }

    sort(nums.begin(), nums.end(), compare);

    for (string s : nums) {
        answer += s;
    }

    if (answer.front() == '0') return "0";

    return answer;
}