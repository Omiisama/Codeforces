/*==================== GRID DP ====================*/

/*-------------------- Unique Paths --------------------*/

// Move only Right and Down
vector<vector<ll>> dp(n,vector<ll>(m,0));
dp[0][0]=1;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(i) dp[i][j]+=dp[i-1][j];
        if(j) dp[i][j]+=dp[i][j-1];
    }
}
// Answer : dp[n-1][m-1]

/*-------------------- Grid with Obstacles --------------------*/

// '#' = blocked
vector<vector<ll>> dp(n,vector<ll>(m,0));
if(grid[0][0]!='#') dp[0][0]=1;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j]=='#') continue;
        if(i) dp[i][j]+=dp[i-1][j];
        if(j) dp[i][j]+=dp[i][j-1];
    }
}

/*-------------------- Minimum Path Sum --------------------*/

const ll INF=4e18;
vector<vector<ll>> dp(n,vector<ll>(m,INF));
dp[0][0]=a[0][0];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(i) dp[i][j]=min(dp[i][j],dp[i-1][j]+a[i][j]);
        if(j) dp[i][j]=min(dp[i][j],dp[i][j-1]+a[i][j]);
    }
}

/*-------------------- Maximum Path Sum --------------------*/

const ll NEG=-4e18;
vector<vector<ll>> dp(n,vector<ll>(m,NEG));
dp[0][0]=a[0][0];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(i) dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i][j]);
        if(j) dp[i][j]=max(dp[i][j],dp[i][j-1]+a[i][j]);
    }
}

/*-------------------- Number of Paths Mod M --------------------*/

dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;

/*-------------------- Recover Path --------------------*/

string path;
int i=n-1,j=m-1;
while(i||j){
    if(i && dp[i][j]==dp[i-1][j]+a[i][j]){
        path+='D';
        i--;
    }
    else{
        path+='R';
        j--;
    }
}
reverse(path.begin(),path.end());

/*-------------------- State Compression --------------------*/

// Only previous row needed
vector<ll> dp(m);
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){

    }
}

/*-------------------- Common State --------------------*/

// dp[i][j]
// Answer till cell (i,j)

/*-------------------- Complexity --------------------*/

// Time : O(nm)
// Space : O(nm)
// Compressed : O(m)