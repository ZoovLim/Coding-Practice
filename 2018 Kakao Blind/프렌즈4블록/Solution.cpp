#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool isChange = true;
    vector<vector<string>> game(n, vector<string>(m, ""));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) game[j][m - i - 1] += board[i][j];
    }

    while (isChange) {        
        isChange = false;
        for (int i = 0; i < n - 1; i++) {
            if (game[i].empty() || game[i + 1].empty()) continue;
            for (int j = 0; j < min(game[i].size(), game[i + 1].size()) - 1; j++) {
                if ((game[i][j][0] == game[i + 1][j][0]) && (game[i][j + 1][0] == game[i + 1][j + 1][0]) && (game[i][j][0] == game[i][j + 1][0])) {
                    game[i][j] += " ";
                    game[i][j + 1] += " ";
                    game[i + 1][j] += " ";
                    game[i + 1][j + 1] += " ";
                    isChange = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (auto it = game[i].begin(); it != game[i].end();) {
                if ((*it).size() > 1) {
                    it = game[i].erase(it);
                    answer++;
                }
                else it++;
            }
        }
    }
    return answer;
}