/*==================== MAP ====================*/

// Stores (key,value) pairs.
// Keys are UNIQUE and sorted by key.
// Implemented using Red-Black Tree.

/*-------------------- Declaration --------------------*/

map<int,int> mp;
map<string,int> mp;
map<int,ll> mp;
map<pair<int,int>,int> mp;

/*-------------------- Basic Operations --------------------*/

mp[key]=value;

mp.insert({key,value});
mp.emplace(key,value);

mp.erase(key);
mp.erase(it);

mp.find(key);

mp.count(key);

mp.lower_bound(key);
mp.upper_bound(key);

mp.begin();
mp.end();

mp.rbegin();
mp.rend();

mp.size();
mp.empty();

mp.clear();

/*-------------------- Example --------------------*/

map<string,int> mp;

mp["Alice"]=10;
mp["Bob"]=20;

cout<<mp["Alice"];

// 10

/*-------------------- Traversal --------------------*/

for(auto [k,v]:mp)
    cout<<k<<" "<<v<<"\n";

for(auto it=mp.begin();it!=mp.end();it++)
    cout<<it->first<<" "<<it->second<<"\n";

/*-------------------- Find --------------------*/

auto it=mp.find(key);

if(it!=mp.end())
    cout<<it->second;

/*-------------------- Count --------------------*/

// 0 or 1

mp.count(key);

/*-------------------- Frequency Map --------------------*/

map<int,int> freq;

for(int x:v)
    freq[x]++;

for(auto [x,cnt]:freq)
    cout<<x<<" "<<cnt<<"\n";

/*-------------------- Access --------------------*/

// Inserts key if absent

mp[key];

// Access without insertion

mp.at(key);

/*
at() throws exception
if key doesn't exist.
*/

/*-------------------- Erase --------------------*/

mp.erase(key);

auto it=mp.find(key);

if(it!=mp.end())
    mp.erase(it);

/*-------------------- Lower / Upper Bound --------------------*/

// First key >= x

auto it=mp.lower_bound(x);

// First key > x

auto it=mp.upper_bound(x);

/*-------------------- First / Last --------------------*/

auto first=*mp.begin();

auto last=*mp.rbegin();

// key

first.first;
last.first;

// value

first.second;
last.second;

/*-------------------- Custom Comparator --------------------*/

map<int,int,greater<int>> mp;

/*-------------------- Common CF Tricks --------------------*/

// Frequency

mp[x]++;

// Exists

if(mp.count(x)){}

// OR

if(mp.find(x)!=mp.end()){}

// Decrease frequency

if(--mp[x]==0)
    mp.erase(x);

// Iterate

for(auto &[k,v]:mp)
    cout<<k<<" "<<v<<"\n";

/*-------------------- Common Mistakes --------------------*/

// WRONG

if(mp[x])

// Inserts x if absent.

// Correct

if(mp.count(x))

// OR

if(mp.find(x)!=mp.end())

// at() doesn't insert.

mp.at(x);

/*-------------------- Complexity

operator[]      O(log n)
insert()        O(log n)
emplace()       O(log n)
erase()         O(log n)
find()          O(log n)
count()         O(log n)
lower_bound()   O(log n)
upper_bound()   O(log n)
size()          O(1)
empty()         O(1)
clear()         O(n)
*/