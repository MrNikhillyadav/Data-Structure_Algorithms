class Solution {
public:

    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;

        for(int neighbor : adj[node]){
            if(neighbor == parent) continue;

            if(visited[neighbor]) return true;

            if(dfs(neighbor, node, adj, visited)){
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        
        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: DFS
        vector<bool> visited(V, false);

        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(dfs(i, -1, adj, visited)){
                    return true;
                }
            }
        }

        return false;
    }
};

/*
    Golden Rule:
    
    🔥 Always Identify Input Type FIRST

      Before coding, ask: What is given?”
            
            Input Type	           What to do
           ----------------    ----------------- 
            Adjacency list	 -      Direct DFS
            Edge list	     -      Build graph first
            Grid	         -     Use directions

        DFS/BFS NEVER runs directly on edge list
        You MUST convert it
        
    
    Undirected:
    
        “Did I come back to a node via a different path?”
    
    
*/