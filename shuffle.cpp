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
        int n,x,m;cin >> n >> x >>m;
        int rl=INT_MAX,rr=-1;
        rl=x,rr=x;
        for(int i=0;i<m;i++)
        {
            int l,r;
            cin >> l >> r;
            if(max(rl,l)<=min(rr,r))
            {
                rl=min(rl,l);
                rr=max(rr,r);
            }
            
        }
        // cout << rl << " " <<  rr << endl;
        cout << rr-rl+1 << endl;


    }
    return 0;
}