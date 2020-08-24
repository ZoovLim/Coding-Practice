#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

bool primeNumber(int n) {
    bool answer = true;
    if (n == 0 || n == 1) return false;
    if (n == 2 || n == 3) return true;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return answer;
}

set<string> findAllComb(string numbers) {
    set<string> s;
    if (numbers.size() == 1) {  // 경계조건 : 크기 1이면 그냥 담는다.
        s.insert(numbers);
        return s;
    }
    else {
        for (int i = 0; i < numbers.size(); i++) {
            // 크기 n인 string numbers에 대하여, "numbers[i]" + "나머지로 이루어지는 모든 문자열 조합" 재귀
            set<string> tmp;
            string tmpStr = numbers;
            tmpStr.erase(i, 1);
            tmp = findAllComb(tmpStr);
            for (string str : tmp) {
                s.insert(str);
                s.insert(numbers.substr(i, 1) + str);
            }
        }
    }
    return s;
}

int solution(string numbers) {
    int answer = 0;
    set<int> numSet;
    for (string num : findAllComb(numbers)) {        
        numSet.insert(stoi(num));
    }
    for (int i : numSet) {
        if (primeNumber(i)) answer++;
    }
    return answer;
}