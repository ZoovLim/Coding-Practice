#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int keyNum = relation[0].size();
    int allCombs = 1 << keyNum;
    int tmp, digit;
    vector<int> uniqueKeys;

    for (int i = 1; i < allCombs; i++) {
        vector<int> keys;
        unordered_set<string> tuples;
        tmp = allCombs >> 1, digit = 0;
        while (tmp != 0) {
            if (tmp & i) keys.push_back(digit);
            tmp >>= 1;
            digit++;
        }    
        uniqueKeys.push_back(i);
        for (int j = 0; j < relation.size(); j++) {
            string tuple;
            for (int k = 0; k < keys.size(); k++) tuple += relation[j][keys[k]] + ".";
            if (tuples.find(tuple) != tuples.end()) {
                uniqueKeys.erase(--uniqueKeys.end());
                break;
            }
            tuples.insert(tuple);
        }        
    }
 
    for (auto it = uniqueKeys.begin(); it != uniqueKeys.end();) {
        for (auto it2 = it + 1; it2 != uniqueKeys.end();) {
            if ((*it & *it2) == *it) it2 = uniqueKeys.erase(it2);
            else it2++;
        }
        it++; 
    }

    answer = uniqueKeys.size();

    return answer;
}