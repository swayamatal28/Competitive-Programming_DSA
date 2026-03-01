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

bool check(ll n,ll s,ll m)
{
    if(n==0)
    {
        if(s==0) return true;
        return false;
    }
    ll cur=s;
    for(int i=61;i>=0;i--)
    {
        if((m>>i)&1)
        {
            if(cur>=(1LL<<i))
            {
                ll take= cur>>i;
                if(take>n) take=n;
                cur=cur-(take*(1LL<<i));
            }
        }
    }
    return cur==0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int t;cin>>t;
    while(t--)
    {
        ll s,m;
        cin >> s >> m;
        if(s==0)
        {
            cout << 0 << endl;
            continue;
        }
        ll ans=-1;
        if(check(s,s,m))
        {
            ll l=1,r=s;
            ans=s;
            while(l<=r)
            {
                ll mid=l+(r-l)/2;
                if(check(mid,s,m))
                {
                    ans=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}