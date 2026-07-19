/*==================== TOPOLOGICAL SORT ====================*/

/*-------------------- Kahn's Algorithm (BFS) --------------------*/

vector<int> indeg(n+1,0);
for(int u=1;u<=n;u++){
    for(int v:g[u]) indeg[v]++;
}

queue<int> q;
for(int i=1;i<=n;i++){
    if(indeg[i]==0) q.push(i);
}

vector<int> topo;
while(!q.empty()){
    int u=q.front();
    q.pop();
    topo.push_back(u);
    for(int v:g[u]){
        indeg[v]--;
        if(indeg[v]==0) q.push(v);
    }
}
// if(topo.size()!=n) Cycle exists.

/*-------------------- Lexicographically Smallest --------------------*/

// Replace queue with priority_queue

priority_queue<int,vector<int>,greater<int>> pq;
for(int i=1;i<=n;i++){
    if(indeg[i]==0) pq.push(i);
}

vector<int> topo;
while(!pq.empty()){
    int u=pq.top();
    pq.pop();
    topo.push_back(u);
    for(int v:g[u]){
        indeg[v]--;
        if(indeg[v]==0) pq.push(v);
    }
}

/*-------------------- DFS Topological Sort --------------------*/

vector<int> topo;
vector<bool> vis(n+1);

void dfs(int u){
    vis[u]=1;
    for(int v:g[u]){
        if(!vis[v]) dfs(v);
    }
    topo.push_back(u);
}

/*
Usage

for(int i=1;i<=n;i++){
    if(!vis[i]) dfs(i);
}
reverse(topo.begin(),topo.end());
*/

/*-------------------- Longest Path in DAG --------------------*/

vector<int> dp(n+1,-INF);
dp[src]=0;
for(int u:topo){
    if(dp[u]==-INF) continue;
    for(int v:g[u]) dp[v]=max(dp[v],dp[u]+1);
}

/*-------------------- Count Paths in DAG --------------------*/

vector<ll> dp(n+1,0);
dp[src]=1;
for(int u:topo){
    for(int v:g[u]) dp[v]+=dp[u];
}

/*-------------------- Complexity --------------------*/

//Kahn      O(n+m)
//DFS Topo  O(n+m)