#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_set<string> w;
    answer = { 0, 0 };
    w.insert(words[0]);

    for (int i = 1; i < words.size(); i++) {
        if (words[i].at(0) != words[i - 1].at(words[i - 1].size() - 1) || w.find(words[i]) != w.end()) {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        else w.insert(words[i]);
    }

    return answer;
}