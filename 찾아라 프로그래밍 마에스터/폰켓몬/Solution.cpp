#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> monsters;

    for (auto i : nums) {
        monsters.insert(i);
    }
    answer = nums.size() / 2 > monsters.size() ? monsters.size() : nums.size() / 2;

    return answer;
}