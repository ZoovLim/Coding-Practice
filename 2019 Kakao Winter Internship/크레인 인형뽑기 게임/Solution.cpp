#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    int tmp = 0;
    vector<int> basket;

    for (int i = 0; i < moves.size(); i++)
    {
        tmp = 0;
        for (int j = 0; j < board.at(0).size(); j++)
        {
            if (board.at(j).at(moves.at(i) - 1) != 0)
            {
                tmp = board.at(j).at(moves.at(i) - 1);
                if (!basket.empty() && basket.back() == tmp)
                {
                    basket.pop_back();
                    answer += 2;
                }
                else
                {
                    basket.push_back(tmp);
                }
                board.at(j).at(moves.at(i) - 1) = 0;
                break;
            }
        }
    }
    return answer;
}