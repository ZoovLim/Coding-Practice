int gcd(int a, int b) {
    int r;

    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

long long solution(int w, int h) {
    long long answer = 0;   
    long long g = gcd(w, h);
    long long minw = w / g;
    long long minh = h / g;

    answer = (long long) w * h - g * (minw + minh - 1);

    return answer;
}