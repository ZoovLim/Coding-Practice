#include <string>
#include <vector>

using namespace std;

bool isComplete(string w);
string convert(string w);
string findFirstBalanced(string w);

string solution(string p) {
    string answer = "";

    if (isComplete(p)) return p;
    answer = convert(p);

    return answer;
}

bool isComplete(string w) { // Check "w" is complete
    bool answer = true;
    int match = 0;

    for (int i = 0; i < w.size(); i++) {
        if (w[i] == '(') match++;
        else if (match == 0) return false;
        else match--;
    }
    return answer;
}

string convert(string w) {  // Main algorithm
    string answer = "";
    if (w == "") return answer;

    string u = findFirstBalanced(w);
    string v = w.substr(u.size());

    if (isComplete(u)) {
        return u + convert(v);
    }

    answer = "(" + convert(v) + ")";
    string tmp = u.substr(1, u.size() - 2);
    
    for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i] == '(') answer += ')';
        else answer += '(';
    }
    return answer;
}

string findFirstBalanced(string w) {    // Find first balanced string in "w"
    string answer = "";
    int open = 0;

    for (int i = 0; i < w.size(); i++) {
        if (open == 0 && answer.size() != 0) return answer;
        else if (w[i] == '(') open++;
        else open--;
        answer.push_back(w[i]);
    }
    return answer;
}