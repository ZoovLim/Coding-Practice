#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> printQ;

    for (int i = 0; i < priorities.size(); i++) {
        printQ.push(make_pair(i, priorities[i]));
    }

    sort(priorities.begin(), priorities.end());

    while (!printQ.empty()) {
        if (printQ.front().second >= *(priorities.end() - 1)) {
            answer++;
            if (printQ.front().first == location) {
                return answer;
            }
            printQ.pop();
            priorities.erase(priorities.end() - 1);
        }
        else {
            pair<int, int> tmp = printQ.front();
            printQ.pop();            
            printQ.push(tmp);
        }
    }

    return answer;
}