/*==================== BITMASK DP ====================*/

/*-------------------- Basics --------------------*/

// Number of masks 1<<n
// Iterate over all masks
for(int mask=0;mask<(1<<n);mask++){}

/*-------------------- Check ith Bit --------------------*/

if(mask&(1<<i))

/*-------------------- Set ith Bit --------------------*/

mask|(1<<i)

/*-------------------- Remove ith Bit --------------------*/

mask&(~(1<<i))

/*-------------------- Toggle ith Bit --------------------*/

mask^(1<<i)

/*-------------------- Count Set Bits --------------------*/

__builtin_popcount(mask)
__builtin_popcountll(mask)

/*-------------------- Least Significant Bit --------------------*/

mask&(-mask)

/*-------------------- Remove Lowest Set Bit --------------------*/

mask&(mask-1)

/*-------------------- Iterate Set Bits --------------------*/

for(int i=0;i<n;i++)
    if(mask&(1<<i)){

    }

/*-------------------- Enumerate All Submasks --------------------*/

for(int sub=mask;sub;sub=(sub-1)&mask){}

/*
Includes 0
for(int sub=mask;;sub=(sub-1)&mask){
    ...
    if(sub==0) break;
}
*/

/*-------------------- Enumerate All Supermasks --------------------*/

// Usually
for(int sup=mask;sup<(1<<n);sup=(sup+1)|mask){}

/*-------------------- Standard DP --------------------*/

// dp[mask]
vector<ll> dp(1<<n);

/*-------------------- Add One Element --------------------*/

for(int mask=0;mask<(1<<n);mask++){
    for(int i=0;i<n;i++){
        if(mask&(1<<i)) continue;
        int nxt=mask|(1<<i);
    }
}

/*-------------------- Remove One Element --------------------*/

for(int mask=0;mask<(1<<n);mask++){
    for(int i=0;i<n;i++){
        if(mask&(1<<i)){
            int nxt=mask^(1<<i);
        }
    }
}

/*-------------------- TSP DP --------------------*/

// dp[mask][i]
// Minimum cost to reach i
// after visiting mask
dp[1<<src][src]=0;

/*-------------------- Assignment DP --------------------*/

// dp[mask]
// k=assigned persons
int k=__builtin_popcount(mask);

/*-------------------- SOS DP --------------------*/

// Iterate bits
for(int i=0;i<n;i++){
    for(int mask=0;mask<(1<<n);mask++){
        if(mask&(1<<i)) dp[mask]+=dp[mask^(1<<i)];
    }
}

/*-------------------- Complexity --------------------*/

// Masks : O(2^n)
// Transitions : O(n*2^n)
// TSP : O(n²2^n)
// Submask Enumeration : O(3^n)