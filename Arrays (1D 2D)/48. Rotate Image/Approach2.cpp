class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // step-1 transpose
        for(int i=0; i < n; i++){
            for(int j=i; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // step-2 reverse all the rows
        for(int i=0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
// Space: O(1)  No extra space

/*  
    Approach2: In-place (transpose + reverse)

    refer : CodeStoryWithMik
*/