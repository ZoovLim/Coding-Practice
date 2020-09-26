#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    queue<int> q;
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> d(n + 1, 0);
    int max = 0;

    for (auto e : edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto i : graph[v]) {
            if (!visited[i]) {
                visited[i] = true;
                d[i] = d[v] + 1;
                q.push(i);
                max = d[i];
            }
        }
    }

    for (auto v : d) if (v == max) answer++;

    return answer;
}