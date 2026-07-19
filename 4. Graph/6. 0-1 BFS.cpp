/*==================== 0-1 BFS ====================*/

const ll INF=4e18;
vector<ll> dist(n+1,INF);
deque<int> dq;
dist[src]=0;
dq.push_front(src);

while(!dq.empty()){
    int u=dq.front();
    dq.pop_front();

    for(auto [v,w]:g[u]){
        if(dist[v]>dist[u]+w){
            dist[v]=dist[u]+w;
            if(w==0) dq.push_front(v);
            else dq.push_back(v);
        }
    }
}
// Complexity O(n+m)