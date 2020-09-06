#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> chars;

    if (s.empty()) return 1;

    chars.push(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (!chars.empty() && s[i] == chars.top()) chars.pop();
        else chars.push(s[i]);
    }
    answer = chars.empty() ? 1 : 0;

    return answer;
}