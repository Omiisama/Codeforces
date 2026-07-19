/*==================== DIVISORS ====================*/
/*-------------------- Find All Divisors --------------------*/

// O(sqrt(n))
vector<ll> divisors(ll n){
    vector<ll> d;
    for(ll i=1;i*i<=n;i++){
        if(n%i) continue;
        d.push_back(i);
        if(i!=n/i) d.push_back(n/i);
    }
    sort(d.begin(),d.end());
    return d;
}

/*-------------------- Number of Divisors --------------------*/

// O(sqrt(n))
int divisorCount(ll n){
    int cnt=0;
    for(ll i=1;i*i<=n;i++){
        if(n%i) continue;
        cnt++;
        if(i!=n/i) cnt++;
    }
    return cnt;
}

/*-------------------- Sum of Divisors --------------------*/

// O(sqrt(n))
ll divisorSum(ll n){
    ll sum=0;
    for(ll i=1;i*i<=n;i++){
        if(n%i) continue;
        sum+=i;
        if(i!=n/i) sum+=n/i;
    }
    return sum;
}

/*-------------------- Divisors From Prime Factorization --------------------*/

// factors = {(p,e)}
void gen(int idx,ll cur, vector<pair<ll,int>>& f, vector<ll>& divs){
    if(idx==(int)f.size()){
        divs.push_back(cur);
        return;
    }
    ll val=1;
    for(int i=0;i<=f[idx].second;i++){
        gen(idx+1,cur*val,f,divs);
        val*=f[idx].first;
    }
}
//vector<ll> divs;
//gen(0,1,factors,divs);
//sort(divs.begin(),divs.end());

/*-------------------- Number of Divisors From PF --------------------*/

// n = p1^a1 * p2^a2 ...
ll numDiv(vector<pair<ll,int>>& f){
    ll ans=1;
    for(auto [p,e]:f) ans*=e+1;
    return ans;
}

/*-------------------- Sum of Divisors From PF --------------------*/

// Σ (1+p+p²+...+p^e)
ll sumDiv(vector<pair<ll,int>>& f){
    ll ans=1;
    for(auto [p,e]:f){
        ll cur=1;
        ll pw=1;
        for(int i=1;i<=e;i++){
            pw*=p;
            cur+=pw;
        }
        ans*=cur;
    }
    return ans;
}

/*-------------------- Product of Divisors --------------------*/

/*
If
n = p1^a1 ...
d = number of divisors
Product = n^(d/2)
(Need modular exponentiation for large values.)
*/

/*-------------------- Common Tricks --------------------*/

/* Complexity

Find Divisors      O(sqrt(n))
Count Divisors     O(sqrt(n))
Sum Divisors       O(sqrt(n))
Generate Divisors  O(number of divisors)
*/