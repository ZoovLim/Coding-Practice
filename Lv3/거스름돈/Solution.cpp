#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<int> m(n + 1);
    m[0] = 1;

    for (int i = 0; i < money.size(); i++) {
        for (int j = 1; j <= n; j++) {
            if (j >= money[i]) m[j] = (m[j] + m[j - money[i]]) % 1000000007;
        }
    }
    answer = m[n];

    return answer;
}