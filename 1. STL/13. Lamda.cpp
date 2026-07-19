/*==================== LAMBDAS ====================*/

// Syntax

[](){};

[](int x){
    return x*x;
};

[](int a,int b){
    return a<b;
};

/*-------------------- Capture --------------------*/

// Capture nothing

[](){};

// Capture everything by value

[=](){};

// Capture everything by reference

[&](){};

// Capture specific variable

[x](){};

[&x](){};

[x,&y](){};

/*-------------------- sort() --------------------*/

// Ascending

sort(v.begin(),v.end(),[](int a,int b){
    return a<b;
});

// Descending

sort(v.begin(),v.end(),[](int a,int b){
    return a>b;
});

// Pair

sort(v.begin(),v.end(),[](auto &a,auto &b){
    if(a.first!=b.first)
        return a.first<b.first;
    return a.second>b.second;
});

/*-------------------- Priority Queue --------------------*/

auto cmp=[](int a,int b){
    return a>b;
};

priority_queue<int,
vector<int>,
decltype(cmp)> pq(cmp);

/*-------------------- find_if --------------------*/

auto it=find_if(v.begin(),v.end(),[](int x){
    return x>10;
});

/*-------------------- count_if --------------------*/

int cnt=count_if(v.begin(),v.end(),[](int x){
    return x&1;
});

/*-------------------- remove_if --------------------*/

v.erase(remove_if(v.begin(),v.end(),[](int x){
    return x<0;
}),v.end());

/*-------------------- transform --------------------*/

transform(v.begin(),v.end(),v.begin(),[](int x){
    return x*x;
});

/*-------------------- all_of --------------------*/

bool ok=all_of(v.begin(),v.end(),[](int x){
    return x>0;
});

/*-------------------- Capture Example --------------------*/

int x=10;

sort(v.begin(),v.end(),[&](int a,int b){
    return abs(a-x)<abs(b-x);
});

/*-------------------- Mutable --------------------*/

int x=5;

auto f=[x]() mutable{
    x++;
    cout<<x;
};

f();

// Prints 6
// Original x remains 5

/*-------------------- Immediately Invoked --------------------*/

int ans=[](){
    return 5;
}();

/*-------------------- Recursive Lambda (C++14+) --------------------*/

auto dfs=[&](auto &&self,int u)->void{

    vis[u]=1;

    for(int v:g[u])
        if(!vis[v])
            self(self,v);

};

dfs(dfs,src);

/*-------------------- Common CF Tricks --------------------*/

// Sort by absolute value

sort(v.begin(),v.end(),[](int a,int b){
    return abs(a)<abs(b);
});

// Sort by distance from x

sort(v.begin(),v.end(),[&](int a,int b){
    return abs(a-x)<abs(b-x);
});

// Sort strings by length

sort(s.begin(),s.end(),[](string &a,string &b){
    return a.size()<b.size();
});

// Count evens

count_if(v.begin(),v.end(),[](int x){
    return x%2==0;
});

/*-------------------- Common Mistakes --------------------*/

// Comparator must return bool.

// Wrong

return a<=b;

// Correct

return a<b;

// Capture variable if needed.

// Wrong

int x=5;

sort(v.begin(),v.end(),[](int a,int b){
    return abs(a-x)<abs(b-x);
});

// Correct

sort(v.begin(),v.end(),[&](int a,int b){
    return abs(a-x)<abs(b-x);
});