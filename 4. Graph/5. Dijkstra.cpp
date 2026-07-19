/*==================== DIJKSTRA ====================*/

//Graph
vector<vector<pair<int,int>>> g(n+1);
// g[u] contains {v, weight}

/*-------------------- Dijkstra --------------------*/

const ll INF=4e18;
vector<ll> dist(n+1,INF);
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
dist[src]=0;
pq.push({0,src});

while(!pq.empty()){
    auto [d,u]=pq.top();
    pq.pop();

    if(d!=dist[u]) continue;
    for(auto [v,w]:g[u]){
        if(dist[v]>dist[u]+w){
            dist[v]=dist[u]+w;
            pq.push({dist[v],v});
        }
    }
}

/*-------------------- Complexity --------------------*/

O((n+m)log n)