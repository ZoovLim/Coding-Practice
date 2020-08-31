class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";
        String prefix = new String(strs[0]);

        for (int i = 1; i < strs.length; i++) {
            int minLength = Math.min(prefix.length(), strs[i].length());
            prefix = prefix.substring(0, minLength);
            for (int j = 0; j < minLength; j++) {
                if (prefix.charAt(j) != strs[i].charAt(j)) {
                    prefix = prefix.substring(0, j);
                    break;
                }
            }
        }
        return prefix;
    }
}