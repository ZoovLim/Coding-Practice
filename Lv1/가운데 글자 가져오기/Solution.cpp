#include <iostream>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int length = s.size();

    if (length % 2 == 0) answer.push_back(s[length / 2 - 1]);

    answer.push_back(s[length / 2]);

    return answer;
}

int main(void) {
    string s = "";
    cin >> s;
    cout << solution(s) << endl;

    return 0;
}