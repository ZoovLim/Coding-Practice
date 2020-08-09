#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> digitV;
    int d = 1;

    while (n) {
        digitV.push_back(n % 10);
        n /= 10;
    }

    sort(digitV.begin(), digitV.end(), less<int>());

    for (int i : digitV) {
        answer += d * i;
        d *= 10;
    }

    return answer;
}