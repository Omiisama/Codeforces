/*==================== GRAPH BASICS ====================*/
/*-------------------- Unweighted Graph --------------------*/

int n,m;
cin>>n>>m;
vector<vector<int>> g(n+1);
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);      // Remove for directed graph
}
//degree[u]=g[u].size();

/*-------------------- Weighted Graph --------------------*/

vector<vector<pair<int,int>>> g(n+1);
for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    g[u].push_back({v,w});
    g[v].push_back({u,w});
}

/*-------------------- DFS --------------------*/

vector<bool> vis(n+1,false);
void dfs(int u){
    vis[u]=true;
    for(int v:g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

/*-------------------- DFS with Parent --------------------*/

void dfs(int u,int p){
    for(int v:g[u]){
        if(v==p) continue;
        dfs(v,u);
    }
}

/*-------------------- BFS --------------------*/

vector<int> dist(n+1,-1);
vector<int> par(n+1,-1);
queue<int> q;
dist[src]=0;
q.push(src);
// for(int s:sources){
//     dist[s]=0;
//     q.push(s);
// }

while(!q.empty()){
    int u=q.front();
    q.pop();
    for(int v:g[u]){
        if(dist[v]!=-1) continue;
        dist[v]=dist[u]+1;
        par[v]=u;
        q.push(v);
    }
}

/*-------------------- Connected Components --------------------*/

int cc=0;
for(int i=1;i<=n;i++){
    if(vis[i]) continue;
    cc++;
    dfs(i);
}

/*-------------------- Restore Path --------------------*/

vector<int> path;
for(int v=dest;v!=-1;v=par[v]) path.push_back(v);
reverse(path.begin(),path.end());

/*-------------------- Complexity --------------------*/

//Adjacency List
//Space : O(n+m)
//DFS : O(n+m)
//BFS : O(n+m)