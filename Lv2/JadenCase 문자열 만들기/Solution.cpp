#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    bool newWord = true;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            answer += " ";
            if (!newWord) newWord = true;            
        }
        else if (newWord && isalpha(s[i])) {
            newWord = false;
            answer += toupper(s[i]);
        }
        else if (isalpha(s[i])) {
            newWord = false;
            answer += tolower(s[i]);
        }
        else {
            newWord = false;
            answer += s[i];
        }
    }

    return answer;
}