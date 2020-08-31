#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman;
        int answer = 0;
        int count = 0;

        roman.insert(make_pair('I', 1));
        roman.insert(make_pair('V', 5));
        roman.insert(make_pair('X', 10));
        roman.insert(make_pair('L', 50));
        roman.insert(make_pair('C', 100));
        roman.insert(make_pair('D', 500));
        roman.insert(make_pair('M', 1000));

        count++;
        for (int i = 1; i < s.size(); i++) {
            if (roman.find(s[i - 1])->second < roman.find(s[i])->second) {
                answer += roman.find(s[i])->second - roman.find(s[i - 1])->second;
                count = 0;
            }
            else if (s[i - 1] == s[i]) count++;
            else {
                answer += count * roman.find(s[i - 1])->second;
                count = 1;
            }
        }
        answer += count * roman.find(s[s.size() - 1])->second;

        return answer;
    }
};