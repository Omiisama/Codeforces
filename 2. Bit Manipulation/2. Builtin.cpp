/*==================== BUILTIN BIT FUNCTIONS ====================*/

// NOTE:
// __builtin_* works on int (32-bit)
// __builtin_*ll works on long long (64-bit)

/*-------------------- popcount --------------------*/

// Number of set bits

__builtin_popcount(x);

__builtin_popcountll(x);

// Example

__builtin_popcount(13);      // 3

// 13 = 1101

/*-------------------- parity --------------------*/

// Returns 1 if odd number of set bits
// Returns 0 if even number of set bits

__builtin_parity(x);

__builtin_parityll(x);

/*-------------------- clz --------------------*/

// Count Leading Zeros

__builtin_clz(x);

__builtin_clzll(x);

/*
32-bit Example

x = 5

00000000...00000101

clz = 29
*/

/*-------------------- ctz --------------------*/

// Count Trailing Zeros

__builtin_ctz(x);

__builtin_ctzll(x);

/*
12 = 1100

Trailing zeros = 2
*/

/*-------------------- ffs --------------------*/

// First set bit (1-indexed)

__builtin_ffs(x);

/*
12 = 1100

Returns 3
*/

// Returns 0 if x==0

/*-------------------- Common Tricks --------------------*/

// Number of bits required

int bits=32-__builtin_clz(x);

// For long long

int bits=64-__builtin_clzll(x);

/*
Example

13

1101

Needs 4 bits.
*/

// Position of highest set bit

int pos=31-__builtin_clz(x);

// long long

int pos=63-__builtin_clzll(x);

// Position of lowest set bit

int pos=__builtin_ctz(x);

// Lowest set bit

int low=x&-x;

// Power of two

bool ok=__builtin_popcount(x)==1;

// Check single bit

bool ok=(x&(x-1))==0 && x>0;

/*-------------------- Binary String --------------------*/

bitset<32>(x);

bitset<64>(x);

/*-------------------- Common CF Tricks --------------------*/

// Iterate only set bits

for(int t=x;t;t&=t-1){

    int bit=__builtin_ctz(t);

    // process bit
}

// Highest Power of Two <= x

1<<(31-__builtin_clz(x));

// Long long

1LL<<(63-__builtin_clzll(x));

/*-------------------- Common Mistakes --------------------*/

// Undefined if x==0

__builtin_clz(0);
__builtin_ctz(0);

// Safe

if(x){

    __builtin_clz(x);
    __builtin_ctz(x);

}

// Wrong

__builtin_popcount(1LL<<40);

// Correct

__builtin_popcountll(1LL<<40);

/* Complexity

popcount()     O(1)
parity()       O(1)
clz()          O(1)
ctz()          O(1)
ffs()          O(1)
*/