#include <string>
#include <vector>

using namespace std;

int countBinary(int n) {
    int count = 0;

    while (n != 0) {
        if (n % 2 == 1) count++;
        n /= 2;
    }

    return count;
}

int solution(int n) {
    int answer = 0;
    int count = countBinary(n);

    while (true) {
        n++;
        if (count == countBinary(n)) return n;
        else if (n > 1000000) break;
    }

    return answer;
}