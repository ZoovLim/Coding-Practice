#include <iostream>
#include <string>

using namespace std;

int solution(string s)
{
    int answer = 0;

    for (int i = s.size(); i >= 1; i--) {
        for (int j = 0; j <= s.size() - i; j++) {
            bool flag = true;
            int start = j;
            int end = j + i - 1;
            for (int k = 0; k < i / 2; k++) {
                if (s[start + k] != s[end - k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) return i;
        }
    }    

    return answer;
}
