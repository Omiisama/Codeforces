/*==================== LIS FAMILY ====================*/

/*-------------------- Longest Increasing Subsequence O(n²) --------------------*/

// dp[i] = LIS ending at i
vector<int> dp(n,1);
for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
        if(a[j]<a[i]) dp[i]=max(dp[i],dp[j]+1);
    }
}
int LIS=*max_element(dp.begin(),dp.end());

/*-------------------- Print LIS --------------------*/

vector<int> dp(n,1),par(n,-1);
for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
        if(a[j]<a[i] && dp[j]+1>dp[i]){
            dp[i]=dp[j]+1;
            par[i]=j;
        }
    }
}
int idx=max_element(dp.begin(),dp.end())-dp.begin();
vector<int> lis;
while(idx!=-1){
    lis.push_back(a[idx]);
    idx=par[idx];
}
reverse(lis.begin(),lis.end());

/*-------------------- LIS O(nlogn) --------------------*/

// Only length

vector<int> lis;
for(int x:a){
    auto it=lower_bound(lis.begin(),lis.end(),x);
    if(it==lis.end()) lis.push_back(x);
    else *it=x;
}
int length=lis.size();

// lower_bound  -> Strictly Increasing
// upper_bound  -> Non-decreasing

/*-------------------- Maximum Sum Increasing Subsequence --------------------*/

vector<ll> dp(n);
for(int i=0;i<n;i++) dp[i]=a[i];
for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
        if(a[j]<a[i]) dp[i]=max(dp[i],dp[j]+a[i]);
    }
}
ll ans=*max_element(dp.begin(),dp.end());

/*-------------------- Number of LIS --------------------*/

vector<int> len(n,1),cnt(n,1);
int mx=1;
for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
        if(a[j]<a[i]){
            if(len[j]+1>len[i]){
                len[i]=len[j]+1;
                cnt[i]=cnt[j];
            }
            else if(len[j]+1==len[i]){
                cnt[i]+=cnt[j];
            }
        }
    }
    mx=max(mx,len[i]);
}
int ways=0;
for(int i=0;i<n;i++){
    if(len[i]==mx) ways+=cnt[i];
}

/*-------------------- Longest Bitonic Subsequence --------------------*/

// Increasing then Decreasing

vector<int> inc(n,1),dec(n,1);
// LIS ending at i

for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
        if(a[j]<a[i]) inc[i]=max(inc[i],inc[j]+1);
    }
}

// LDS starting from i

for(int i=n-1;i>=0;i--){
    for(int j=n-1;j>i;j--){
        if(a[j]<a[i]) dec[i]=max(dec[i],dec[j]+1);
    }
}

int ans=0;
for(int i=0;i<n;i++) ans=max(ans,inc[i]+dec[i]-1);

/*-------------------- Common Patterns --------------------*/

/*
LIS
dp[i]=max(dp[j]+1)

MSIS
dp[i]=max(dp[j]+a[i])

Count LIS
Maintain length + count

Bitonic
LIS + LDS

LIS O(nlogn)

Patience Sorting
*/

/*-------------------- Complexity --------------------*/

// LIS O(n²)              O(n²)
// LIS O(nlogn)           O(nlogn)
// MSIS                   O(n²)
// Count LIS              O(n²)
// Bitonic                O(n²)