/*==================== TREES ====================*/

/*-------------------- Tree DFS --------------------*/

vector<vector<int>> g(n+1);
void dfs(int u,int p){
    for(int v:g[u]){
        if(v==p) continue;
        dfs(v,u);
    }
}

/*-------------------- Depth of Every Node --------------------*/

vector<int> depth(n+1);
void dfs(int u,int p){
    for(int v:g[u]){
        if(v==p) continue;
        depth[v]=depth[u]+1;
        dfs(v,u);
    }
}
// depth[root]=0;
// dfs(root,0);

/*-------------------- Parent Array --------------------*/

vector<int> par(n+1);
void dfs(int u,int p){
    par[u]=p;
    for(int v:g[u]){
        if(v==p) continue;
        dfs(v,u);
    }
}
// par[root]=0;
// dfs(root,0);

/*-------------------- Subtree Size --------------------*/

vector<int> sz(n+1);
void dfs(int u,int p){
    sz[u]=1;
    for(int v:g[u]){
        if(v==p) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
// sz[u] = number of nodes in subtree of u

/*-------------------- Euler Tour (Entry/Exit Time) --------------------*/

int timer=0;
vector<int> tin(n+1),tout(n+1);
void dfs(int u,int p){
    tin[u]=++timer;
    for(int v:g[u]){
        if(v==p) continue;
        dfs(v,u);
    }
    tout[u]=timer;
}

/*-------------------- Ancestor Check --------------------*/
// u is ancestor of v iff
bool ancestor(int u,int v){
    return tin[u]<=tin[v] && tout[v]<=tout[u];
}

/*-------------------- Distance from Root --------------------*/

// Same as depth in an unweighted tree
vector<int> dist(n+1);
void dfs(int u,int p){
    for(int v:g[u]){
        if(v==p) continue;
        dist[v]=dist[u]+1;
        dfs(v,u);
    }
}

/*-------------------- Leaf Node --------------------*/

// u != root
bool leaf(int u,int p){
    return (u!=1 && g[u].size()==1);
}

/*-------------------- Rooted Tree Children --------------------*/

vector<vector<int>> child(n+1);
void dfs(int u,int p){
    for(int v:g[u]){
        if(v==p) continue;
        child[u].push_back(v);
        dfs(v,u);
    }
}

/*-------------------- Complexity --------------------*/

// DFS               O(n)
// Depth             O(n)
// Parent            O(n)
// Subtree Size      O(n)
// Euler Tour        O(n)