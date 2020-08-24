#include <string>

using namespace std;

int solution(string s) {
    int answer = s.length();
    int l, r;

    for (int i = 1; i <= s.length() / 2; i++) {
        l = 0;
        for (int j = 0; j <= s.length() - 2 * i; j++) {
            int count = 1;
            string c;
            string tmp = s.substr(j, i);

            for (int k = j + i; k < s.length(); k += i) {
                if (tmp != s.substr(k, i)) {
                    break;
                }
                count++;
            }
            if (count == 1) l += i;
            else {
                c = to_string(count);
                l += i + c.length();
            }
            j += (count * i);
            r = j;
            j--;
        }
        l += s.length() - r;
        if (l < answer) {
            answer = l;
        }
    }
    return answer;
}