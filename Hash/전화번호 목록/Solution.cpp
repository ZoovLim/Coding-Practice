#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    // 오름차순으로 전화번호부 정렬, i + 1번째 문자열의 접두어가 i번째 문자열이 아니라면, i + 2번째 문자열부터는 볼 필요가 없다.
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++) {        
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())) return false;
    }

    return answer;
}