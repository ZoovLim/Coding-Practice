/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
#include <stack>
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

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////
		
		// Variables in the problem
		int N, k, m;
		cin >> N >> k >> m;		
		
		// DP�� �̿��ϱ� ���� 2���� vector
		// M[i][j] : i -> j �� �����ϱ� ���� �ַ��
		vector<vector<int>> M(N + 1, vector<int>(N + 1, -1));		
		vector<vector<int>> tmp(2, vector<int>(N + 1, -1));	// �޸� ȿ���� ���� �� ���࿡�� ���� ���ϴ� �ַ���� ���ϱ� ���� ���� ������ �ַ���� ���� �ӽ� ����
		stack<pair<int, int>> connection;	// k���� ������ ���� stack
		stack<pair<int, int>> problem;		// m���� ������ ���� stack
		int a, b;	// �� ���� ���� ������ ���� 

		for (int i = 0; i < k; i++) {	// Make connection stack
			cin >> a >> b;
			connection.push(make_pair(a, b));
		}
		for (int i = 0; i < m; i++) {	// Make problem stack
			cin >> a >> b;
			problem.push(make_pair(a, b));
		}

		// ù ���� �ʱ�ȭ
		a = connection.top().first;
		b = connection.top().second;
		connection.pop();
		M[a][b] = 0;
		M[b][a] = 0;		
		for (int i = 1; i <= N; i++) {
			if (i == a || i == b) M[i][i] = 1;
			else M[i][i] = 0;
		}
		
		while (!connection.empty()) {	// �Ʒ��� ������� ������ �ַ���� ã�Ƴ�����.
			a = connection.top().first;
			b = connection.top().second;
			connection.pop();

			for (int i = 0; i < 2; i++) {	// ���� ���ϴ� �����鿡 ���ؼ� ���� ������ �ַ���� ���� �����Ѵ�.
				int tmpIndex = (i == 0) ? a : b;
				for (int j = 1; j <= N; j++) {
					tmp[i][j] = M[tmpIndex][j];
				}
			}

			for (int i = 0; i < 2; i++) {
				int tmpIndex = (i == 0) ? a : b;
				for (int j = 1; j <= N; j++) {
					if (tmp[i][j] == -1) {	// �̹� ������ ������ �����ص� ������ �� ���� ���
						M[tmpIndex][j] = tmp[(i + 1) % 2][j];
					}
					else if (tmp[(i + 1) % 2][j] == -1) {	// �̹� ������ ������ �����ؾ߸� ������ �� �ִ� ���
						M[tmpIndex][j] = 1 + tmp[i][j];
					}
					else {	// ������ ���
						M[tmpIndex][j] = min(tmp[(i + 1) % 2][j], 1 + tmp[i][j]);
					}
				}
			}
		}

		while (!problem.empty()) {	// ��� ������ �ַ�� �� ���ϱ�
			int start, end;
			start = problem.top().first;
			end = problem.top().second;
			problem.pop();			
			Answer += M[start][end];
		}

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}