/*==================== DISJOINT SET UNION (DSU) ====================*/

/*-------------------- Initialization --------------------*/

vector<int> par(n+1), sz(n+1,1);
void init(){
    for(int i=1;i<=n;i++) par[i]=i;
}

/*-------------------- Find Parent --------------------*/

// Path Compression
int find(int v){
    if(par[v]==v) return v;
    return par[v]=find(par[v]);
}

/*-------------------- Union by Size --------------------*/

bool unite(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b) return false;
    if(sz[a]<sz[b]) swap(a,b);
    par[b]=a;
    sz[a]+=sz[b];
    return true;
}

/*-------------------- Same Component --------------------*/

bool same(int a,int b){
    return find(a)==find(b);
}

/*-------------------- Component Size --------------------*/

int size(int v){
    return sz[find(v)];
}

/*-------------------- Number of Components --------------------*/

int comp=n;
if(unite(u,v)) comp--;

/*-------------------- Complexity --------------------*/

// Find
// O(α(n))
// Union
// O(α(n))
// (Practically O(1))