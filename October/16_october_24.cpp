class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> choices = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        string result;
        for (int i = 0; i < a + b + c; ++i) {
            sort(begin(choices), end(choices), greater<pair<int, int>>());
            bool is_found = false;
            for (auto& kvp :choices) {
                if (kvp.first &&
                    (result.length() < 2 ||
                     result[result.length() - 2] != kvp.second ||
                     result[result.length() - 1] != kvp.second)) {
                    result.push_back(kvp.second);
                    --kvp.first;
                    is_found = true;
                    break;
                }
            }
            if (!is_found) {
                break;
            }
        }
        return result;
    }
};