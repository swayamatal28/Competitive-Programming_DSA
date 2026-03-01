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

bool prime(ll x)
{
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int t;cin>>t;
    while(t--)
    {
        int n;cin >> n;
        vector<ll> a(n);
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        ll mini=1e18;

        for(ll i=2;i<1000;i++)
        {
            if(!prime(i)) continue;
            for(int j=0;j<n;j++)
            {
                if(a[j]%i!=0)
                {
                    mini=min(mini,i);
                }
            }
        }
        cout << mini << endl;
    }
    return 0;
}