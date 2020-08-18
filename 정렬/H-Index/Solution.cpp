#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());

    for (int h = citations.size(); h > 0; h--) {
        for (int i = 0; i < h; i++) {
            if (citations[i] < h) break;
            if (i == h - 1) return h;
        }
    }

    return answer;
}