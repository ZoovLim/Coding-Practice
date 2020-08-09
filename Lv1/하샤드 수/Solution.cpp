#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int digitSum = 0;
    int tmp = x;

    while (tmp) {
        digitSum += tmp % 10;
        tmp /= 10;
    }

    answer = (x % digitSum == 0) ? true : false;

    return answer;
}