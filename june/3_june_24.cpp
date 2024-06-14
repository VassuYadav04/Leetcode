class Solution {
public:
    int appendCharacters (string s, string t) {
        int i=0;
        int j=0;
        int count=0;
        while (i<s.length()) {
            if(s[i]==t[j]) i++, j++;
            else i++;
        }
        while (j<t.length()) j++, count++;
        return count;
    }
};