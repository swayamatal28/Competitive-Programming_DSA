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
        ll n,m,h;cin >> n >> m >> h;
        vector<ll>a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        vector<ll> add(n,0);
        vector<ll> upd(n,0);
        int idx=0;
        for(int i=0;i<m;i++)
        {
            ll b,c;cin >> b >> c;
            b--;
            if(upd[b]!=idx)
            {
                add[b]=0;
                upd[b]=idx;
            }
            add[b]+=c;

            if(a[b]+add[b]>h)
            {
                idx++;
            }
        }
        for(int i=0;i<n;i++)
        {
            ll val=a[i];
            if(upd[i]==idx) val+=add[i];
            cout << val << " ";
        }

        cout << endl;
    }
    return 0;
}