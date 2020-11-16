#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    int answer = 0;
    int height = triangle.size();
    vector<vector<int>> dp(height);

    for (int i = 0; i < height; i++)
    {
        dp[i] = vector<int>(triangle[i].begin(), triangle[i].end());
    }

    for (int i = 1; i < height; i++)
    {
        dp[i][0] += dp[i - 1][0];
        dp[i][i] += dp[i - 1][i - 1];
        for (int j = 1; j < i; j++)
        {
            dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }

    for (int i = 0; i < height; i++)
    {
        answer = max(answer, dp[height - 1][i]);
    }

    return answer;
}