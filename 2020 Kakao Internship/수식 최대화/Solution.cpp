#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long calc(queue<long long> operands, queue<char> op, vector<char> priority) {
    queue<long long> operQ = operands;
    queue<char> opQ = op;
    for (int i = 0; i < priority.size(); i++) {
        queue<long long> tmpOperQ;
        queue<char> tmpOpQ;
        while (!operQ.empty()) {   
            if (opQ.empty()) {
                tmpOperQ.push(operQ.front());
                operQ.pop();
                break;
            }
            char curOp = opQ.front();
            opQ.pop();
            if (curOp == priority[i]) {
                long long first = operQ.front();
                operQ.pop();
                long long second = operQ.front();           
                switch (curOp)
                {
                case '+':
                    operQ.front() = first + second;
                    break;
                case '-':
                    operQ.front() = first - second;
                    break;
                case '*':
                    operQ.front() = first * second;
                    break;
                }             
            }
            else {
                tmpOpQ.push(curOp);
                tmpOperQ.push(operQ.front());
                operQ.pop();
            }        
        }
        opQ = tmpOpQ;
        operQ = tmpOperQ;
    }
    return abs(operQ.front());
}

long long solution(string expression) {
    long long answer = 0;
    queue<long long> operands;
    queue<char> op;
    string tmp = "";
    vector<vector<char>> priorityV;

    priorityV.push_back({ '+','-','*' });
    priorityV.push_back({ '+','*','-' });
    priorityV.push_back({ '-','+','*' });
    priorityV.push_back({ '-','*','+' });
    priorityV.push_back({ '*','+','-' });
    priorityV.push_back({ '*','-','+' });
    
    for (auto c : expression) {
        if (isdigit(c)) tmp += c;
        else {
            operands.push(stoll(tmp));
            op.push(c);
            tmp = "";
        }
    }
    operands.push(stoll(tmp));

    for (int i = 0; i < 6; i++) {       
        answer = max(answer, calc(operands, op, priorityV[i]));
    }
    
    return answer;
}