#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    vector<char> digits;
    digits.push_back('0');

    int num = 1;
    while (digits.size() < m * t) {
        int tmp = num;
        string str = "";
        while (tmp != 0) {
            if (tmp % n >= 10) str.push_back('A' + tmp % n - 10);
            else str.push_back('0' + tmp % n);
            tmp /= n;
        }
        for (int i = str.size() - 1; i >= 0; i--) digits.push_back(str[i]);
        num++;
    }  
  
    for (int i = 0; i < t; i++) {
        answer += digits[m * i + (p - 1)];
    }
    return answer;
}