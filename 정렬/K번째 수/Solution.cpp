#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (vector<int> v : commands) {
        vector<int> tmp;
        int start;

        for (int i = 0, start = v[0] - 1; i <= (v[1] - v[0]); i++) {
            tmp.push_back(array[start++]);
        }

        sort(tmp.begin(), tmp.end(), less<int>());

        answer.push_back(tmp[v[2] - 1]);
    }

    return answer;
}