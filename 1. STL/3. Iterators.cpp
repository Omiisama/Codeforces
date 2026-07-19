/*==================== ITERATORS ====================*/

// begin() -> First element
v.begin();
// end() -> One position after last element
v.end();
// rbegin() -> Last element
v.rbegin();
// rend() -> One position before first element
v.rend();

// Iterator Declaration
vector<int>::iterator it;
set<int>::iterator it2;
map<int,int>::iterator it3;
// Auto (Recommended)
auto it=v.begin();

// Access Value by *it
// Move Iterator
++it;
--it;
advance(it,3);          // Move forward by 3
advance(it,-2);         // Move backward (bidirectional iterators)
// Next / Prev
next(it);
next(it,3);
prev(it);
prev(it,2);

// Distance
distance(v.begin(),it);

// Traversal
for(auto it=v.begin();it!=v.end();it++) cout<<*it<<" ";
for(auto it=v.rbegin();it!=v.rend();it++) cout<<*it<<" ";

// Const Iterator
vector<int>::const_iterator it=v.begin();

// Erase using Iterator
v.erase(it);

// Erase Range
v.erase(it1,it2);

// Find returns Iterator
auto it=find(v.begin(),v.end(),10);
if(it!=v.end()) cout<<"Found";

// lower_bound / upper_bound return iterators
auto it=lower_bound(v.begin(),v.end(),x);
auto it=upper_bound(v.begin(),v.end(),x);

// Index from Iterator (Vector)
int idx=it-v.begin();

// Iterator from Index
auto it=v.begin()+idx;

// ==================== Iterator Categories ====================

// Random Access
vector
deque
array

// Bidirectional
set
multiset
map
multimap

// Forward
forward_list

// Unordered
unordered_set
unordered_map

/* Common Mistakes

// Wrong
cout<<it;
// Correct
cout<<*it;

// Wrong
v.end() points to last element
// Correct
v.end() is ONE PAST the last element

// Wrong
*v.end();        // Undefined
// Check before dereferencing
if(it!=v.end()) ...

// Vector iterators become invalid after
push_back()
insert()
erase()
resize()

// Set/Map iterators remain valid after insertion
(except erased iterator)

/* Complexity

begin(), end()          : O(1)
++, --                  : O(1)
next(), prev()          : O(k)
advance()               : O(k)*
distance()              : O(k)*

* O(1) for random access iterators (vector, deque, array)
  O(k) for set/map/multiset/etc.
*/