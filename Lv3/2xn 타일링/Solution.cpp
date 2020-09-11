#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> m(n + 1);
    m[0] = 1;
    m[1] = 1;

    for (int i = 2; i <= n; i++) {
        m[i] = (m[i - 1] + m[i - 2]) % 1000000007;
    }
    answer = m[n];
    return answer;
}