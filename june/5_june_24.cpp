class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int check[26] = {0};
        vector<string> count;
        for (int i=0; i<words[0].length(0); i++){
            check[(int)words[0][i]-97]++;
        }
        for (int i=0; i<words.size(); i++) {
            int check2[26] = {0};
            for (int j=0; j<words[i].length(); j++) {
                check2[(int)words[i][j]-97]++;
            }
            for (int k=0; k<26; k++) {
                if(check[k]>check2[k]) check[k] = check2[k];
            }
        }
        for (int i=0; i<26; i++) {
            for (int j=0; j<check[i]; j++) {
                string s = "";
                s = s+(char)(i+97);
                count.push_back(s);
            }
        }
        return count;
    }
};