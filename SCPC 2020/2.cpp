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
		// Answer : 필승상태 경우의 수
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
		// winCase[i][j] : X와 Y에 각각 i, j장이 있을때, true면 필승전략 존재, false면 패배할 수 밖에 없는 상황.		
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
		
		// 경계조건 초기화
		winCase[0][0] = true;
		Answer++;
		
		for (int i = 1; i <= 2 * n; i++) {	// X 와 Y 카드 장 수의 합이 1에서부터 2n까지 탐색
			int limit = min(i, n);	// 한 쪽에 존재 가능한 카드수 제한
			for (int j = limit; j >= i - limit; j--) {	// 두 더미의 장 수 합이 j일때, 가능한 모든 조합에 대해 탐색
				if (winCase[j][i - j]) {	// 해당 상태가 필승전략이 존재하는 경우 Answer 증가하며, 다음 탐색으로 넘어간다.
					Answer++;
					continue;
				}
				else {	// 해당 상태가 패배할 수 밖에 없는 상황이라면, 카드를 반대로 쌓아가며 필승전략이 존재하는 경우를 찾아낸다.
					int index = j + 1;	// 카드를 쌓을 X의 순번					
					if (index <= n) {	// 다 쌓인 경우 Skip
						int total = X[index - 1];	// 쌓아가는 카드 값 초기화
						while (total <= k) {	// X에 카드를 쌓아가는 과정					
							winCase[index][i - j] = true;
							index++;
							if (index > n) break;
							total += X[index - 1];
						}
					}
					index = i - j + 1;	// 카드를 쌓을 Y의 순번
					if (index > n) continue;	// 다 쌓인 경우 Skip
					int total = Y[index - 1];	// 카드 값 초기화
					while (total <= k) {	// Y에 카드를 쌓아가는 과정
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