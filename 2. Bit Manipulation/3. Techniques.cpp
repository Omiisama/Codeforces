/*==================== BITMASK TECHNIQUES ====================*/

/*-------------------- Enumerate All Subsets --------------------*/

// n elements

for(int mask=0;mask<(1<<n);mask++){

}

/*
Example

n=3

000
001
010
011
100
101
110
111
*/

/*-------------------- Iterate Elements of Subset --------------------*/

for(int i=0;i<n;i++){

    if(mask&(1<<i)){

    }

}

/*
mask = 10110

Elements

1
2
4
*/

/*-------------------- Enumerate Submasks --------------------*/

// All non-empty submasks

for(int s=mask;s;s=(s-1)&mask){

}

// Including 0

for(int s=mask;;s=(s-1)&mask){

    if(s==0)
        break;
}

/*
mask = 1101

Submasks

1101
1100
1001
1000
0101
0100
0001
0000
*/

/* Complexity

Number of submasks

2^(popcount(mask))

All masks + all submasks

O(3^n)
*/

/*-------------------- Enumerate Supermasks --------------------*/

// Universe = n bits

for(int s=mask;s<(1<<n);s=(s+1)|mask){

}

/*
Example

mask = 0101

Supermasks

0101
0111
1101
1111
*/

/*-------------------- Iterate Set Bits Only --------------------*/

for(int t=mask;t;t&=t-1){

    int b=__builtin_ctz(t);

    // process bit b
}

/*
Complexity

O(number of set bits)
*/

/*-------------------- Enumerate Fixed Size Subsets --------------------*/

// popcount(mask)==k

for(int mask=0;mask<(1<<n);mask++){

    if(__builtin_popcount(mask)==k){

    }

}

/*-------------------- Gosper's Hack --------------------*/

// Next mask with same popcount

int c=mask&-mask;
int r=mask+c;
mask=(((r^mask)>>2)/c)|r;

/*
Example

00111

↓

01011

↓

01101

↓

01110
*/

/*-------------------- Complement --------------------*/

// n bits only

int comp=((1<<n)-1)^mask;

/*
n=5

mask

10100

comp

01011
*/

/*-------------------- Union --------------------*/

A|B;

/*-------------------- Intersection --------------------*/

A&B;

/*-------------------- Difference --------------------*/

A&(~B);

/*-------------------- Symmetric Difference --------------------*/

A^B;

/*-------------------- Check Subset --------------------*/

// Is A subset of B ?

(A&B)==A;

/*-------------------- Check Disjoint --------------------*/

(A&B)==0;

/*-------------------- Count Common Bits --------------------*/

__builtin_popcount(A&B);

/*-------------------- Lowest Set Bit --------------------*/

mask&-mask;

/*-------------------- Highest Set Bit --------------------*/

31-__builtin_clz(mask);

/*-------------------- Remove Lowest Set Bit --------------------*/

mask&=(mask-1);

/*-------------------- Binary --------------------*/

bitset<16>(mask);

/*-------------------- Common CF Tricks --------------------*/

// Iterate all subsets

for(int mask=0;mask<(1<<n);mask++){

}

// Iterate only set bits

for(int t=mask;t;t&=t-1){

    int b=__builtin_ctz(t);

}

// Complement

int other=((1<<n)-1)^mask;

// Common elements

int cnt=__builtin_popcount(a&b);

// Power of two

__builtin_popcount(x)==1;

/*-------------------- Common Mistakes --------------------*/

// Wrong

~mask

// Flips all 32 bits.

// Correct

((1<<n)-1)^mask

// Don't use

1<<31

// Use

1LL<<31

// ctz(0) and clz(0)
// are undefined.