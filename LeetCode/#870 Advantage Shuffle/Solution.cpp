#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> advantageCount(vector<int> &A, vector<int> &B)
    {
        vector<int> tmpA(A.begin(), A.end());
        vector<int> answer;

        sort(tmpA.begin(), tmpA.end());
        for (int i = 0; i < B.size(); i++)
        {
            auto it = upper_bound(tmpA.begin(), tmpA.end(), B[i]);
            if (it == tmpA.end())
            {
                answer.push_back(tmpA[0]);
                tmpA.erase(tmpA.begin());
            }
            else
            {
                answer.push_back(*it);
                tmpA.erase(it);
            }
        }

        return answer;
    }
};