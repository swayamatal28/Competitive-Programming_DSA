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
        vector<long long> a(n),b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >>b[i];
        
        vector<long long> pref(n,0);
        pref[0]=b[0];
        for(int i=1;i<n;i++) pref[i]=pref[i-1]+b[i];
        vector<long long> cnt(n+1,0);
        vector<long long> add(n+1,0);
        for(int i=0;i<n;i++)
        {
            long long ps=0;
            if(i>0) ps=pref[i-1];
            int j=upper_bound(pref.begin(),pref.end(),a[i]+ps)-pref.begin();
            cnt[i]+=1;
            cnt[j]-=1;
            if(j<n)
            {
                if(j>0)
                add[j]+=a[i]-pref[j-1]+ps;
                else add[j]+=a[i]-ps;
            }
        }
        for(int i=0;i<n;i++)
        {
            cout << cnt[i]*b[i]+add[i] << " ";
            if(i<n-1)
            cnt[i+1]+=cnt[i];
        }
        cout << "\n";

    }

    return 0;
}
/*

5 7 3 17 8 9   10 7 7
2 4 1 3  5 7*  7 7 7

2 3 0 0  0  


*/