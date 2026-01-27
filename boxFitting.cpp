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
    
    int t;cin>>t;//5*1e3
    while(t--)
    {
        int n;cin >> n;//1e5
        ll w;cin >> w;//1e9

        multiset<ll> wd;
        for(int i=0;i<n;i++)
        {
            ll width;cin >> width;
            wd.insert(width);
        }
        int spaceLeft=w;
        int ans=1;
        while(!wd.empty())
        {
            auto it=wd.upper_bound(spaceLeft);
            if(it!=wd.begin())
            {
                it--;
                int val=*it;
                spaceLeft-=val;
                wd.erase(it);
            }
            else
            {
                spaceLeft=w;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}