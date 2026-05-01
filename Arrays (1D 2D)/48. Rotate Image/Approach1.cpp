class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> res(n, vector<int>(n));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                res[j][n - 1 - i] = matrix[i][j];
            }
        }

        matrix = res;
    }
};

/*
    First Principles (Very Important)

        For a 90° clockwise rotation:
            Element at position (i, j) → goes to (j, n - 1 - i)

        This is the core formula.
*/