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

const int mod=1e9+7;
// int f(vector<vector<int>>& dp,vector<int>& coins,int i,int n)
// {
//     if(n==0) return 1;
//     if(i<0) return 0;
//     if(dp[n][i]!=-1) return dp[n][i];
//     int take=0,ntake=0;
//     if(coins[i]<=n)
//     take=f(dp,coins,i,n-coins[i]);
//     ntake=f(dp,coins,i-1,n);

//     return dp[n][i]=(take+ntake)%mod;
// }

bool ispal(int x)
{
    int orgx=x;
    int newx=0;
    while(x!=0)
    {
        newx=newx*10+x%10;
        x=x/10;
    }
    if(newx==orgx) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    vector<int> coins;
    
    for(int i=1;i<=40000;i++) if(ispal(i)) coins.push_back(i);
    vector<int> dp(40001,0);
    dp[0]=1;
    for(auto coin:coins)
    {
        for(int i=coin;i<=40000;i++){
            dp[i]=(dp[i]+dp[i-coin])%mod;
        }
    }
    while(t--)
    {
        int n;cin >> n;
        // f(dp,coins,coins.size()-1,n);
        int ans=dp[n];
        cout << ans << endl;
    }

    return 0;
}