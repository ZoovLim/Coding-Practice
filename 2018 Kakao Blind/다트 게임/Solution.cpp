#include <string>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int index = 0;
    int scores[4] = { 0, };

    for (int i = 0; i < dartResult.size(); i++) {
        if (isdigit(dartResult[i])) {
            if (dartResult[i - 1] == '1') scores[index] = 10;
            else {
                index++;
                scores[index] = dartResult[i] - '0';
            }
        }
        else if (isalpha(dartResult[i])) {
            switch (dartResult[i]) {
            case 'D':
                scores[index] = pow(scores[index], 2);
                break;
            case 'T':
                scores[index] = pow(scores[index], 3);
                break;
            }            
        }
        else if (dartResult[i] == '*') {
            scores[index] *= 2;
            scores[index - 1] *= 2;
        }
        else {
            scores[index] *= -1;
        }
    }

    for (int i = 1; i <= 3; i++) {
        answer += scores[i];
    }
   
    return answer;
}