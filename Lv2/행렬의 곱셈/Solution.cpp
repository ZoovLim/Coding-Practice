#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for (int i = 0; i < arr1.size(); i++) {
        vector<int> tmp;
        answer.push_back(tmp);
        for (int j = 0; j < arr2[0].size(); j++) {
            answer[i].push_back(0);
        }
    }

    for (int i = 0; i < arr1.size(); i++) {      
        for (int j = 0; j < arr1[0].size(); j++) {
            for (int k = 0; k < arr2[0].size(); k++) {
                answer[i][k] += arr1[i][j] * arr2[j][k];
            }
        }
    }

    return answer;
}