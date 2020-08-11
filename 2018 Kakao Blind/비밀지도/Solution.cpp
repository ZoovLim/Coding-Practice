#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < arr1.size(); i++) {
        arr1[i] = arr1[i] | arr2[i];
    }

    for (int i = 0; i < arr1.size(); i++) {
        string tmp = "";
        int digit = 1 << (n - 1);

        for (int j = 0; j < n; j++) {
            if ((arr1[i] & digit) == digit) tmp.push_back('#');
            else tmp.push_back(' ');
            digit = digit >> 1;
        }
        answer.push_back(tmp);
    }

    return answer;
}