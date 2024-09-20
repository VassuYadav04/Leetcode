class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) {
            return s;
        }
        string rev_s(s.crbegin(), s.crend());
        string A = s + '#' + rev_s;
        auto prefix = getPrefix(A);
        string non_palindrome = s.substr(prefix.back() + 1);
        reverse(non_palindrome.begin(), non_palindrome.end());
        return non_palindrome + s;
    }
        
private:
    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i) {
            while (j > -1 && pattern[j + 1] != pattern[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }
};