/*==================== PRIORITY QUEUE ====================*/

// Default : Max Heap

priority_queue<int> pq;

// Basic Operations

pq.push(x);
pq.emplace(x);
pq.pop();

pq.top();

pq.size();
pq.empty();

/*-------------------- Max Heap --------------------*/

priority_queue<int> pq;

pq.push(5);
pq.push(2);
pq.push(8);

while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
}

// Output
// 8 5 2

/*-------------------- Min Heap --------------------*/

priority_queue<int,vector<int>,greater<int>> pq;

pq.push(5);
pq.push(2);
pq.push(8);

// Output
// 2 5 8

/*-------------------- Pair --------------------*/

// Lexicographical

priority_queue<pair<int,int>> pq;

pq.push({3,2});
pq.push({3,5});
pq.push({1,8});

// Top
// (3,5)

/*
Order

first descending
then second descending
*/

/*-------------------- Pair Min Heap --------------------*/

priority_queue<
pair<int,int>,
vector<pair<int,int>>,
greater<pair<int,int>>
> pq;

/*-------------------- Tuple --------------------*/

priority_queue<tuple<int,int,int>> pq;

pq.push({1,2,3});

/*-------------------- Custom Comparator --------------------*/

struct cmp{

    bool operator()(int a,int b){
        return a>b;
    }

};

priority_queue<int,vector<int>,cmp> pq;

/*-------------------- Custom Comparator (Pair) --------------------*/

// Smaller second has higher priority

struct cmp{

    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }

};

priority_queue<
pair<int,int>,
vector<pair<int,int>>,
cmp
> pq;

/*-------------------- Lambda Comparator (C++20) --------------------*/

auto cmp=[](int a,int b){
    return a>b;
};

priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);

/*-------------------- Dijkstra --------------------*/

// {distance,node}

priority_queue<
pair<ll,int>,
vector<pair<ll,int>>,
greater<pair<ll,int>>
> pq;

pq.push({0,src});

/*-------------------- K Largest --------------------*/

// Keep k largest elements

priority_queue<int,vector<int>,greater<int>> pq;

for(int x:v){

    pq.push(x);

    if(pq.size()>k)
        pq.pop();
}

/*-------------------- K Smallest --------------------*/

// Keep k smallest elements

priority_queue<int> pq;

for(int x:v){

    pq.push(x);

    if(pq.size()>k)
        pq.pop();
}

/*-------------------- Common CF Tricks --------------------*/

// Max

int mx=pq.top();

// Min Heap

priority_queue<int,vector<int>,greater<int>> pq;

// Pair

priority_queue<pair<int,int>> pq;

// Dijkstra

priority_queue<
pair<ll,int>,
vector<pair<ll,int>>,
greater<pair<ll,int>>
> pq;

// Store tuple

priority_queue<
tuple<int,int,int>,
vector<tuple<int,int,int>>,
greater<tuple<int,int,int>>
> pq;

/*-------------------- Common Mistakes --------------------*/

// Don't call top() on empty queue.

if(!pq.empty())
    cout<<pq.top();

// Default is MAX heap.

// greater<T> gives MIN heap.

// For pair

// Orders by first.
// If first equal,
// then by second.

/* Complexity

push()      O(log n)
emplace()   O(log n)
pop()       O(log n)
top()       O(1)
size()      O(1)
empty()     O(1)