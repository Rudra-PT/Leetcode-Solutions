class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0; 
        int writeIndex = 0;

        while (i < n) {
            int j = i; 
            while (j < n && chars[j] == chars[i]) {
                j++;
            }
            chars[writeIndex++] = chars[i];
            int count = j - i;
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[writeIndex++] = c;
                }
            }
            i = j; 
        }
        
        return writeIndex;
    }
};