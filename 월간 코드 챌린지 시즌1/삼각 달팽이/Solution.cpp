#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> tmp(n, vector<int>(n, 0));
    int end = n * (n + 1) / 2;
    int i = 1;
    int rowS = 0, rowE = n - 1;
    int colS = 0, colE = n - 1;

    while (i <= end) {
        for (int j = rowS; j <= rowE; j++) {
            tmp[j][colS] = i++;
        }
        for (int j = ++colS; j <= colE; j++) {
            tmp[rowE][j] = i++;
        }
        int rowT = rowE - 1, colT = colE - 1;
        for (; rowT > rowS;) {
            tmp[rowT--][colT--] = i++;
        }
        rowS += 2, rowE--;
        colE -= 2;
    }

    for (auto v : tmp) {
        for (auto a : v) {
            if (a != 0) answer.push_back(a);
        }
    }

    return answer;
}