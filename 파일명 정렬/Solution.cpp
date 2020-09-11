#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> p1, pair<int, string> p2) {
    string s1Head, s2Head, s1Number, s2Number;
    int i = 1, count = 1;

    while (true) {
        if (p1.second[i] >= '0' && p1.second[i] <= '9') break;
        else i++;
    }
    s1Head = p1.second.substr(0, i);
    i++;
    while (count < 5) {
        if (p1.second[i] >= '0' && p1.second[i] <= '9') count++;
        else break;
        i++;
    }
    s1Number = p1.second.substr(s1Head.size(), count);

    i = 1, count = 1;
    while (true) {
        if (p2.second[i] >= '0' && p2.second[i] <= '9') break;
        else i++;
    }
    s2Head = p2.second.substr(0, i);
    i++;
    while (count < 5) {
        if (p2.second[i] >= '0' && p2.second[i] <= '9') count++;
        else break;
        i++;
    }
    s2Number = p2.second.substr(s2Head.size(), count);

    transform(s1Head.begin(), s1Head.end(), s1Head.begin(), ::tolower);
    transform(s2Head.begin(), s2Head.end(), s2Head.begin(), ::tolower);
    if (s1Head < s2Head) return true;
    else if (s1Head == s2Head) {
       int n1 = stoi(s1Number);
       int n2 = stoi(s2Number);
       if (n1 < n2) return true;
       else if (n1 == n2) return p1.first < p2.first;
       else return false;
    }
    return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<pair<int, string>> fileList;

    for (int i = 0; i < files.size(); i++) {
        fileList.push_back(make_pair(i, files[i]));
    }
    sort(fileList.begin(), fileList.end(), compare);

    for (auto p : fileList) answer.push_back(p.second);

    return answer;
}