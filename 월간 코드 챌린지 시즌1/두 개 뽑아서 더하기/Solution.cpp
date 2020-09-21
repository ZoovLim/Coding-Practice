#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> n;
    
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            n.insert(numbers[i] + numbers[j]);
        }
    }
    
    for (auto i : n) answer.push_back(i);

    return answer;
}