#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool checkCondition(string str, vector<string> data) {    
    for(auto it : data) { 
        char from = it[0];
        char to = it[2];
        char op = it[3];
        int dist = it[4] - '0';
        switch (op) {
        case '=':
            if (abs((int)(str.find(from) - str.find(to))) - 1 != dist) return false;
            break;            
        case '<':
            if (abs((int)(str.find(from) - str.find(to))) - 1 >= dist) return false;
            break;       
        case '>':
            if (abs((int)(str.find(from) - str.find(to))) - 1 <= dist) return false; 
            break;
        }
    }    
    return true;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string perm = "ACJFMNRT";
    sort(perm.begin(), perm.end());

    do {
        if (checkCondition(perm, data)) answer++;
    } while (next_permutation(perm.begin(), perm.end()));

    return answer;
}