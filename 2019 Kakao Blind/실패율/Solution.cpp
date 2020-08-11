#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, double>& a, const pair<int, double>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    else {
        return a.second > b.second;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> failures;
    double failure[501] = { 0, };
    int users = stages.size();
    double failUsers = 0;

    for (int s : stages) {
        failure[s]++;
    }

    for (int i = 1; i <= N; i++) {
        if (users == 0) failures.push_back(pair<int, double>(i, 0));
        else {
            failUsers = failure[i];
            failure[i] /= users;
            users -= failUsers;
            failures.push_back(pair<int, double>(i, failure[i]));
        }
    }

    sort(failures.begin(), failures.end(), compare);

    for (pair<int, double> p : failures) {
        answer.push_back(p.first);
    }

    return answer;
}