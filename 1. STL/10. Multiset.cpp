/*==================== MULTISET ====================*/

// Stores elements in sorted order.
// Allows DUPLICATES.

/*-------------------- Declaration --------------------*/

multiset<int> ms;
multiset<ll> ms;
multiset<pair<int,int>> ms;

/*-------------------- Basic Operations --------------------*/

ms.insert(x);
ms.emplace(x);

ms.erase(x);          // Erases ALL occurrences
ms.erase(it);         // Erases ONE occurrence

ms.find(x);

ms.count(x);

ms.lower_bound(x);
ms.upper_bound(x);

ms.begin();
ms.end();

ms.rbegin();
ms.rend();

ms.size();
ms.empty();

ms.clear();

/*-------------------- Example --------------------*/

multiset<int> ms;

ms.insert(5);
ms.insert(2);
ms.insert(5);
ms.insert(8);

for(int x:ms)
    cout<<x<<" ";

// Output
// 2 5 5 8

/*-------------------- Find --------------------*/

auto it=ms.find(x);

if(it!=ms.end())
    cout<<"Found";

/*
find(x)

Returns iterator to FIRST occurrence.
*/

/*-------------------- Count --------------------*/

int cnt=ms.count(x);

/*-------------------- Erase --------------------*/

// Remove ALL copies

ms.erase(x);

// Remove ONE copy

auto it=ms.find(x);

if(it!=ms.end())
    ms.erase(it);

/*
Example

5 5 5 8

erase(5)

8

-----------------

5 5 5 8

erase(find(5))

5 5 8
*/

/*-------------------- Lower / Upper Bound --------------------*/

// First >= x

auto it=ms.lower_bound(x);

// First > x

auto it=ms.upper_bound(x);

/*-------------------- Frequency --------------------*/

int freq=ms.count(x);

// OR

int freq=distance(ms.lower_bound(x),ms.upper_bound(x));

/*-------------------- First / Last --------------------*/

int mn=*ms.begin();

int mx=*ms.rbegin();

// OR

int mx=*prev(ms.end());

/*-------------------- Pair --------------------*/

multiset<pair<int,int>> ms;

/*-------------------- Descending --------------------*/

multiset<int,greater<int>> ms;

/*-------------------- Common CF Tricks --------------------*/

// Remove ONE occurrence

auto it=ms.find(x);

if(it!=ms.end())
    ms.erase(it);

// Minimum

*ms.begin();

// Maximum

*ms.rbegin();

// Smallest >= x

ms.lower_bound(x);

// Smallest > x

ms.upper_bound(x);

/*-------------------- Common Mistakes --------------------*/

// WRONG

ms.erase(x);

// Removes EVERY occurrence.

// Correct

auto it=ms.find(x);

if(it!=ms.end())
    ms.erase(it);

// Don't dereference end()

auto it=ms.find(x);

if(it!=ms.end())
    cout<<*it;

/* Complexity

insert()        O(log n)
emplace()       O(log n)
erase(value)    O(log n + count)
erase(iterator) O(log n)
find()          O(log n)
count()         O(log n + count)
lower_bound()   O(log n)
upper_bound()   O(log n)
size()          O(1)
empty()         O(1)
clear()         O(n)
*/