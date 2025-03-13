/*
    Code by: KoKoDuDu
*/
class Solution {
    public boolean isPalindrome(int x) {
        StringBuilder sb = new StringBuilder(Integer.toString(x));
        String s = sb.toString();
        String t = sb.reverse().toString();
        return s.equals(t);
    }
}