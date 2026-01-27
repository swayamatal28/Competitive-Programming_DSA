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
        int n;cin >> n;
        ll x;cin >> x;
        vector<ll>a(n);
        vector<ll>b(n);
        vector<ll>c(n);

        vector<ll> limit(n);
        ll extra=-1;
        for(int i=0;i<n;i++)
        {
            ll p,y,z;cin >> p >> y >> z;
            a[i]=(p);
            b[i]=(y);
            c[i]=(z);
        }
        bool pos=false;
        ll sum=0;
        ll maxi=-2e18;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,(a[i]*b[i])-c[i]);
            sum+=(a[i]*(b[i]-1));
        }
        if(sum>=x)
        {
            cout<<0<<endl;
            continue;
        }   
        x=x-sum;
        if(maxi<=0) {
            cout << -1 << endl;
        }
        else{
            if(x%(maxi)==0) cout << x / maxi << endl;
            else cout << (x/maxi)+1 << endl;
        }
        
    }
    return 0;
}