/*==================== GENERAL DP PATTERNS ====================*/

/*-------------------- 1D DP --------------------*/

// dp[i] = answer till index i
dp[i]=...

/*-------------------- 2D DP --------------------*/

// dp[i][j]
/*
Examples
i = position
j = remaining

i = row
j = column

i = first string
j = second string
*/

/*-------------------- Take / Not Take --------------------*/

dp[i]=max(take, not_take);

/*-------------------- Prefix DP --------------------*/

// Answer considering first i elements
dp[i]=...

/*-------------------- Ending DP --------------------*/

// Answer ending exactly at i
dp[i]=...

/*-------------------- Interval DP --------------------*/

// dp[l][r]
for(int len=1;len<=n;len++){
    for(int l=0;l+len-1<n;l++){
        int r=l+len-1;

    }
}
/*-------------------- Grid DP --------------------*/

for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){

    }

/*-------------------- Tree DP --------------------*/

dfs(child);
dp[u]=merge(dp[child]);

/*-------------------- Bitmask DP --------------------*/

for(int mask=0;mask<(1<<n);mask++){

}

/*-------------------- Memoization --------------------*/

if(dp[state]!=-1) return dp[state];

/*-------------------- Space Optimization --------------------*/

// Only if dp[i] depends on a constant number of previous states
prev,curr,next;

/*-------------------- State Checklist --------------------*/

/*
1. State
2. Transition
3. Base Case
4. Order of Computation
5. Final Answer
*/