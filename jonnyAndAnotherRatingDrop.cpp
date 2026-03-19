#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define pll pair<ll, ll>
#define vll vector<ll>
const int N=1e5+11,mod=1e9+7;
ll max(ll a,ll b) {return ((a>b)?a:b);}
ll min(ll a,ll b) {return ((a>b)?b:a);}

long long diff(long long n,long long m){
    ll cnt=0;
    while(n!=0 && m!=0){
        if(((n&1)!=(m&1))) cnt++;

        n=(n>>1);
        m=(m>>1);
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int t;cin>>t;
    while(t--)
    {
        ll n;cin >> n;
        long long nob=0;
        ll num=n;
        while(num)
        {
            nob++;
            num=(num>>1);
        }
        long long ans=n;
        for(int i=1;i<nob;i++){
            ans+=(n/(1LL<<i));
        }
        cout << ans << endl;
    }
    return 0;
}