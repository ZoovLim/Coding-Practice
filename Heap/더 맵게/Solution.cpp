#include <string>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int sc = 0; // ���� ������� ������ ���ں� ����

    // ȿ������ ���� min heap ���
    priority_queue<int, vector<int>, greater<int>> min_heap(scoville.begin(), scoville.end());

    // ���� �� ���ں� ���� �ּҰ��� K �̻��� �� ������ �ݺ�
    while (min_heap.top() < K) {
        if (min_heap.size() == 1) return -1;    // ������ �ϳ� �������� ���ں� ���� K�� �������� ���� ���
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