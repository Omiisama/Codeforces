/*==================== MODULAR ARITHMETIC ====================*/
const ll MOD = 1000000007LL;

ll mod(ll x, ll MOD = 1000000007LL){ return ((x%MOD)+MOD)%MOD;}

/*-------------------- Addition --------------------*/

ll add(ll a,ll b, ll MOD = 1000000007LL){ return (mod(a, MOD)+mod(b, MOD))%MOD;}

/*-------------------- Subtraction --------------------*/

ll sub(ll a,ll b, ll MOD = 1000000007LL){ return (mod(a, MOD)-mod(b, MOD)+MOD)%MOD;}

/*-------------------- Multiplication --------------------*/

ll mul(ll a,ll b, ll MOD = 1000000007LL){ return (mod(a, MOD)*mod(b, MOD))%MOD;}

/*-------------------- Binary Exponentiation --------------------*/

ll power(ll a, ll n, ll MOD = 1000000007LL){
    a %= MOD;
    // a = mod(a, MOD);
    ll res=1;
    while(n){
        if(n & 1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        n >>= 1;
    }
    return res;
}

/*-------------------- Modular Inverse --------------------*/
// MOD must be prime
ll inv(ll a, ll MOD = 1000000007LL){ return power(a,MOD-2, MOD);}

/*-------------------- Division --------------------*/
// a/b % MOD
ll divide(ll a,ll b, ll MOD = 1000000007LL){ return mul(a,inv(b, MOD), MOD);}

/*-------------------- EXTRA --------------------*/
// Division only works if
gcd(b,MOD)=1
// Fermat inverse only works when MOD is prime.

/* Complexity

add()      O(1)
sub()      O(1)
mul()      O(1)
power()    O(log MOD)
inv()      O(log MOD)
divide()   O(log MOD)
*/

//IF MOD constant
const ll MOD = 1000000007LL;
ll mod(ll x){ return ((x%MOD)+MOD)%MOD;}
ll add(ll a,ll b){ return (mod(a)+mod(b))%MOD;}
ll sub(ll a,ll b){return (mod(a)-mod(b)+MOD)%MOD;}
ll mul(ll a,ll b){ return mod(a)*mod(b)%MOD;}
ll power(ll a,ll b){a=mod(a);ll res=1;while(b){if(b&1) res=mul(res,a);a=mul(a,a);b>>=1;}return res;}
ll inv(ll a){return power(a,MOD-2);}
ll divide(ll a,ll b){return mul(a,inv(b));}