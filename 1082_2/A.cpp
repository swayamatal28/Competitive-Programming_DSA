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
        ll x,y;cin >> x>>y;
        if(y==0)
        {
            if(x%3==0 && x>=0) cout << "YES" << endl;
            else cout << "NO" << endl;
            continue;
        }
        if(y>0)
        {
            x=x-(y*2);
            if(x%3==0 && x>=0) cout << "YES" << endl;
            else cout << "NO" << endl;
            continue;
        }
        if(y<0)
        {
            x=x-(-4*y);
            if(x%3==0 && x>=0) cout << "YES" << endl;
            else cout << "NO" << endl;
            continue;
        }
    }
    return 0;
}