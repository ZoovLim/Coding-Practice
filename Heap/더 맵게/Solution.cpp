#include <string>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int sc = 0; // 새로 만들어진 음식의 스코빌 지수

    // 효율성을 위한 min heap 사용
    priority_queue<int, vector<int>, greater<int>> min_heap(scoville.begin(), scoville.end());

    // 음식 중 스코빌 지수 최소값이 K 이상이 될 때까지 반복
    while (min_heap.top() < K) {
        if (min_heap.size() == 1) return -1;    // 음식이 하나 남았으나 스코빌 지수 K에 도달하지 못한 경우
        int sc1 = min_heap.top();    
        min_heap.pop();
        int sc2 = min_heap.top();
        min_heap.pop();
        sc = sc1 + 2 * sc2;
        min_heap.push(sc);
        answer++;
    }

    return answer;
}