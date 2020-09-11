#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
	int answer = 0;

	// ���� ���� Ƚ��
	for (int i = 0; i < name.size(); i++) {
		answer += min(name[i] - 'A', 'Z' - name[i] + 1);
	}

	// �¿� ���� Ƚ��
	int horizontal = 0;
	int firstNotA = 1;
	int lastNotA = 0;
	bool findFirstNotA = false;

	for (int i = 1; i < name.size(); i++) {
		if (name[i] == 'A' && !findFirstNotA) firstNotA++;
		else {
			lastNotA = i;
			findFirstNotA = true;
		}
	}

	// ���� ��ȯ ���� ���� ����� �ּ� ���� Ƚ��
	horizontal = min(lastNotA, (int) name.size() - firstNotA);

	int againAStart, againAEnd;
	bool findAGroup = false;
	// ���� ��ȯ�� �ϴ� ���
	if(firstNotA == 1) {
		for (int i = firstNotA + 1; i < name.size(); i++) {
			if (!findAGroup) {
				if (name[i] == 'A') {
					findAGroup = true;
					againAStart = i;
					againAEnd = i;
				}
			}
			else if (name[i] == 'A') againAEnd = i;
			else break;
		}
		if(findAGroup) horizontal = min(horizontal, ((againAStart - 1) * 2 + ((int) name.size() - againAEnd - 1)));
	}

	if (firstNotA == 1) {
		int start = -1, max = 0, count = 0;
		for (int i = firstNotA + 1; i < name.size(); i++) {
			if (name[i] == 'A') {
				count++;
				if (count > max) {
					max = count;
					start = i - count + 1;
				}
			}
			else count = 0;
		}
		int end = start + max - 1;
		if (start != -1) horizontal = min(horizontal, 2 * (start - 1) + ((int) name.size() - end - 1));
	}
	answer += horizontal;

	return answer;
}