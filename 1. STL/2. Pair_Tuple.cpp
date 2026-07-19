/*==================== PAIR & TUPLE ====================*/
// Declaration
// pair<type1, type2> p
pair<int,int> p;

// Initialization
pair<int,int> p={1,2};
pair<int,int> p(1,2);
auto p=make_pair(1,2);

// Access
p.first; p.second;
// Common Macro
#define F first
#define S second
p.F;
p.S;

// Comparison (Lexicographical)
// First compares first, then second
pair<int,int> a={1,5};
pair<int,int> b={2,1};
a<b;      // true
// < <= > >= == != all works

// Swap
swap(a,b);
a.swap(b);

// Reading
cin>>p.first>>p.second;

// Traversal in vector of pairs
for(auto &[u,v]:vp){
    cout<<u<<" "<<v<<"\n";
}

// Custom Sorting
sort(vp.begin(),vp.end(),[](auto &a, auto &b){
    if(a.first!=b.first) return a.first<b.first;
    return a.second>b.second;
});

// Lower/Upper Bound
lower_bound(vp.begin(),vp.end(),make_pair(x,y));
upper_bound(vp.begin(),vp.end(),make_pair(x,y));

/*-------------------- TUPLE --------------------*/
// Declaration
// tuple<type1, type2, type3> t
tuple<int,int,int> t;

// Initialization
tuple<int,int,int> t={1,2,3};
auto t2=make_tuple(4,5,6);

// Access
get<0>(t);
get<1>(t);
get<2>(t);

// Structured Binding (C++17)
auto [x,y,z]=t;

// tie()
int a,b,c;
tie(a,b,c)=t;

// Ignore Values
int x,y;
tie(x,ignore,y)=t;

// Comparison (Lexicographical)
tuple<int,int,int> A={1,2,3};
tuple<int,int,int> B={1,3,1};
// A<B == true

// Traversal in vector of tuples
for(auto &[a,b,c]:vt){
    cout<<a<<" "<<b<<" "<<c<<"\n";
}

/* Common CF Uses

pair
✓ Graph edges
✓ BFS Queue
✓ Coordinates
✓ {value,index}
✓ Priority Queue
✓ Sorting

tuple
✓ State DP
✓ Dijkstra (dist,node,parent)
✓ Events
✓ Multiple return values
✓ 3D coordinates

Complexity
Construction : O(1)
Access : O(1)
Comparison : O(min(size until mismatch))
Swap : O(1)
*/