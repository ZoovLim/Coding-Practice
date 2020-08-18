#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int xMax, yMax;

int bfs(vector<vector<int>>& p, int x, int y, vector<vector<bool>> &visited) {
    int area = 0;
    int color = p[x][y];
    queue<pair<int, int>> bfsQ;

    bfsQ.push(make_pair(x, y));
    visited[x][y] = true;

    while (!bfsQ.empty()) {
        int x = bfsQ.front().first;
        int y = bfsQ.front().second;
        bfsQ.pop();
        area++;
        p[x][y] = 0;        

        if (x - 1 >= 0 && p[x - 1][y] == color && !visited[x - 1][y]) {
            bfsQ.push(make_pair(x - 1, y));
            visited[x - 1][y] = true;
        }
        if (y - 1 >= 0 && p[x][y - 1] == color && !visited[x][y - 1]) {
            bfsQ.push(make_pair(x, y - 1));
            visited[x][y - 1] = true;
        }
        if (x + 1 <= xMax && p[x + 1][y] == color && !visited[x + 1][y]) {
            bfsQ.push(make_pair(x + 1, y));
            visited[x + 1][y] = true;
        }
        if (y + 1 <= yMax && p[x][y + 1] == color && !visited[x][y + 1]) {
            bfsQ.push(make_pair(x, y + 1));
            visited[x][y + 1] = true;
        }
    }

    return area;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    xMax = m - 1;
    yMax = n - 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0) {
                number_of_area++;
                int area = bfs(picture, i, j, visited);
                max_size_of_one_area = max_size_of_one_area < area ? area : max_size_of_one_area;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}