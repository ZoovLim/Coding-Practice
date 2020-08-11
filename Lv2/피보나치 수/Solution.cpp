int solution(int n) {
    int answer = 1;
    int nums[100001];

    nums[0] = 0;
    nums[1] = 1;

    for (int i = 2; i <= n; i++) {
        nums[i] = ((nums[i - 2] % 1234567) + (nums[i - 1] % 1234567)) % 1234567;
    }

    answer = nums[n];

    return answer;
}