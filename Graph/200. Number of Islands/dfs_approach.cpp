class Solution {
public:
    void dfs(vector<vector<char>>& grid, int n, int m, int i, int j){

        // bound conditons
        if(i < 0 || i >= n || j < 0 || j >= m ){
            return;
        }

        if(grid[i][j] == '0'){  
            return;
        }

        if(grid[i][j] == '$'){   // if already visited, then return
            return;
        }

        grid[i][j] = '$';

        // for all 4 directions:
        dfs(grid, n, m, i+1, j);
        dfs(grid, n, m, i-1, j);
        dfs(grid, n, m, i, j+1);
        dfs(grid, n, m, i, j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int islands = 0;

        for(int i=0; i < n; i++){
            for(int j=0; j< m; j++){

                if(grid[i][j] == '1'){
                    dfs(grid, n, m, i, j);
                    islands++;
                }
            }
        }

        return islands;
    }
};

/*
    Approach 1 - DFS on Graph, TC: O(m*n)

    void dfs(i, j):
        - if out of bounds OR invalid:
            return
        
        - mark visited
        
        - for all 4 directions:
            dfs(new_i, new_j)


    Main loop 

        for each cell:
           - if unvisited land:
                run dfs
                count++
*/