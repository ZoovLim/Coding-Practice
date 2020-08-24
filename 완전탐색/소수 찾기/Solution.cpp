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
    if (numbers.size() == 1) {  // ������� : ũ�� 1�̸� �׳� ��´�.
        s.insert(numbers);
        return s;
    }
    else {
        for (int i = 0; i < numbers.size(); i++) {
            // ũ�� n�� string numbers�� ���Ͽ�, "numbers[i]" + "�������� �̷������ ��� ���ڿ� ����" ���
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