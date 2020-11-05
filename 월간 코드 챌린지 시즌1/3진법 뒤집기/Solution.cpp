#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n)
{
    int answer = 0;
    stack<int> s;

    while (n != 0)
    {
        s.push(n % 3);
        n /= 3;
    }

    int digit = 1;
    while (!s.empty())
    {
        int tmp = s.top();
        s.pop();
        answer += digit * tmp;
        digit *= 3;
    }

    return answer;
}