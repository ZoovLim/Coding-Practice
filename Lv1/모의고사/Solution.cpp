#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score(3);
    vector<int> a = { 1, 2, 3, 4, 5 };
    vector<int> b = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> c = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    
 
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == a[i % a.size()]) score[0]++;
        if (answers[i] == b[i % b.size()]) score[1]++;
        if (answers[i] == c[i % c.size()]) score[2]++;
    }

    int max = *max_element(score.begin(), score.end());

    for (int i = 0; i < 3; i++) {
        if (score[i] == max) answer.push_back(i + 1);
    }

    return answer;
}

int main(void) {
    vector<int> v = { 1, 2, 3, 4, 5 };
    solution(v);
    

    return 0;
}