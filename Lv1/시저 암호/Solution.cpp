#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    int alphas = 'z' - 'a' + 1;

    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) s[i] = isupper(s[i]) ? 'A' + ((s[i] - 'A' + n) % alphas) : 'a' + ((s[i] - 'a' + n) % alphas);
        answer.push_back(s[i]);
    }

    return answer;
}