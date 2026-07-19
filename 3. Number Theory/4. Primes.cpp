/*==================== PRIME NUMBERS & SIEVE ====================*/

/*-------------------- Primality Test --------------------*/

// O(sqrt(n))
bool isPrime(ll n){
    if(n<2) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    for(ll i=3;i*i<=n;i+=2){if(n%i==0) return false;}
    return true;
}

/*-------------------- Sieve of Eratosthenes --------------------*/

vector<bool> isPrime(1000001, true);
vector<int> primes;
void seive(){
    int n = 1000000;
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i*i<=n; i++){
        if(isPrime[i]){
            for(int j=i*i; j<=n; j+=i) isPrime[j]=false;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}

// For segmented seive in [L,R] generate prime till sqrt(R) 
// And then mark numbers as prime in range
vector<bool> segmentedSieve(ll L, ll R) {
    vector<bool> segPrime(R - L + 1, true);
    for (ll p : primes) {
        if (p * p > R) break;
        ll start = max(p * p, ((L + p - 1) / p) * p);
        for (ll x = start; x <= R; x += p) {
            segPrime[x - L] = false;
        }
    }
    if (L == 1) segPrime[0] = false;
    return segPrime;
}

/*-------------------- Smallest Prime Factor --------------------*/

const int N=1e6+5;
int spf[N]; //smallest prime factor dividing x
void SPF(){
    for(int i=0;i<N;i++) spf[i]=i;
    for(int i=2;i*i<N;i++){
        if(spf[i]!=i) continue;
        for(int j=i*i;j<N;j+=i){
            if(spf[j]==j) spf[j]=i;
        }
    }
}

/*-------------------- Prime Factorization --------------------*/

// O(log n)
vector<pair<int,int>> factorize(int n){
    vector<pair<int,int>> f;
    while(n>1){
        int p=spf[n];
        int cnt=0;
        while(n%p==0){
            n/=p;
            cnt++;
        }
        f.push_back({p,cnt});
    }
    return f;
}

/*-------------------- Distinct Prime Factors --------------------*/

vector<int> factors;
while(n>1){
    int p=spf[n];
    factors.push_back(p);
    while(n%p==0) n/=p;
}

/*-------------------- Complexity --------------------*/

isPrime()        O(sqrt(n))
Sieve            O(N log log N)
SPF              O(N log log N)
Factorization    O(log n)