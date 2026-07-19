/*==================== CYCLE DETECTION ====================*/

/*-------------------- Undirected Graph --------------------*/

bool dfs(int u,int p){
    vis[u]=1;
    for(int v:g[u]){
        if(v==p) continue;
        if(vis[v]) return true;
        if(dfs(v,u)) return true;
    }
    return false;
}
/*
bool ok=false;
for(int i=1;i<=n;i++){
    if(vis[i]) continue;
    if(dfs(i,-1)){
        ok=true;
        break;
    }
}
*/

/*-------------------- Directed Graph --------------------*/

// color
// 0 = unvisited
// 1 = visiting
// 2 = finished

bool dfs(int u){
    color[u]=1;
    for(int v:g[u]){
        if(color[v]==1) return true;
        if(color[v]==0 && dfs(v)) return true;
    }
    color[u]=2;
    return false;
}

/*
Usage

bool ok=false;
for(int i=1;i<=n;i++){
    if(color[i]) continue;
    if(dfs(i)){
        ok=true;
        break;
    }
}
*/

/*-------------------- Restore Cycle (Undirected) --------------------*/

vector<int> par;
int st=-1,en=-1;
bool dfs(int u,int p){
    vis[u]=1;
    for(int v:g[u]){
        if(v==p) continue;
        if(vis[v]){
            st=v;
            en=u;
            return true;
        }
        par[v]=u;
        if(dfs(v,u)) return true;
    }
    return false;
}

/*
Restore

vector<int> cycle;
cycle.push_back(st);
for(int v=en;v!=st;v=par[v]) cycle.push_back(v);
cycle.push_back(st);
reverse(cycle.begin(),cycle.end());
*/

/*-------------------- Restore Cycle (Directed) --------------------*/

vector<int> par;
int st=-1,en=-1;
bool dfs(int u){
    color[u]=1;
    for(int v:g[u]){
        if(color[v]==0){
            par[v]=u;
            if(dfs(v)) return true;
        }
        else if(color[v]==1){
            st=v;
            en=u;
            return true;
        }
    }
    color[u]=2;
    return false;
}

/*
Restore

vector<int> cycle;
cycle.push_back(st);
for(int v=en;v!=st;v=par[v]) cycle.push_back(v);
cycle.push_back(st);
reverse(cycle.begin(),cycle.end());
*/

/*-------------------- Complexity --------------------*/

// O(n+m)