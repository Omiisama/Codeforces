/*==================== BINARY SEARCH FUNCTIONS ====================*/
// Works only on SORTED containers.
/*-------------------- lower_bound --------------------*/

// First element >= x
auto it=lower_bound(v.begin(),v.end(),x);
// Index
int idx=lower_bound(v.begin(),v.end(),x)-v.begin();

// Examples
vector<int> v={1,2,2,2,4,6};
lower_bound(v.begin(),v.end(),2);   // index = 1
lower_bound(v.begin(),v.end(),3);   // index = 4
lower_bound(v.begin(),v.end(),7);   // end()

/*-------------------- upper_bound --------------------*/

// First element > x
auto it=upper_bound(v.begin(),v.end(),x);
// Index
int idx=upper_bound(v.begin(),v.end(),x)-v.begin();

// Examples
upper_bound(v.begin(),v.end(),2);   // index = 4
upper_bound(v.begin(),v.end(),3);   // index = 4

/*-------------------- binary_search --------------------*/
// Returns bool
if(binary_search(v.begin(),v.end(),x)) cout<<"Found";

/*-------------------- equal_range --------------------*/

// Returns {lower_bound, upper_bound}
auto p=equal_range(v.begin(),v.end(),x);

auto L=p.first;
auto R=p.second;

// Frequency
int freq_x = R-L;

/*-------------------- Count Occurrences --------------------*/

int cnt=upper_bound(v.begin(),v.end(),x)
       -lower_bound(v.begin(),v.end(),x);

/*-------------------- Insert While Keeping Sorted --------------------*/

v.insert(lower_bound(v.begin(),v.end(),x),x);

/*-------------------- First Element >= x --------------------*/

auto it=lower_bound(v.begin(),v.end(),x);
if(it!=v.end()) cout<<*it;

/*-------------------- First Element > x --------------------*/

auto it=upper_bound(v.begin(),v.end(),x);
if(it!=v.end()) cout<<*it;

/*-------------------- Largest Element < x --------------------*/

auto it=lower_bound(v.begin(),v.end(),x);

if(it!=v.begin()){
    --it;
    cout<<*it;
}

/*-------------------- Largest Element <= x --------------------*/

auto it=upper_bound(v.begin(),v.end(),x);

if(it!=v.begin()){
    --it;
    cout<<*it;
}

/*-------------------- Number of Elements --------------------*/

// < x
int less=lower_bound(v.begin(),v.end(),x)-v.begin();

// <= x
int leq=upper_bound(v.begin(),v.end(),x)-v.begin();

// >= x
int geq=v.end()-lower_bound(v.begin(),v.end(),x);

// > x
int greater=v.end()-upper_bound(v.begin(),v.end(),x);

/*-------------------- Array --------------------*/

lower_bound(a,a+n,x);
upper_bound(a,a+n,x);

/*-------------------- String --------------------*/

string s="abccde";
lower_bound(s.begin(),s.end(),'c');

/*-------------------- Pair --------------------*/

// Lexicographical comparison

vector<pair<int,int>> vp;
lower_bound(vp.begin(),vp.end(),make_pair(x,y));

/*-------------------- Descending Order --------------------*/

sort(v.begin(),v.end(),greater<int>());

lower_bound(v.begin(),v.end(),x,greater<int>());
upper_bound(v.begin(),v.end(),x,greater<int>());

/*-------------------- Set --------------------*/

set<int> st;

auto it=st.lower_bound(x);      // First >= x
auto it2=st.upper_bound(x);     // First > x
/*-------------------- Map --------------------*/

// Searches by KEY

map<int,int> mp;

mp.lower_bound(x);
mp.upper_bound(x);

/*-------------------- Unordered Containers --------------------*/

// Not available
// unordered_set
// unordered_map

/*-------------------- Common Mistakes --------------------*/

// ❌ Container not sorted

// ❌ Dereferencing end()

auto it=lower_bound(v.begin(),v.end(),x);

if(it!=v.end())
    cout<<*it;

// ❌ lower_bound returns iterator, NOT bool

// ❌ binary_search returns bool, NOT iterator

/* Complexity

lower_bound()    : O(log n)
upper_bound()    : O(log n)
binary_search()  : O(log n)
equal_range()    : O(log n)

(set/map versions are also O(log n))
*/