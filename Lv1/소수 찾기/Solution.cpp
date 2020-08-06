#include <cmath>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> isPrime(n, true);

    for (int i = 2; i <= sqrt(n); i++) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) answer++;
    }
  
    return answer;
}