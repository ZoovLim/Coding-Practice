#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int firstPos = 0;
    int d = 1;
    bool isPositive = true;

    if (!isdigit(s[0])) {
        if(s[0] == '-') isPositive = false;
        firstPos++;
    }

    for (int i = s.size() - 1; i >= firstPos; i--, d *= 10) {
        answer += d * (s[i] - '0');
    }

    if (!isPositive) answer *= -1;

    return answer;
}