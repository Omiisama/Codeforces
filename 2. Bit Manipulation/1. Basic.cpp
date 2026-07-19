/*==================== BIT MANIPULATION - PART 1 ====================*/

/*-------------------- Basics --------------------*/

// 1 << k = 2^k

1<<0;      // 1
1<<1;      // 2
1<<2;      // 4
1<<5;      // 32

// For long long

1LL<<k;

/*-------------------- Check ith Bit --------------------*/

// 0-indexed

bool bit=(x>>i)&1;

// OR

x&(1<<i);

/*-------------------- Set ith Bit --------------------*/

x|=(1<<i);

/*-------------------- Clear ith Bit --------------------*/

x&=~(1<<i);

/*-------------------- Toggle ith Bit --------------------*/

x^=(1<<i);

/*-------------------- Lowest Bit --------------------*/

x&1;

// Odd

if(x&1){}

// Even

if(!(x&1)){}

/*-------------------- Multiply / Divide --------------------*/

// x*=2^k

x<<=k;

// x/=2^k

x>>=k;

/*-------------------- Remove Lowest Set Bit --------------------*/

x&=(x-1);

// Example

101100
101011
------
101000

/*-------------------- Is Power of Two --------------------*/

x>0 && (x&(x-1))==0;

/*-------------------- Lowest Set Bit --------------------*/

x&(-x);

// Example

12 = 1100

1100
0100

Answer = 4

/*-------------------- Turn On Lowest Zero Bit --------------------*/

x|(x+1);

/*-------------------- Turn Off Lowest One Bit --------------------*/

x&(x-1);

/*-------------------- Toggle Lowest Zero Bit --------------------*/

x^(x+1);

/*-------------------- Bit Masks --------------------*/

// First k bits ON

(1<<k)-1;

// Example

k=5

11111

// Bits l...r ON

((1<<(r-l+1))-1)<<l;

/*-------------------- Submask Enumeration --------------------*/

for(int s=mask;s;s=(s-1)&mask){

}

// Includes 0

for(int s=mask;;s=(s-1)&mask){

    if(s==0) break;
}

/*-------------------- Iterate Bits --------------------*/

for(int i=0;i<32;i++){

    if((x>>i)&1){

    }

}

// Long long

for(int i=0;i<64;i++){

}

/*-------------------- Swap Without Temp --------------------*/

a^=b;
b^=a;
a^=b;

/*
Not recommended.
Use std::swap().
*/

/*-------------------- Common Masks --------------------*/

// All bits till n

(1<<n)-1;

// Single bit

1<<i;

// Remove bit

mask^(1<<i);

// Add bit

mask|(1<<i);

// Check bit

mask&(1<<i);

/*-------------------- Binary Representation --------------------*/

bitset<8>(x);

bitset<32>(x);

bitset<64>(x);

/*-------------------- Common Mistakes --------------------*/

// Wrong

1<<40

// Correct

1LL<<40

// Shift >= bits is undefined.

// Wrong

1<<31

// Correct

1LL<<31

/* Complexity

All operations : O(1)
*/