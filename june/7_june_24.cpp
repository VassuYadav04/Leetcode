class Solution {
public:
    string replaceWords(vector<string>& dict, string sent) {
        set<string>s;
        for (auto i : dict)s.insert(i);
        string ans="";
        sent.push_back(' ');
        string temp="";
        for (int i=0; i<(int)sent.size(); i++) {
            if(sent[i]==' ') {
                ans += temp;
                ans += (char)(' ');
                temp = "";
            }
            else {
                temp += (char)sent[i];
                if (s.count(temp)){
                    ans += temp;
                    ans += char(' ');
                    temp = "";
                    while(sent[i]!=' ') i++;
                }
            }
        }
        ans.pop_back();
        return ans;
    }
};