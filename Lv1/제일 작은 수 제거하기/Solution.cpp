#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = arr[0];
    int minIndex = 0;

    if (arr.size() == 1) {
        return { -1 };
    }

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
    }
    
    answer = arr;
    answer.erase(answer.begin() + minIndex);

    return answer;
}