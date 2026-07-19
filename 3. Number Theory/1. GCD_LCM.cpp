/*==================== GCD & LCM ====================*/

gcd(a, b);
lcm(a, b);
// or lcm = (a/gcd(a,b))*b
// gcd(a, 0) = a
// gcd(a, b) = gcd(b, a%b)
// Reduced fraction of a/b is (a/gcd(a, b))/(b/gcd(a, b))
/*-------------------- Euclidean Algorithm --------------------*/

ll gcd(ll a,ll b){
    while(b){
        ll t=a%b;
        a=b;
        b=t;
    }
    return a;
}
/*-------------------- GCD of Array --------------------*/

vector<ll> pref(n), suff(a(n));

ll pref[0]=a[0];
for(int i=1;i<n;i++) pref[i] = gcd(pref[i-1], a[i]);

ll suff[n-1]=a[n-1];
for(ll i=n-2; i>=0; i--) suff[i] = gcd(suff[i+1], a[i]);

