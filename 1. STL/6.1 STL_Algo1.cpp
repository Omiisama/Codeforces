/*==================== STL ALGORITHMS - PART 2 ====================*/

/*-------------------- accumulate --------------------*/

// Sum

ll sum=accumulate(v.begin(),v.end(),0LL);

// Product

ll prod=accumulate(v.begin(),v.end(),1LL,multiplies<ll>());

// XOR

int xr=accumulate(v.begin(),v.end(),0,bit_xor<int>());

// Complexity : O(n)

/*-------------------- iota --------------------*/

// Fill with consecutive values

vector<int> v(5);

iota(v.begin(),v.end(),1);

// 1 2 3 4 5

iota(v.begin(),v.end(),0);

// 0 1 2 3 4

// Complexity : O(n)

/*-------------------- fill --------------------*/

// Fill entire container

fill(v.begin(),v.end(),7);

// Fill range

fill(v.begin()+l,v.begin()+r+1,0);

// Array

fill(a,a+n,-1);

// Complexity : O(n)

/*-------------------- fill_n --------------------*/

// Fill first n elements

fill_n(v.begin(),k,5);

fill_n(a,n,0);

// Complexity : O(n)

/*-------------------- partial_sum --------------------*/

// Prefix Sum

vector<int> pre(v.size());

partial_sum(v.begin(),v.end(),pre.begin());

// Example

// 1 2 3 4
// ->
// 1 3 6 10

// Complexity : O(n)

/*-------------------- adjacent_difference --------------------*/

// Difference Array

vector<int> diff(v.size());

adjacent_difference(v.begin(),v.end(),diff.begin());

// Example

// 1 3 6 10
// ->
// 1 2 3 4

// Complexity : O(n)

/*-------------------- partition --------------------*/

// Doesn't preserve order

partition(v.begin(),v.end(),[](int x){
    return x&1;
});

// Odds first, evens later

/*-------------------- stable_partition --------------------*/

// Preserves relative order

stable_partition(v.begin(),v.end(),[](int x){
    return x&1;
});

/*-------------------- merge --------------------*/

// Both arrays MUST be sorted.

merge(a.begin(),a.end(),
      b.begin(),b.end(),
      c.begin());

// Complexity : O(n+m)

/*-------------------- inplace_merge --------------------*/

// First half sorted
// Second half sorted

inplace_merge(v.begin(),v.begin()+mid,v.end());

/*-------------------- transform --------------------*/

// Square every element

transform(v.begin(),v.end(),v.begin(),[](int x){
    return x*x;
});

// Lowercase

transform(s.begin(),s.end(),s.begin(),::tolower);

// Uppercase

transform(s.begin(),s.end(),s.begin(),::toupper);

/*-------------------- copy --------------------*/

copy(v.begin(),v.end(),b.begin());

copy(a,a+n,b);

/*-------------------- copy_if --------------------*/

copy_if(v.begin(),v.end(),back_inserter(ans),[](int x){
    return x&1;
});

// Copies only odd numbers

/*-------------------- replace --------------------*/

replace(v.begin(),v.end(),old,new_val);

/*-------------------- replace_if --------------------*/

replace_if(v.begin(),v.end(),[](int x){
    return x<0;
},0);

/*-------------------- swap_ranges --------------------*/

swap_ranges(a.begin(),a.end(),b.begin());

/*-------------------- generate --------------------*/

generate(v.begin(),v.end(),rand);

/*-------------------- generate_n --------------------*/

generate_n(v.begin(),k,rand);

/*-------------------- Common CF Tricks --------------------*/

// Prefix Sum

partial_sum(v.begin(),v.end(),pre.begin());

// Initialize permutation

iota(p.begin(),p.end(),0);

// Square every element

transform(v.begin(),v.end(),v.begin(),[](int x){
    return x*x;
});

// Remove negatives

copy_if(v.begin(),v.end(),back_inserter(ans),[](int x){
    return x>=0;
});

/*-------------------- Common Mistakes --------------------*/

// accumulate()

// Wrong
accumulate(v.begin(),v.end(),0);

// If v stores ll, use

accumulate(v.begin(),v.end(),0LL);

// merge()

// Inputs MUST be sorted.

// copy()

// Destination must have enough space,
// or use back_inserter().

/* Complexity

accumulate()            : O(n)
iota()                  : O(n)
fill()                  : O(n)
fill_n()                : O(n)
partial_sum()           : O(n)
adjacent_difference()   : O(n)
partition()             : O(n)
stable_partition()      : O(n log n) (implementation dependent)
merge()                 : O(n+m)
inplace_merge()         : O(n log n)
transform()             : O(n)
copy()                  : O(n)
copy_if()               : O(n)
replace()               : O(n)
replace_if()            : O(n)
swap_ranges()           : O(n)
generate()              : O(n)
generate_n()            : O(n)