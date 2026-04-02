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

long long pos(long long x,vector<int> a){
    int n=a.size();
    long long cnt=0;
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=x){
            x=x-a[i];
            cnt+=1LL*a[i];
            ans+=1LL*a[i];
        }
        else if(x!=0 && a[i]>x){
            a[i]=a[i]-x;
            cnt+=1LL*(x);
            ans+=1LL*x;
            x=0;
            cnt=cnt-a[i];
            ans++;
        }
        else if(x==0){
            cnt=cnt-a[i];
            ans++;
        }
    }
    if(cnt<0) return 2e18;
    else return ans;
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
        for(int i=0;i<n;i++ ) cin >> a[i];
        long long sum=accumulate(a.begin(),a.end(),0LL);
        long long low=1;
        long long high=sum;
        long long ans=2e18;
        sort(a.begin(),a.end());
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            long long temp_ans=pos(mid,a);
            if(temp_ans<ans){
                high=mid-1;
                ans=temp_ans;
            }
            else{
                low=mid+1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}