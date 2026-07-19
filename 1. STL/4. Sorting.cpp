/*==================== SORTING ====================*/

// Ascending
sort(v.begin(),v.end());
// Descending
sort(v.begin(),v.end(),greater<int>());
// Array
sort(a,a+n);
// String
sort(s.begin(),s.end());
// Reverse after sorting
sort(v.begin(),v.end());
reverse(v.begin(),v.end());

/*-------------------- Pair Sorting --------------------*/

// Default: First ↑ then Second ↑
vector<pair<int,int>> vp;

sort(vp.begin(),vp.end());

// Example
// {2,5} {1,7} {2,3}
// ->
// {1,7} {2,3} {2,5}

/*-------------------- Tuple Sorting --------------------*/

// Default: Lexicographical
vector<tuple<int,int,int>> vt;

sort(vt.begin(),vt.end());

/*-------------------- Custom Comparator --------------------*/

// Function

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first!=b.first)
        return a.first<b.first;
    return a.second>b.second;
}

sort(vp.begin(),vp.end(),cmp);

// Lambda

sort(vp.begin(),vp.end(),[](auto &a, auto &b){
    if(a.first!=b.first)
        return a.first<b.first;
    return a.second>b.second;
});

/*-------------------- Frequently Used Comparators --------------------*/

// First Ascending, Second Descending

sort(vp.begin(),vp.end(),[](auto &a, auto &b){
    if(a.first!=b.first)
        return a.first<b.first;
    return a.second>b.second;
});

// First Descending

sort(vp.begin(),vp.end(),[](auto &a, auto &b){
    return a.first>b.first;
});

// Second Ascending

sort(vp.begin(),vp.end(),[](auto &a, auto &b){
    return a.second<b.second;
});

// Second Descending

sort(vp.begin(),vp.end(),[](auto &a, auto &b){
    return a.second>b.second;
});

// Absolute Value

sort(v.begin(),v.end(),[](int a,int b){
    return abs(a)<abs(b);
});

/*-------------------- stable_sort --------------------*/

// Equal elements keep original order

stable_sort(v.begin(),v.end());

/*
Example

(2,A)
(1,B)
(2,C)

sort() may become

(1,B)
(2,C)
(2,A)

stable_sort()

(1,B)
(2,A)
(2,C)
*/

/*-------------------- Partial Sorting --------------------*/

// First k element become the smallest k elements of complete vector and rest in random order
partial_sort(v.begin(),v.begin()+k,v.end()); // O(nlogk)
// Ex: v = {3, 2, 4, 5, 1}
// partial_sort(v.begin(), v.end()+3, v.end())
// will give 1, 2, 3, 5, 4 (last 2 elements can be in any order)

/*-------------------- is_sorted --------------------*/

is_sorted(v.begin(),v.end());

/*-------------------- Common CF Tricks --------------------*/

// Descending using reverse iterator
sort(v.rbegin(),v.rend());

// Sort by length
sort(str.begin(),str.end(),[](string &a,string &b){
    return a.size()<b.size();
});

// Sort by popcount

sort(v.begin(),v.end(),[](int a,int b){
    return __builtin_popcount(a)<__builtin_popcount(b);
});

// Sort by distance from x

int x=10;
sort(v.begin(),v.end(),[&](int a,int b){
    return abs(a-x)<abs(b-x);
});

// nth_element()
nth_element(v.begin(),v.begin()+k,v.end());
nth_element(v.begin(),v.begin()+k,v.end(),greater<int>());
/*
Places the nth element in its sorted position.
All elements before it <= nth element.
All elements after it >= nth element.
The two partitions are NOT sorted.
Average : O(n)
*/
/*-------------------- Common Mistakes --------------------*/

// Wrong Comparator
// return a.first<=b.first;

// Correct
// return a.first<b.first;

// Comparator must define STRICT ordering.

// Don't modify elements inside comparator.

// Comparator should return bool.

/* Complexity

sort()          : O(n log n)
stable_sort()   : O(n log²n) (typically O(n log n) in practice)
partial_sort()  : O(n log k)
is_sorted()     : O(n)

Uses Introsort:
Quick Sort + Heap Sort + Insertion Sort