class Solution {
    public String countAndSay(int n) {
        String answer = "1";
        for (int i = 1; i < n; i++) {
            answer = func(answer);
        }
        return answer;
    }

    public String func(String n) {
        char digit = n.charAt(0);
        int count = 0;
        String answer = "";
        for (int i = 0; i < n.length(); i++) {
            if (digit == n.charAt(i)) {
                count++;
            } else {
                answer = answer + count + digit;
                digit = n.charAt(i);
                count = 1;
            }
        }
        return answer + count + digit;
    }
}