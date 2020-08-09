#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int index = 1;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            index = 1;
            continue;
        }
        else if (index % 2 == 0) s[i] = tolower(s[i]);
        else s[i] = toupper(s[i]);
        index++;
    }

    return s;
}