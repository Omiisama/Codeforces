/*==================== UNORDERED SET ====================*/

// Stores UNIQUE elements.
// No ordering.
// Implemented using Hash Table.

/*-------------------- Declaration --------------------*/

unordered_set<int> st;
unordered_set<ll> st;

/*-------------------- Basic Operations --------------------*/

st.insert(x);
st.emplace(x);

st.erase(x);
st.erase(it);

st.find(x);
st.count(x);

st.size();
st.empty();

st.clear();

/*-------------------- Traversal --------------------*/

for(auto x:st)
    cout<<x<<" ";

/*-------------------- Find --------------------*/

auto it=st.find(x);

if(it!=st.end())
    cout<<"Found";

/*-------------------- Common CF Tricks --------------------*/

// Exists

if(st.count(x)){}

// OR

if(st.find(x)!=st.end()){}

/*-------------------- Common Mistakes --------------------*/

// Elements are NOT sorted.

// No lower_bound()
// No upper_bound()

/* Complexity

insert()    O(1) average
erase()     O(1) average
find()      O(1) average
count()     O(1) average

Worst Case : O(n)
*/



/*==================== UNORDERED MAP ====================*/

// Stores (key,value)
// Keys are UNIQUE.
// No ordering.

/*-------------------- Declaration --------------------*/

unordered_map<int,int> mp;
unordered_map<ll,int> mp;
unordered_map<string,int> mp;

/*-------------------- Basic Operations --------------------*/

mp[key]=value;

mp.insert({key,value});
mp.emplace(key,value);

mp.erase(key);
mp.erase(it);

mp.find(key);
mp.count(key);

mp.size();
mp.empty();

mp.clear();

/*-------------------- Traversal --------------------*/

for(auto [k,v]:mp)
    cout<<k<<" "<<v<<"\n";

/*-------------------- Frequency --------------------*/

unordered_map<int,int> freq;

for(int x:v)
    freq[x]++;

/*-------------------- Common CF Tricks --------------------*/

// Exists

if(mp.count(x)){}

// Increase frequency

mp[x]++;

// Remove if frequency becomes zero

if(--mp[x]==0)
    mp.erase(x);

/*-------------------- Common Mistakes --------------------*/

// Keys are NOT sorted.

// No lower_bound()
// No upper_bound()

// operator[] inserts key if absent.

/* Complexity

operator[]  O(1) average
insert()    O(1) average
erase()     O(1) average
find()      O(1) average
count()     O(1) average

Worst Case : O(n)
*/



/*==================== CUSTOM HASH ====================*/

// Prevents hacking on Codeforces.

struct custom_hash{

    static uint64_t splitmix64(uint64_t x){

        x+=0x9e3779b97f4a7c15;

        x=(x^(x>>30))*0xbf58476d1ce4e5b9;

        x=(x^(x>>27))*0x94d049bb133111eb;

        return x^(x>>31);
    }

    size_t operator()(uint64_t x) const{

        static const uint64_t FIXED_RANDOM=
        chrono::steady_clock::now().time_since_epoch().count();

        return splitmix64(x+FIXED_RANDOM);
    }
};

// Usage

unordered_map<ll,int,custom_hash> mp;

unordered_set<ll,custom_hash> st;



/*==================== PAIR HASH ====================*/

struct pair_hash{

    size_t operator()(const pair<int,int>&p) const{

        return hash<int>()(p.first)^
              (hash<int>()(p.second)<<1);
    }
};

// Usage

unordered_map<pair<int,int>,int,pair_hash> mp;

unordered_set<pair<int,int>,pair_hash> st;



/*==================== COMMON CF TIPS ====================*/

// Fast frequency map

unordered_map<int,int> cnt;

// Fast lookup

unordered_set<int> vis;

// Reserve memory (reduces rehashing)

mp.reserve(1<<18);
st.reserve(1<<18);

// Reduce load factor

mp.max_load_factor(0.25);
st.max_load_factor(0.25);



/*==================== MAP vs UNORDERED_MAP ====================*/

/*
map

Sorted
O(log n)
Supports lower_bound()

-------------------------

unordered_map

Not Sorted
Average O(1)
No lower_bound()
Can be hacked
*/



/*==================== COMMON MISTAKES ====================*/

// Don't expect sorted iteration.

// Don't use lower_bound().

// Use custom_hash on Codeforces
// if constraints are large.

/* Complexity

insert()        O(1) average
erase()         O(1) average
find()          O(1) average
count()         O(1) average

Worst Case      O(n)
*/  