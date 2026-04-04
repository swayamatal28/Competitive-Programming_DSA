#include <bits/stdc++.h>
using namespace std;

// ---------------- PBDS ----------------
//won't compile here,run online or on some other IDE
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// ---------------- MACROS ----------------
#define ll long long
#define pb push_back
#define F first
#define S second
#define pll pair<ll,ll>
#define vll vector<ll>

const int N = 1e5 + 11;
const ll mod = 1e9 + 7;

// ---------------- POWER ----------------
ll power(ll a, ll b, ll m = mod) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

// ---------------- PRIORITY QUEUE ----------------
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define maxpq_ll priority_queue<ll>
#define minpq_ll priority_queue<ll, vector<ll>, greater<ll>>

// ---------------- PRIME UTILITIES ----------------
bool isPrime(ll n) {
    if(n < 2) return false;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= n; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

vector<ll> primeFactors(ll n) {
    vector<ll> factors;
    for(ll i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            factors.pb(i);
            n /= i;
        }
    }
    if(n > 1) factors.pb(n);
    return factors;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n;cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>> a[i];
        string s;cin >> s;
        int q;cin >> q;
        int x0=0;
        int x1=0;
        vector<int> pref(n);
        pref[0]=a[0];
        for(int i=0;i<n;i++){
            if(i>0) pref[i]=pref[i-1]^a[i];
            if(s[i]=='0') x0=x0^a[i];
            else x1=x1^a[i];
        }
        while(q--)
        {
            int type;cin >> type;
            int l,r,x;
            if(type==1)
            {
                cin >> l >> r; 
                l--;r--;
                int valu=(l==0?pref[r]:pref[r]^pref[l-1]);
                x0=x0^valu;
                x1=x1^valu;
            }
            else{
                cin>>x;
                if(x==0)
                {
                    cout << x0 <<" ";
                }
                else cout << x1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}


// a   1 2 3 4 5
// s   0 1 0 0 0
// pre 1 3 0 4 1
// x0=3
// x1=2

// 011
