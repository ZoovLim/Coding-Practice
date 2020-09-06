#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n) {
    if (n == 3) return true;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    int n = nums.size();

    for (int i = 0; i <= n - 3; i++) {
        for (int j = i + 1; j <= n - 2; j++) {
            for (int k = j + 1; k <= n - 1; k++) {
                if (isPrime(nums[i] + nums[j] + nums[k])) answer++;
            }
        }
    }
    return answer;
}