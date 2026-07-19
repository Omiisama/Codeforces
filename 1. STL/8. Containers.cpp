/*==================== STACK ====================*/

stack<int> st;

// Basic Operations

st.push(x);
st.emplace(x);
st.pop();
st.top();

st.size();
st.empty();

// Example

stack<int> st;

st.push(1);
st.push(2);
st.push(3);

while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
}

// Output
// 3 2 1

// Swap

stack<int> s1,s2;
s1.swap(s2);

// Complexity

push()      O(1)
emplace()   O(1)
pop()       O(1)
top()       O(1)
size()      O(1)
empty()     O(1)



/*==================== QUEUE ====================*/

queue<int> q;

// Basic Operations

q.push(x);
q.emplace(x);
q.pop();

q.front();
q.back();

q.size();
q.empty();

// Example

queue<int> q;

q.push(1);
q.push(2);
q.push(3);

while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
}

// Output
// 1 2 3

// Swap

queue<int> q1,q2;
q1.swap(q2);

// Complexity

push()      O(1)
emplace()   O(1)
pop()       O(1)
front()     O(1)
back()      O(1)
size()      O(1)
empty()     O(1)



/*==================== DEQUE ====================*/

deque<int> dq;

// Basic Operations

dq.push_back(x);
dq.push_front(x);

dq.emplace_back(x);
dq.emplace_front(x);

dq.pop_back();
dq.pop_front();

dq.front();
dq.back();

dq[i];

dq.size();
dq.empty();

// Insert / Erase

dq.insert(dq.begin()+i,x);
dq.erase(dq.begin()+i);

// Example

deque<int> dq;

dq.push_back(2);
dq.push_front(1);
dq.push_back(3);

// 1 2 3

while(!dq.empty()){
    cout<<dq.front()<<" ";
    dq.pop_front();
}

// Output
// 1 2 3

// Reverse Traversal

for(auto it=dq.rbegin();it!=dq.rend();it++)
    cout<<*it<<" ";

// Complexity

push_front()    O(1)
push_back()     O(1)
pop_front()     O(1)
pop_back()      O(1)
front()         O(1)
back()          O(1)
operator[]      O(1)
insert()        O(n)
erase()         O(n)



/*==================== COMMON CF USES ====================*/

// Stack
// DFS
// Bracket Matching
// Monotonic Stack
// Expression Evaluation

// Queue
// BFS
// Multi-source BFS
// Simulation

// Deque
// 0-1 BFS
// Sliding Window
// Monotonic Queue



/*==================== COMMON MISTAKES ====================*/

// Don't call
// top(), front(), back(), pop()
// on empty container.

if(!st.empty())
    cout<<st.top();

if(!q.empty())
    cout<<q.front();

if(!dq.empty())
    cout<<dq.front();