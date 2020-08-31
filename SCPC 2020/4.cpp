/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;

// ���� ���� ���� �ִ밪 ���ϴ� �Լ�
int findMaxCount(int n, string t, int k, int m);

// string -> int function
int sToi(string str);

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
		int n, k, m;
		string t;

		cin >> n >> k >> m;
		cin >> t;

		Answer = findMaxCount(n, t, k, m);
		
		for (int i = 0; i < n; i++) {
			if (t[i] == '1') continue;
			else {
				string tmp = t;
				tmp[i] = '1';
				int count = findMaxCount(n, tmp, k, m);
				Answer = count > Answer ? count : Answer;
			}
		}

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}

int findMaxCount(int n, string t, int k, int m) {
	int maxCount = 1;
	vector<int> nums;

	for (int i = 0; i <= n - k; i++) {	// ���ڵ� �����
		nums.push_back(sToi(t.substr(i, k)));
	}

	// ������� ���ڵ� �������� ����
	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size(); i++) {	// �ε����� ���󰡸� Ž��
		while ((i + maxCount < nums.size()) && (nums[i + maxCount] <= nums[i] + m)) {	// �ش� ������ maxCount�� �Ѵ� ���ڰ� ������ �� �ִ��� üũ�ϴ� ����
			maxCount++;
		}
	}

	return maxCount;
}

int sToi(string str) {
	int result = 0;

	for (int i = 0; i < str.size(); i++) {
		result *= 10;
		result += str[i] - '0';
	}

	return result;
}