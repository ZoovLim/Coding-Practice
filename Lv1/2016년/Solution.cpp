#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<int> days = { 31, 29, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31 };
    vector<string> day = { "THU", "FRI", "SAT", "SUN", "MON", "TUE","WED" };
    int d = 0;

    for (int i = 0; i < a - 1; i++) {
        d += days[i];
    }
    d += b;

    answer = day[d % 7];

    return answer;
}

int main(void) {
    int a, b;
    cin >> a >> b;
    cout << solution(a, b) << endl;

    return 0;
}