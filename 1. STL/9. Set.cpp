/*==================== SET ====================*/

// Stores UNIQUE elements in sorted order.
// Implemented using Red-Black Tree.

/*-------------------- Declaration --------------------*/

set<int> st;
set<ll> s;
set<pair<int,int>> sp;

/*-------------------- Basic Operations --------------------*/

st.insert(x);
st.emplace(x);

st.erase(x);          // Erase by value
st.erase(it);         // Erase by iterator

st.find(x);

st.count(x);

st.lower_bound(x);
st.upper_bound(x);

st.begin();
st.end();

st.rbegin();
st.rend();

st.size();
st.empty();

st.clear();

/*-------------------- Example --------------------*/

set<int> st;

st.insert(5);
st.insert(2);
st.insert(8);
st.insert(5);

for(int x:st)
    cout<<x<<" ";

// Output
// 2 5 8

/*-------------------- Traversal --------------------*/

for(auto x:st)
    cout<<x<<" ";

for(auto it=st.begin();it!=st.end();it++)
    cout<<*it<<" ";

for(auto it=st.rbegin();it!=st.rend();it++)
    cout<<*it<<" ";

/*-------------------- Find --------------------*/

auto it=st.find(x);

if(it!=st.end())
    cout<<"Found";

/*-------------------- Count --------------------*/

// Since elements are unique

st.count(x);      // 0 or 1

/*-------------------- Erase --------------------*/

// By Value

st.erase(x);

// By Iterator

auto it=st.find(x);

if(it!=st.end())
    st.erase(it);

/*-------------------- Lower Bound --------------------*/

// First element >= x

auto it=st.lower_bound(x);

/*-------------------- Upper Bound --------------------*/

// First element > x

auto it=st.upper_bound(x);

/*-------------------- Previous Element --------------------*/

// Largest element < x

auto it=st.lower_bound(x);

if(it!=st.begin()){
    --it;
    cout<<*it;
}

/*-------------------- Next Element --------------------*/

// Smallest element > x

auto it=st.upper_bound(x);

if(it!=st.end())
    cout<<*it;

/*-------------------- First / Last --------------------*/

int mn=*st.begin();
int mx=*st.rbegin();

// OR

int mx=*prev(st.end());

/*-------------------- Pair --------------------*/

set<pair<int,int>> st;

st.insert({2,5});
st.insert({1,8});

for(auto [x,y]:st)
    cout<<x<<" "<<y<<"\n";

/*-------------------- Custom Comparator --------------------*/

// Descending

set<int,greater<int>> st;

// Custom

struct cmp{
    bool operator()(int a,int b) const{
        return a>b;
    }
};

set<int,cmp> st;

/*-------------------- Common CF Tricks --------------------*/

// Exists

if(st.count(x)){}

// OR

if(st.find(x)!=st.end()){}

// Minimum

*st.begin();

// Maximum

*st.rbegin();

// Smallest >= x

auto it=st.lower_bound(x);

// Smallest > x

auto it=st.upper_bound(x);

// Largest < x

auto it=st.lower_bound(x);

if(it!=st.begin()){
    --it;
}

// Largest <= x

auto it=st.upper_bound(x);

if(it!=st.begin()){
    --it;
}

/*-------------------- Common Mistakes --------------------*/

// insert() ignores duplicates.

st.insert(5);
st.insert(5);

// Size is still 1.

// Don't dereference end().

auto it=st.find(x);

if(it!=st.end())
    cout<<*it;

// erase(x) does nothing if x doesn't exist.

/* Complexity

insert()        O(log n)
emplace()       O(log n)
erase()         O(log n)
find()          O(log n)
count()         O(log n)
lower_bound()   O(log n)
upper_bound()   O(log n)
begin()         O(1)
rbegin()        O(1)
size()          O(1)
empty()         O(1)
clear()         O(n)
*/