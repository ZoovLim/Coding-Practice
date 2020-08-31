#include <string>
#include <vector>

using namespace std;

int dfs(vector<int> numbers, int target) {
    int count = 0;

    if (numbers.size() == 1) {
        if (numbers[0] == target || numbers[0] == -target) count++;
    }
    else {
        vector<int> tmp = numbers;
        int front = tmp.front();
        tmp.erase(tmp.begin());
        count += dfs(tmp, target + front);
        count += dfs(tmp, target - front);
    }
    return count;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    answer = dfs(numbers, target);

    return answer;
}