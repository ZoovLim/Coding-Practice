#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_multiset<string> completionHash;

    for (string c : completion) {
        completionHash.insert(c);
    }    

    for (string p : participant) {
        if (completionHash.find(p) == completionHash.end()) return p;
        else completionHash.erase(completionHash.find(p));
    }

    return answer;
}