//O(log n)
ll power(ll a, ll n, ll MOD=1e9+7){
    a %= MOD;
    ll res=1;
    while(n){
        if(n & 1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        n >>= 1;
    }
    return res;
}

//Uses: Fast expo and mod inverse
ll power(ll a, ll n, ll MOD=1e9+7){ a %= MOD; ll res=1; while(n){ if(n & 1) res = (res*a)%MOD; a = (a*a)%MOD; n >>= 1;} return res;}