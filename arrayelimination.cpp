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
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        vector<ll>ans;
        int gcd=0;
        for(int j=0;j<30;j++)
        {
            int count=0;
            for(int i=0;i<n;i++)
            {
                if((v[i]>>j)&1) count++;
            }
            if(count>0)
            gcd=__gcd(gcd,count);
        }
        if(gcd==0)
        {
            for(int i=1;i<=n;i++)
            {
                cout << i << " ";
            }
            cout << endl;
            continue;
        }

        for(int i=1;i*i<=gcd;i++)
        {
            if(gcd%i==0)
            {
                ans.pb(i);
                if(i!= gcd/i)
                {
                    ans.pb(gcd/i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        for(auto val:ans)
        cout << val << " ";
        cout << endl;
    }
    return 0;
}