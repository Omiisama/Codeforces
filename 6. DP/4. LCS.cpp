/*==================== LCS FAMILY ====================*/

/*-------------------- Longest Common Subsequence --------------------*/

// dp[i][j] = LCS of first i chars of s and first j chars of t
vector<vector<int>> dp(n+1,vector<int>(m+1,0));
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
}

/*
Answer
dp[n][m]
Time : O(nm)
Space : O(nm)
*/

/*-------------------- Print LCS --------------------*/

string ans;
int i=n,j=m;
while(i>0 && j>0){
    if(s[i-1]==t[j-1]){
        ans+=s[i-1];
        i--;
        j--;
    }
    else if(dp[i-1][j]>dp[i][j-1]) i--;
    else j--;
}
reverse(ans.begin(),ans.end());

/*-------------------- Longest Common Substring --------------------*/

// Consecutive characters
vector<vector<int>> dp(n+1,vector<int>(m+1,0));
int ans=0;
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(s[i-1]==t[j-1]){
            dp[i][j]=dp[i-1][j-1]+1;
            ans=max(ans,dp[i][j]);
        }
        else dp[i][j]=0;
    }
}

/*-------------------- Longest Palindromic Subsequence --------------------*/

// Reverse the string
string t=s;
reverse(t.begin(),t.end());
// LPS = LCS(s,t)
/*-------------------- Minimum Insertions to Make Palindrome --------------------*/
// Answer = n - LPS
/*-------------------- Minimum Deletions to Make Palindrome --------------------*/
// Answer = n - LPS
/*-------------------- Minimum Insertions + Deletions --------------------*/
// Convert string A → B
insertions = m-LCS
deletions = n-LCS

/*-------------------- Shortest Common Supersequence --------------------*/

// Length
SCS = n+m-LCS

/*-------------------- Edit Distance --------------------*/

// dp[i][j] = minimum operations
vector<vector<int>> dp(n+1,vector<int>(m+1));
for(int i=0;i<=n;i++) dp[i][0]=i;
for(int j=0;j<=m;j++) dp[0][j]=j;
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1];
        else dp[i][j]=1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
    }
}

/*
Answer
dp[n][m]
Time : O(nm)
*/