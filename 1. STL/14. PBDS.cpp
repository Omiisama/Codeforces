/*==================== PBDS ====================*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

/*-------------------- Ordered Set --------------------*/

template<class T>
using ordered_set = tree<
T,
null_type,
less<T>,
rb_tree_tag,
tree_order_statistics_node_update
>;

ordered_set<int> st;

/*-------------------- Basic Operations --------------------*/

st.insert(x);
st.erase(x);

st.find(x);

st.size();
st.empty();

st.clear();

/*-------------------- find_by_order --------------------*/

// Iterator to k-th smallest element (0-indexed)

auto it=st.find_by_order(k);

if(it!=st.end())
    cout<<*it;

// Example

// Set = {2,5,7,10}

*st.find_by_order(0);     // 2
*st.find_by_order(2);     // 7

/*-------------------- order_of_key --------------------*/

// Number of elements strictly less than x

st.order_of_key(x);

// Example

// Set = {2,5,7,10}

st.order_of_key(1);       // 0
st.order_of_key(2);       // 0
st.order_of_key(6);       // 2
st.order_of_key(100);     // 4

/*-------------------- Exists --------------------*/

if(st.find(x)!=st.end()){

}

/*-------------------- Lower Bound --------------------*/

auto it=st.lower_bound(x);

/*-------------------- Upper Bound --------------------*/

auto it=st.upper_bound(x);

/*-------------------- Traversal --------------------*/

for(auto x:st)
    cout<<x<<" ";

/*-------------------- Descending --------------------*/

template<class T>
using ordered_set_desc = tree<
T,
null_type,
greater<T>,
rb_tree_tag,
tree_order_statistics_node_update
>;

/*-------------------- Ordered Multiset --------------------*/

// Duplicates using pair

template<class T>
using ordered_multiset = tree<
pair<T,int>,
null_type,
less<pair<T,int>>,
rb_tree_tag,
tree_order_statistics_node_update
>;

ordered_multiset<int> ms;

int timer=0;

ms.insert({5,timer++});
ms.insert({5,timer++});
ms.insert({2,timer++});

/*
Elements

(2,0)
(5,1)
(5,2)
*/

// Erase ONE occurrence

auto it=ms.lower_bound({5,-1});

if(it!=ms.end())
    ms.erase(it);

// Count elements < x

ms.order_of_key({x,-1});

// k-th smallest

ms.find_by_order(k);

/*-------------------- Common CF Tricks --------------------*/

// k-th smallest

int kth=*st.find_by_order(k);

// Rank of x

int rank=st.order_of_key(x);

// Count elements < x

int cnt=st.order_of_key(x);

// Count elements >= x

int cnt=st.size()-st.order_of_key(x);

// Count elements in [l,r]

int cnt=st.order_of_key(r+1)
       -st.order_of_key(l);

/*-------------------- Common Mistakes --------------------*/

// find_by_order() is 0-indexed.

// Wrong

find_by_order(1);

// Returns SECOND smallest.

// Check iterator

auto it=st.find_by_order(k);

if(it!=st.end())
    cout<<*it;

// ordered_set does NOT allow duplicates.

/* Complexity

insert()          O(log n)
erase()           O(log n)
find()            O(log n)
lower_bound()     O(log n)
upper_bound()     O(log n)
find_by_order()   O(log n)
order_of_key()    O(log n)