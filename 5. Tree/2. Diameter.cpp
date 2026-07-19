/*==================== TREE DIAMETER ====================*/

/*-------------------- Method 1 : Two DFS/BFS --------------------*/

// Diameter = Longest path between any two nodes
vector<vector<int>> g(n+1);
vector<int> dist(n+1);
void dfs(int u,int p){
    for(int v:g[u]){
        if(v==p) continue;
        dist[v]=dist[u]+1;
        dfs(v,u);
    }
}
/*
Step 1
dist.assign(n+1,0);
dfs(1,0);
Find farthest node A.
*/

/*
Step 2
dist.assign(n+1,0);
dfs(A,0);
The maximum distance now is the diameter.
The farthest node from A is B.
*/

/*-------------------- Restore Diameter Path --------------------*/

vector<int> par(n+1);
void dfs(int u,int p){
    par[u]=p;
    for(int v:g[u]){
        if(v==p) continue;
        dist[v]=dist[u]+1;
        dfs(v,u);
    }
}
/*
Run DFS from A.
Suppose farthest node is B.
Restore path:

vector<int> path;
for(int v=B;v!=0;v=par[v]) path.push_back(v);
reverse(path.begin(),path.end());
*/

/*-------------------- Method 2 : DP --------------------*/

// Height DP
int diameter=0;
int dfs(int u,int p){
    int mx1=0,mx2=0;
    for(int v:g[u]){
        if(v==p) continue;
        int h=dfs(v,u)+1;
        if(h>mx1){
            mx2=mx1;
            mx1=h;
        }
        else if(h>mx2){
            mx2=h;
        }
    }
    diameter=max(diameter,mx1+mx2);
    return mx1;
}

/*
Call
dfs(root,0);
diameter contains answer.
*/

/*-------------------- Complexity --------------------*/

// Two DFS/BFS
// O(n)
// DP
// O(n)