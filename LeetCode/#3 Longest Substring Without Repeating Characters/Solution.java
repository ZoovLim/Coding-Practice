import java.util.HashSet;
import java.util.Set;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int answer = 0;
        int start = 0, end = 0, n = s.length();
        Set<Character> chars = new HashSet<>();

        while (start < n && end < n) {
            if (!chars.contains(s.charAt(end))) {
                chars.add(s.charAt(end++));
                answer = Math.max(answer, end - start);
            } else {
                chars.remove(s.charAt(start++));
            }
        }
        return answer;
    }
}