#include <string>

using namespace std;

string solution(int num) {
    string answer = "";

    answer = abs(num) % 2 == 1 ? "Odd" : "Even";
    
    return answer;
}