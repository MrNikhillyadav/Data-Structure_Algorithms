class Solution {
public:
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};

    void bfs(vector<vector<char>>& grid, int n, int m, int i, int j){

        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = '$';

        while(!q.empty()){
            auto coordinate = q.front();
            q.pop();

            for(auto &dir : directions ){
                int x_ = coordinate.first + dir[0];
                int y_ = coordinate.second + dir[1];

                if( x_ < 0 || x_ >= n || y_ < 0 || y_ >= m || grid[x_][y_] != '1'){ // or grid[x_][y_] == '0' || grid[x_][y_] == '$'
                    continue;
                }else{
                    q.push({x_,y_});
                    grid[x_][y_] = '$';
                }
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j < m; j++){
                if(grid[i][j] == '1'){
                  bfs(grid, n, m, i, j);
                  islands++;
                }
            }
        }
       
        return islands;
    }
};

/*
    Approach 2 - BFS on Graph, TC: O(m*n)   
*/