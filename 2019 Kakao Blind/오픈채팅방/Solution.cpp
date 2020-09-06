#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    queue<pair<char, string>> actionQ;
    unordered_map<string, string> users;

    for (auto r : record) {
        int firstSpace = r.find(' ');
        int secondSpace = r.find(' ', firstSpace + 1);
        string id = r.substr(firstSpace + 1, secondSpace - firstSpace - 1);
        string nickName = r.substr(secondSpace + 1);

        if (r[0] != 'L') users[id] = nickName;
        if (r[0] == 'C') continue;       
        actionQ.push(make_pair(r[0], id));
    }

    while (!actionQ.empty()){
        string message = "";   
        string nickName = users.find(actionQ.front().second)->second;
        message += nickName;
        message += "님이 ";

        if (actionQ.front().first == 'E') message += "들어왔습니다.";
        else message += "나갔습니다.";
        answer.push_back(message);
        actionQ.pop();
    }

    return answer;
}
