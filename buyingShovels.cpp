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
        int n,k;cin >> n >> k;
        if(k>=n || n==1) {
            cout << 1 << endl;
            continue;
        }
        int ans=1;
        for(int i=1;i*i<=n;i++)
        {
            if(n % i == 0)
            {
                if(i <= k)
                    ans = max(ans, i);
                if(n / i <= k)
                    ans = max(ans, n / i);
            }
        }
        cout << n/ans << endl;
    }
    return 0;
}