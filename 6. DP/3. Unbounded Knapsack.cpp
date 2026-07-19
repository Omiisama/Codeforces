/*==================== UNBOUNDED KNAPSACK ====================*/

/*-------------------- Complete Knapsack --------------------*/

// Unlimited copies of every item

vector<ll> dp(W+1,0);

for(int i=1;i<=n;i++){
    for(int j=wt[i];j<=W;j++) dp[j]=max(dp[j],dp[j-wt[i]]+val[i]);
}

/*-------------------- Minimum Coins --------------------*/

// Minimum coins to make sum S

const int INF=1e9;
vector<int> dp(S+1,INF);
dp[0]=0;
for(int coin:coins){
    for(int s=coin;s<=S;s++) dp[s]=min(dp[s],dp[s-coin]+1);
}
//Answer
//dp[S]==INF ? -1 : dp[S]

/*-------------------- Number of Ways --------------------*/

// Number of ways to make sum S
// Order DOES NOT matter
vector<ll> dp(S+1,0);
dp[0]=1;
for(int coin:coins){
    for(int s=coin;s<=S;s++) dp[s]+=dp[s-coin];
}

/*-------------------- Number of Ordered Ways --------------------*/

// Order matters
vector<ll> dp(S+1,0);
dp[0]=1;
for(int s=1;s<=S;s++){
    for(int coin:coins){
        if(s>=coin) dp[s]+=dp[s-coin];
    }
}

/*-------------------- Rod Cutting --------------------*/

// len[] = piece lengths available
// Ex: len = {2, 4, 7} you can only cut pieces into these lengths
// price[] = price of corresponding lengths

vector<ll> dp(L+1,0);
for(int i=1;i<=n;i++){
    for(int j=len[i];j<=L;j++) dp[j]=max(dp[j],dp[j-len[i]]+price[i]);
}

/*-------------------- Complexity --------------------*/

// Complete Knapsack     O(nW)
// Coin Change           O(nS)
// Rod Cutting           O(nL)