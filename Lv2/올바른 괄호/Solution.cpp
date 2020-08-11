#include <string>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int open = 0;

    for (char c : s) {
        if (c == ')') {
            if (!open) return false;
            else open--;
        }
        else open++;
    }

    if (open) return false;

    return answer;
}