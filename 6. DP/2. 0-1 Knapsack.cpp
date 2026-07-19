/*==================== 0/1 KNAPSACK ====================*/

/*-------------------- Classic 0/1 Knapsack --------------------*/

// dp[i][j] = maximum value using first i items with capacity j

for(int i=1;i<=n;i++){
    for(int j=0;j<=W;j++){
        dp[i][j]=dp[i-1][j];
        if(j>=wt[i]) dp[i][j]=max(dp[i][j], dp[i-1][j-wt[i]]+val[i]);
    }
}

//Space Optimized
vector<ll> dp(W+1,0);
for(int i=1;i<=n;i++){
    for(int j=W;j>=wt[i];j--) dp[j]=max(dp[j],dp[j-wt[i]]+val[i]);
}

/*-------------------- Subset Sum --------------------*/

// Can we make sum = S ?
vector<bool> dp(S+1,false);
dp[0]=true;
for(int x:a){
    for(int s=S;s>=x;s--) dp[s]=dp[s]||dp[s-x];
}

/*-------------------- Count Subsets --------------------*/

// Number of subsets with sum = S
vector<ll> dp(S+1,0);
dp[0]=1;
for(int x:a){
    for(int s=S;s>=x;s--) dp[s]+=dp[s-x];
}

/*-------------------- Equal Partition --------------------*/

// Total sum must be even
// Check subset sum of sum/2

/*-------------------- Minimum Partition Difference --------------------*/

// Find largest achievable sum <= total/2
// Answer = total-2*sum

/*-------------------- Target Sum --------------------*/

//Question: Divide into 2 group such that sum1-sum2 = target
// Convert to subset sum

/*
Positive - Negative = target

Positive + Negative = total
            ↓
Positive=(total+target)/2
*/

/*-------------------- Complexity --------------------*/

// Classic          O(nW)
// Subset Sum       O(nS)
// Count Subsets    O(nS)