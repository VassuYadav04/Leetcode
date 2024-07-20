class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> matrix(size(rowSum), vector<int>(size(colSum)));
        for (int i = 0, j = 0; i < size(matrix) && j < size(matrix[0]);) {
            matrix[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= matrix[i][j];
            colSum[j] -= matrix[i][j];
            if (!rowSum[i]) {
                ++i;
            }
            if (!colSum[j]) {
                ++j;
            }
        }
        return matrix;
    }
};
