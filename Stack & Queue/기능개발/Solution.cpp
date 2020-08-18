#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> dayQ;

    for (int i = 0; i < progresses.size(); i++) {
        int day = (100 - progresses[i]) / speeds[i];
        
        if ((100 - progresses[i]) % speeds[i] != 0) day++;

        dayQ.push(day);
    }

    while (!dayQ.empty()) {
        int finish = 1;
        int day = dayQ.front();
        dayQ.pop();

        while (!dayQ.empty()) {
            if (day >= dayQ.front()) {
                finish++;
                dayQ.pop();
            }
            else break;
        }

        answer.push_back(finish);
    }
    
    return answer;
}