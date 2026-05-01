class Solution {
public:
    void dfsTraversal(vector<vector<int>>& adj, int curr_node, vector<int>& res, vector<bool>& visited) {
        
        visited[curr_node] = true;   // mark first
        res.push_back(curr_node);    // then add
        
        for(int i = 0; i < adj[curr_node].size(); i++) {
            int neighbor = adj[curr_node][i];
            
            if(!visited[neighbor]) {
                dfsTraversal(adj, neighbor, res, visited);  // go to neighbor
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> res;
        vector<bool> visited(n, false);
        
        dfsTraversal(adj, 0, res, visited);
        
        return res;
    }
};

/*
    Intuition 
    
        Think DFS like:
            “I go to a node → mark it → then dive deeper”
            
        DFS (Depth First Search)

            “Go as deep as possible, then backtrack”
                
               - Uses recursion / stack
               - Explores one path fully
               
*/