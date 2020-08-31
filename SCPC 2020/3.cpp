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
		
		// DP를 이용하기 위한 2차원 vector
		// M[i][j] : i -> j 에 도달하기 위한 솔루션
		vector<vector<int>> M(N + 1, vector<int>(N + 1, -1));		
		vector<vector<int>> tmp(2, vector<int>(N + 1, -1));	// 메모리 효율을 위해 매 시행에서 값이 변하는 솔루션을 구하기 위해 이전 시행의 솔루션을 담을 임시 벡터
		stack<pair<int, int>> connection;	// k개의 연결을 담을 stack
		stack<pair<int, int>> problem;		// m개의 문제를 담을 stack
		int a, b;	// 두 점의 값을 저장할 변수 

		for (int i = 0; i < k; i++) {	// Make connection stack
			cin >> a >> b;
			connection.push(make_pair(a, b));
		}
		for (int i = 0; i < m; i++) {	// Make problem stack
			cin >> a >> b;
			problem.push(make_pair(a, b));
		}

		// 첫 시행 초기화
		a = connection.top().first;
		b = connection.top().second;
		connection.pop();
		M[a][b] = 0;
		M[b][a] = 0;		
		for (int i = 1; i <= N; i++) {
			if (i == a || i == b) M[i][i] = 1;
			else M[i][i] = 0;
		}
		
		while (!connection.empty()) {	// 아래의 연결부터 문제의 솔루션을 찾아나간다.
			a = connection.top().first;
			b = connection.top().second;
			connection.pop();

			for (int i = 0; i < 2; i++) {	// 값이 변하는 문제들에 대해서 이전 시행의 솔루션을 따로 저장한다.
				int tmpIndex = (i == 0) ? a : b;
				for (int j = 1; j <= N; j++) {
					tmp[i][j] = M[tmpIndex][j];
				}
			}

			for (int i = 0; i < 2; i++) {
				int tmpIndex = (i == 0) ? a : b;
				for (int j = 1; j <= N; j++) {
					if (tmp[i][j] == -1) {	// 이번 시행의 연결을 제거해도 도달할 수 없는 경우
						M[tmpIndex][j] = tmp[(i + 1) % 2][j];
					}
					else if (tmp[(i + 1) % 2][j] == -1) {	// 이번 시행의 연결을 제거해야만 도달할 수 있는 경우
						M[tmpIndex][j] = 1 + tmp[i][j];
					}
					else {	// 나머지 경우
						M[tmpIndex][j] = min(tmp[(i + 1) % 2][j], 1 + tmp[i][j]);
					}
				}
			}
		}

		while (!problem.empty()) {	// 모든 문제의 솔루션 합 구하기
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