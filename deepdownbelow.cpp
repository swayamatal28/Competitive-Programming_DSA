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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<pair<int,int>> maxis(n);
        vector<vector<ll>>v(n);
        for(int j=0;j<n;j++)
        {
            int mons;cin >> mons;
            ll maxi=-1e18;
            for(int i=0;i<mons;i++)
            {
                int x;cin >> x;
                v[j].pb(x);
                maxi=max(maxi,x+1-i);
            }
            maxis[j]={maxi,mons};
        }
        sort(maxis.begin(),maxis.end());
        ll power=0;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            if(power<maxis[i].F)
            {
                ans += (maxis[i].F - power);
                power = maxis[i].F;
            }   
            power += maxis[i].S;
        }
        cout << ans << endl;

    }
    return 0;
}
// 13 2
// 15 3