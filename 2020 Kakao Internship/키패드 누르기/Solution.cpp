#include <string>
#include <vector>

using namespace std;

char middleHand(int number, int leftPos, int rightPos, string hand) {
    int leftDist = (leftPos % 3 == 1) ? abs(number / 3 - leftPos / 3) + 1 : abs(number / 3 - leftPos / 3);
    int rightDist = (rightPos % 3 == 0) ? abs((rightPos / 3 - 1) - number / 3) + 1 : abs(number / 3 - rightPos / 3);

    if (leftDist == rightDist) return toupper(hand[0]);
    else if (leftDist < rightDist) return 'L';
    else return 'R';
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int leftPos = 10;
    int rightPos = 12;
    char h;

    for (int num : numbers) {
        if (num == 0) num = 11;
        if (num % 3 == 1) {
            leftPos = num;
            answer.push_back('L');
        }
        else if (num % 3 == 0) {
            rightPos = num;
            answer.push_back('R');

        }
        else {
            h = middleHand(num, leftPos, rightPos, hand);
            answer.push_back(h);
            if (h == 'L') leftPos = num;
            else rightPos = num;
        }
    }

    return answer;
}