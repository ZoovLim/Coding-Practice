#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int weight = limit;
    deque<int> p;
    sort(people.begin(), people.end(), greater<int>());
    for (int i = 0; i < people.size(); i++) p.push_back(people[i]);

    while (!p.empty()) {
        answer++;
        weight -= p.front();
        p.pop_front();        
        if (!(p.empty()) && (weight >= p.back())) {
            p.pop_back();
        }
        weight = limit;
    }
    return answer;
}