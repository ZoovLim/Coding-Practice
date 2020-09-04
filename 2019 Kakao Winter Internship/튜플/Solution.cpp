#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    set<int> nums;
    bool open = false;
    int count = 0;
    string tmp = "";
    map<int, string> h;
    s = s.substr(1, s.length() - 2);
   
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{') open = true;
        else if (s[i] == '}') {
            h[count] = tmp;
            count = 0;
            tmp = "";
            open = false;
        }
        else if (open && s[i] != ',') {
            tmp += s[i];
        }
        else if(open) {
            count++;
            tmp += s[i];
        }
    }
    
    for (auto it : h) {       
        tmp = "";           
        for (int i = 0; i < it.second.size(); i++) {    
            if (it.second[i] != ',') tmp += it.second[i];
            if (it.second[i] == ',' || i == it.second.size() - 1) {                
                if (nums.find(stoi(tmp)) == nums.end()) {
                    nums.insert(stoi(tmp));
                    answer.push_back(stoi(tmp));
                    tmp = "";
                }
                tmp = "";
            }
        }         
    }
    return answer;
}