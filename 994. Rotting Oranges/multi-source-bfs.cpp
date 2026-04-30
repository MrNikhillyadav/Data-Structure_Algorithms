class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int freshOranges = 0;

        // Step 1: collect all sources
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }

        if(freshOranges == 0) return 0;  // all rotten oranges

        int minutes = 0;
        vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};

        // Step 2: BFS
        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto curr = q.front();
                q.pop();

                for(auto dir : directions){
                    int i_ = curr.first + dir[0];
                    int j_ = curr.second + dir[1];

                    // boundary condition
                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] == 1){
                        grid[i_][j_] = 2;
                        q.push({i_, j_});
                        freshOranges--;
                    }
                }
            }

            minutes++;
        }

        return freshOranges == 0 ? minutes - 1 : -1;
    }
};