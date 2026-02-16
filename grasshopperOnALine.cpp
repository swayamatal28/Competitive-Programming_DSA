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
        int x;
        cin >> x;
        int k;
        cin >> k;
        if(x%k!=0 || k>x) cout << 1 << endl << x << endl;
        else cout << 2 << endl << x-1 << " " << 1    << endl;
    }
    return 0;
}