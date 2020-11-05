#include <string>
#include <vector>

using namespace std;

vector<int> quadComp(vector<vector<int>> &arr, int rowStart, int colStart, int size)
{
    vector<int> answer(2, 0);
    if (size == 1)
    {
        answer[arr[rowStart][colStart]]++;
        return answer;
    }

    // 모든 수가 같기 위해서 다른 숫자가 존재하는지 확인하기 위한 변수
    bool allSame = true;
    int num = arr[rowStart][colStart];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (num != arr[rowStart + i][colStart + j])
            {
                allSame = false;
                break;
            }
        }
    }

    // 압축 가능한 경우와 그렇지 않은 경우(재귀 실행) 분기 구현
    if (allSame)
    {
        answer[num] = 1;
        return answer;
    }
    else
    {
        vector<int> tmp1 = quadComp(arr, rowStart, colStart, size / 2);
        vector<int> tmp2 = quadComp(arr, rowStart + size / 2, colStart, size / 2);
        vector<int> tmp3 = quadComp(arr, rowStart, colStart + size / 2, size / 2);
        vector<int> tmp4 = quadComp(arr, rowStart + size / 2, colStart + size / 2, size / 2);
        answer[0] = tmp1[0] + tmp2[0] + tmp3[0] + tmp4[0];
        answer[1] = tmp1[1] + tmp2[1] + tmp3[1] + tmp4[1];
    }
    return answer;
}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer;
    answer = quadComp(arr, 0, 0, arr.size());
    return answer;
}