#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    for (int i = 0; i < strings.size(); i++) {
        strings[i] = strings[i][n] + strings[i].substr(0, strings[i].size());
    }

    sort(strings.begin(), strings.end());

    for (int i = 0; i < strings.size(); i++) {
        strings[i] = strings[i].substr(1, strings[i].size());
    }

    return strings;
}