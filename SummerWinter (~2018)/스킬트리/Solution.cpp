#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<char> skills;

    for (int i = 0; i < skill.size(); i++) {
        skills.push_back(skill[i]);
    }

    for (int i = 0; i < skill_trees.size(); i++) {
        vector<char> tmp = skills;
        answer++;

        for (int j = 0; j < skill_trees[i].size(); j++) {
            if (find(tmp.begin(), tmp.end(), skill_trees[i][j]) == tmp.end()) continue;
            else if (*tmp.begin() == skill_trees[i][j]) {   
                tmp.erase(tmp.begin());
            }
            else {                
                answer--;
                break;
            }
        }
    }

    return answer;
}