#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;

    for (int i : arr) {
        if (i % divisor == 0) answer.push_back(i);
    }

    sort(answer.begin(), answer.end());

    if (answer.empty()) answer.push_back(-1);

    return answer;
}

int main(void) {
    vector<int> arr = { 5, 9, 7, 10 };
    int divisor = 5;

    solution(arr, divisor);
    
    return 0;
}