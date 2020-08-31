/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		// Answer : �ʽ»��� ����� ��
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////
		
		// Variables in the problem
		int n, k;
		vector<int> X, Y;
		cin >> n >> k;
		// winCase[i][j] : X�� Y�� ���� i, j���� ������, true�� �ʽ����� ����, false�� �й��� �� �ۿ� ���� ��Ȳ.		
		vector<vector<bool>> winCase(n + 1, vector<bool>(n + 1, false));
		for (int i = 0; i < n; i++) {	// Make X cards
			int tmp;
			cin >> tmp;
			X.push_back(tmp);
		}
		for (int i = 0; i < n; i++) {	// Make Y cards
			int tmp;
			cin >> tmp;
			Y.push_back(tmp);
		}
		
		// ������� �ʱ�ȭ
		winCase[0][0] = true;
		Answer++;
		
		for (int i = 1; i <= 2 * n; i++) {	// X �� Y ī�� �� ���� ���� 1�������� 2n���� Ž��
			int limit = min(i, n);	// �� �ʿ� ���� ������ ī��� ����
			for (int j = limit; j >= i - limit; j--) {	// �� ������ �� �� ���� j�϶�, ������ ��� ���տ� ���� Ž��
				if (winCase[j][i - j]) {	// �ش� ���°� �ʽ������� �����ϴ� ��� Answer �����ϸ�, ���� Ž������ �Ѿ��.
					Answer++;
					continue;
				}
				else {	// �ش� ���°� �й��� �� �ۿ� ���� ��Ȳ�̶��, ī�带 �ݴ�� �׾ư��� �ʽ������� �����ϴ� ��츦 ã�Ƴ���.
					int index = j + 1;	// ī�带 ���� X�� ����					
					if (index <= n) {	// �� ���� ��� Skip
						int total = X[index - 1];	// �׾ư��� ī�� �� �ʱ�ȭ
						while (total <= k) {	// X�� ī�带 �׾ư��� ����					
							winCase[index][i - j] = true;
							index++;
							if (index > n) break;
							total += X[index - 1];
						}
					}
					index = i - j + 1;	// ī�带 ���� Y�� ����
					if (index > n) continue;	// �� ���� ��� Skip
					int total = Y[index - 1];	// ī�� �� �ʱ�ȭ
					while (total <= k) {	// Y�� ī�带 �׾ư��� ����
						winCase[j][index] = true;
						index++;
						if (index > n) break;
						total += Y[index - 1];
					}
				}
			}
		}

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << ' ' << (n + 1) * (n + 1) - Answer <<endl;
	}

	return 0;//Your program should return 0 on normal termination.
}