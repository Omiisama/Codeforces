/*==================== VECTOR ====================*/

// Declaration
vector<int> v;
vector<ll> a;
vector<pair<int,int>> vp;
vector<vector<int>> adj;

// Initialization
vector<int> v1(5);            // {0,0,0,0,0}
vector<int> v2(5,7);          // {7,7,7,7,7}
vector<int> v3={1,2,3};
vector<int> v4=v3;            // O(n)

// Size
v.size();                     // O(1)
v.empty();                    // O(1)

// Access
v[i];                          // No bounds check
v.at(i);                       // Bounds check
v.front();
v.back();

// Modification
v.push_back(x);                // Amortized O(1)
v.emplace_back(a,b);           // For pair/object
v.pop_back();                  // O(1)
v.clear();                     // O(n)
v.resize(n);
v.resize(n,val);
v.reserve(n);
v.assign(n,val);
v.assign(a.begin(),a.end());

// Insert / Erase
v.insert(v.begin()+i,x);                   // O(n)
v.insert(v.end(),a.begin(),a.end());       // Append vector
v.erase(v.begin()+i);                      // O(n)
v.erase(v.begin()+l,v.begin()+r);          // [l,r)
v.swap(other);                             // O(1)
v.shrink_to_fit();                         // Rarely used

// Traversal
for(int i=0;i<v.size();i++){}
for(auto x:v){}
for(auto &x:v) cin>>x;
for(const auto &x:v){}

// 2D Vector
vector<vector<int>> grid(n,vector<int>(m));
vector<vector<int>> vis(n,vector<int>(m,-1));

// Common CF Patterns
ll sum=accumulate(v.begin(),v.end(),0LL);
int mn=*min_element(v.begin(),v.end());
int mx=*max_element(v.begin(),v.end());
sort(v.begin(),v.end());
reverse(v.begin(),v.end());

// Common Mistakes
// for(auto x:v) cin>>x;      // Doesn't modify vector
// front(), back(), pop_back() on empty vector => UB
// insert(), erase(), push_back() may invalidate iterators

/* Complexity
size(), empty(), front(), back(), [] : O(1)
push_back(), emplace_back() : Amortized O(1)
pop_back() : O(1)
clear(), assign() : O(n)
insert(), erase() : O(n)
resize() : O(new_size)
swap() : O(1)
*/