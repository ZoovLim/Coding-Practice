#include <string>

using namespace std;

string solution(int n) {
    string answer = "";
    int digit = 0;

    while (n != 0) {
        digit = n % 3;
        n = (n % 3 == 0) ? (n / 3) - 1 : n / 3;
        answer = "412"[digit] + answer;
    }

    return answer;
}