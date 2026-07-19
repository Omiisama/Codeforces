/*==================== SEARCHING ALGORITHMS ====================*/

/*-------------------- find --------------------*/

// Returns iterator to first occurrence.
// Returns end() if not found.

auto it=find(v.begin(),v.end(),x);

if(it!=v.end())
    cout<<"Found";

// Index
int idx=it-v.begin();

// Complexity : O(n)

/*-------------------- find_if --------------------*/

// First element satisfying condition.

auto it=find_if(v.begin(),v.end(),[](int x){
    return x>10;
});

// Complexity : O(n)

/*-------------------- find_if_not --------------------*/

// First element NOT satisfying condition.

auto it=find_if_not(v.begin(),v.end(),[](int x){
    return x&1;
});

/*-------------------- count --------------------*/

// Number of occurrences.

int cnt=count(v.begin(),v.end(),x);

// Complexity : O(n)

/*-------------------- count_if --------------------*/

// Number satisfying condition.

int cnt=count_if(v.begin(),v.end(),[](int x){
    return x&1;
});

// Complexity : O(n)

/*-------------------- all_of --------------------*/

// True if ALL satisfy condition.

bool ok=all_of(v.begin(),v.end(),[](int x){
    return x>0;
});

/*-------------------- any_of --------------------*/

// True if ANY satisfy condition.

bool ok=any_of(v.begin(),v.end(),[](int x){
    return x<0;
});

/*-------------------- none_of --------------------*/

// True if NONE satisfy condition.

bool ok=none_of(v.begin(),v.end(),[](int x){
    return x==0;
});

/*-------------------- equal --------------------*/

// Checks if two ranges are equal.

equal(a.begin(),a.end(),b.begin());

/*
Example

1 2 3
1 2 3

true
*/

/*-------------------- mismatch --------------------*/

// Returns first mismatching pair.

auto p=mismatch(a.begin(),a.end(),b.begin());

auto it1=p.first;
auto it2=p.second;

// Example

// 1 2 5 4
// 1 2 3 4

// *it1 = 5
// *it2 = 3

/*-------------------- search --------------------*/

// Find subarray/subsequence.

vector<int> a={1,2,3,4,5};
vector<int> b={3,4};

auto it=search(a.begin(),a.end(),
               b.begin(),b.end());

/*-------------------- search_n --------------------*/

// Find k consecutive occurrences.

auto it=search_n(v.begin(),v.end(),3,5);

// Finds first occurrence of
// 5 5 5

/*-------------------- Common CF Tricks --------------------*/

// Exists

bool ok=find(v.begin(),v.end(),x)!=v.end();

// Frequency

int freq=count(v.begin(),v.end(),x);

// All positive

bool ok=all_of(v.begin(),v.end(),[](int x){
    return x>0;
});

// Any negative

bool ok=any_of(v.begin(),v.end(),[](int x){
    return x<0;
});

// None zero

bool ok=none_of(v.begin(),v.end(),[](int x){
    return x==0;
});

/*-------------------- Common Mistakes --------------------*/

// find() returns iterator, NOT bool.

// Wrong
if(find(v.begin(),v.end(),x))

// Correct
if(find(v.begin(),v.end(),x)!=v.end())

// Don't dereference end().

auto it=find(v.begin(),v.end(),x);

if(it!=v.end())
    cout<<*it;

/* Complexity

find()          : O(n)
find_if()       : O(n)
find_if_not()   : O(n)
count()         : O(n)
count_if()      : O(n)
all_of()        : O(n)
any_of()        : O(n)
none_of()       : O(n)
equal()         : O(n)
mismatch()      : O(n)
search()        : O(n*m)
search_n()      : O(n)
*/   