#include <iostream>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int bigger;

    answer = a >= b ? b : a;
    bigger = a >= b ? a : b;

    for (int i = answer + 1; i <= bigger; i++) {
        answer += i;
    }

    return answer;
}

int main(void) {
    int a, b;

    cin >> a >> b;
    cout << solution(a, b) << endl;

    return 0;
}