#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int score[100000][4];
    int N = land.size();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            score[i][j] = land[i][j];
        }
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            score[i][j] += max(score[i - 1][(j + 1) % 4], max(score[i - 1][(j + 2) % 4], score[i - 1][(j + 3) % 4]));
        }
    }

    answer = max(score[N - 1][0], max(score[N - 1][1], max(score[N - 1][2], score[N - 1][3])));

    return answer;
}