#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    // ������������ ��ȭ��ȣ�� ����, i + 1��° ���ڿ��� ���ξ i��° ���ڿ��� �ƴ϶��, i + 2��° ���ڿ����ʹ� �� �ʿ䰡 ����.
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++) {        
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())) return false;
    }

    return answer;
}