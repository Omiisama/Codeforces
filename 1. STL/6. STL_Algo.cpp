/*==================== STL ALGORITHMS - PART 1 ====================*/

/*-------------------- reverse --------------------*/

// Reverse entire container
reverse(v.begin(),v.end());

// Reverse subarray [l,r]
reverse(v.begin()+l,v.begin()+r+1);

// String
reverse(s.begin(),s.end());

// Complexity : O(n)

/*-------------------- rotate --------------------*/

// rotate(first,middle,last)

// Left Rotate
rotate(v.begin(),v.begin()+k,v.end());

// Example
// 1 2 3 4 5
// k=2
// 3 4 5 1 2

// Right Rotate
rotate(v.begin(),v.end()-k,v.end());

// Example
// 1 2 3 4 5
// k=2
// 4 5 1 2 3

// Complexity : O(n)

/*-------------------- unique --------------------*/

// Removes consecutive duplicates.
// Returns iterator to new logical end.

vector<int> v={1,1,2,2,2,3,3,4};

auto it=unique(v.begin(),v.end());

v.erase(it,v.end());

// Result
// 1 2 3 4

// Complexity : O(n)

/* IMPORTANT */

// unique() DOES NOT remove all duplicates.
// It removes only adjacent duplicates.

vector<int> v={1,3,2,3,1};

unique(v.begin(),v.end());

// Still has duplicates.

// To remove all duplicates

sort(v.begin(),v.end());
v.erase(unique(v.begin(),v.end()),v.end());

/*-------------------- erase-remove idiom --------------------*/

// Remove all occurrences of x

v.erase(remove(v.begin(),v.end(),x),v.end());

// Example

vector<int> v={1,2,3,2,4};

v.erase(remove(v.begin(),v.end(),2),v.end());

// 1 3 4

// Remove by condition

v.erase(remove_if(v.begin(),v.end(),[](int x){
    return x&1;
}),v.end());

// Removes all odd numbers

/*-------------------- next_permutation --------------------*/

vector<int> v={1,2,3};

next_permutation(v.begin(),v.end());

// 1 3 2

// Returns false if already last permutation.

while(next_permutation(v.begin(),v.end())){
    // process
}

// IMPORTANT
// Start from sorted order.

/*-------------------- prev_permutation --------------------*/

vector<int> v={3,2,1};

prev_permutation(v.begin(),v.end());

// 3 1 2

while(prev_permutation(v.begin(),v.end())){
    // process
}

// IMPORTANT
// Start from reverse sorted order.

/*-------------------- Common CF Tricks --------------------*/

// Remove duplicates

sort(v.begin(),v.end());
v.erase(unique(v.begin(),v.end()),v.end());

// Number of distinct elements

sort(v.begin(),v.end());
int distinct=unique(v.begin(),v.end())-v.begin();

// Rotate string

rotate(s.begin(),s.begin()+k,s.end());

/*-------------------- Common Mistakes --------------------*/

// unique() doesn't resize vector

v.erase(unique(v.begin(),v.end()),v.end());

// next_permutation() expects initial sequence sorted.

// prev_permutation() expects reverse sorted.

/* Complexity

reverse()            : O(n)
rotate()             : O(n)
unique()             : O(n)
remove()             : O(n)
remove_if()          : O(n)
next_permutation()   : O(n)
prev_permutation()   : O(n)
*/