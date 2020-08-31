import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
        Stack<Character> open = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ')') {
                if (open.empty() || open.pop() != '(') return false;
            } else if (s.charAt(i) == '}') {
                if (open.empty() || open.pop() != '{') return false;
            } else if (s.charAt(i) == ']') {
                if (open.empty() || open.pop() != '[') return false;
            } else open.push(s.charAt(i));
        }
        return open.empty();
    }
}