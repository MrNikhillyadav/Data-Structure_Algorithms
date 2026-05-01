class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> result;
        map<int, vector<int>> mp; // map : keys are sorted, don't use unordered_map here 

        // step-1 : fill the map using [i+j] property
        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++){
                mp[i+j].push_back(mat[i][j]);  // using [i+j] property
            }
        }

        // step -2 traverse on map ;
        bool flip = true;

        for(auto &it : mp){
            if(flip){
                reverse(it.second.begin(), it.second.end());
            }

            for(int &nums : it.second){
                result.push_back(nums);
            }

            flip = !flip;
        }

        return result;
    }
};

/*
    ref : CodeStoryWithMik Array(1D-2D) Playlist

    Important property of Matrix to remember from his video:
        traverse upward   ----> i+j
        traverse downward ----> i-j
*/