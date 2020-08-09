#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<int> newReserve;

    for (int i : reserve) {
        if (lost.end() != find(lost.begin(), lost.end(), i)) {
            lost.erase(find(lost.begin(), lost.end(), i));
        }
        else {
            newReserve.push_back(i);
        }
    }

    for (int i : newReserve) {
        if (lost.end() != find(lost.begin(), lost.end(), i - 1)) lost.erase(find(lost.begin(), lost.end(), i - 1));
        else if (lost.end() != find(lost.begin(), lost.end(), i + 1)) lost.erase(find(lost.begin(), lost.end(), i + 1));
    }

    answer -= lost.size();
    
    return answer;
}