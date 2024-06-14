class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector <int> res(heights.begin(), heights.end());
        sort(res.begin(), res.end());
        int count = 0;
        for (int i=0; i<heights.size(); i++) {
            if (res[i] != heights[i]) count++;
        }
        return count;
    }
};