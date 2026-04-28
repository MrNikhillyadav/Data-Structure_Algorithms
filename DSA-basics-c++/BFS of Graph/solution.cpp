class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int> res;
        vector<bool> visited(n, false);
        
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            int curr_node = q.front();
            q.pop();
            res.push_back(curr_node);
            
            for(int i=0; i < adj[curr_node].size(); i++){ // 0 -> [2,3,1]
                int neigh = adj[curr_node][i];
                
                if(visited[neigh] == false){
                    q.push(neigh);
                    visited[neigh] = true;
                }
            }
        }
        
        return res;
    }
};

/*
    Time : O(n) Space: O(n)
    
    BFS (Breadth First Search)

        “Explore level by level”
            - Uses queue
            - Expands in layers
*/