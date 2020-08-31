#include <string>
#include <vector>

using namespace std;

string pickMax(string number) {   
    int size = number.size();
    for (int i = 0; i < number.size(); i++) {
        if (number[i] >= number[i + 1]) continue;
        else {
            number.erase(number.begin() + i);
            break;
        }
    }
    if (number.size() == size) number.erase(number.begin() + size - 1);
    return number;
}

string solution(string number, int k) {
    string answer = number;

    for (int i = 0; i < k; i++) {
        string tmp = pickMax(answer);
        answer = tmp;
    }

    return answer;
}