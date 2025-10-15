class Solution {
    public boolean checkTwoChessboards(String coordinate1, String coordinate2) {
        
    char c1 = coordinate1.charAt(0);
    char r1 = coordinate1.charAt(1);
    char c2 = coordinate2.charAt(0);
     char r2 = coordinate2.charAt(1);
    return(c1-'a'+r1-'1')%2==(c2-'a'+r2-'1')%2;

    }
}