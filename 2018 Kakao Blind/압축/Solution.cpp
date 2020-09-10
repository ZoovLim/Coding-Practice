#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dictionary;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int index;

    for (index = 1; index <= 26; index++) {        
        dictionary[alphabet.substr(index - 1, 1)] = index;        
    }

    while (msg.size() != 0) {
        int findIndex = -1;
        for (int i = 1; i <= msg.size(); i++) {
            auto it = dictionary.find(msg.substr(0, i));
            if (it == dictionary.end()) {             
                answer.push_back(findIndex);
                dictionary[msg.substr(0, i)] = index++;
                msg = msg.erase(0, i - 1);
                
                break;   
            }
            else {               
                findIndex = it->second;
                if (i == msg.size()) {
                    answer.push_back(findIndex);
                    msg = "";
                }
            }
        }        
    }

    return answer;
}