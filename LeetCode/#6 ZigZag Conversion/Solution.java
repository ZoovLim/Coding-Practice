class Solution {
    public String convert(String s, int numRows) {
        if (s.length() <= numRows || numRows == 1) return s;
        StringBuilder answer = new StringBuilder();

        int cycle = 2 * (numRows - 1);
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; i + j < s.length(); j += cycle) {
                answer.append(s.charAt(j + i));
                if (i != 0 && i != numRows - 1 && j + cycle - i < s.length()) {
                    answer.append(s.charAt(j + cycle - i));
                }
            }
        }
        return answer.toString();
    }
}