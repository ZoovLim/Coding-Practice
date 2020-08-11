#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    sort(d.begin(), d.end(), less<int>());

    for(int i : d){
        if (budget >= i) {
            budget -= i;
            answer++;
        }
        else return answer;
    }

    return answer;
}