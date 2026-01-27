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
    
    int t=1;
    while(t--)
    {
        int n,k;cin >> n >> k;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        double check=0;
        for(int i=0;i<k;i++) check+=a[i];
        int l=1,r=k;
        double ans=check;
        for(int i=1;i<n;i++)
        {
            if(r>=n)
            {
                break;
            }
            check=check-a[l-1]+a[r];
            ans+=check;
            l++;r++;
        }
        double to=(n-k+1);
        cout << fixed << setprecision(10) << ans/to << endl;
    }
    return 0;
}