#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    // 효율성을 위해 Hash Map으로 구현. Key - 의상의 종류 (string), Value - 의상의 이름 벡터 (vector<string>)
    unordered_map<string, vector<string>> hMap;

    for (int i = 0; i < clothes.size(); i++) {
        if (hMap.find(clothes[i][1]) == hMap.end()) {
            vector<string> clothesVector;
            clothesVector.push_back(clothes[i][0]);
            hMap.insert(make_pair(clothes[i][1], clothesVector));
        }
        else {
            hMap.find(clothes[i][1])->second.push_back(clothes[i][0]);
        }
    }

    for (auto p : hMap) {
        answer *= p.second.size() + 1;
    }
    answer--;

    return answer;
}