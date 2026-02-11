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
        int n;
        cin >> n;

        int k=n/2;
        long long tn=(long long) n*(n+1)/2;
        long long tk=(long long) k*(k+1)/2;

        long long max_sum=k*tn+n*(tn-tk);
        cout << max_sum << " " << n + k << endl;

        for(int i=1;i<=n;i++)
        {
            cout << "1 " << i;
            for(int j=1;j<=n;j++)
            {
                cout << " " << j;
            }
            cout << endl;
        }

        for(int j=1;j<=k;j++)
        {
            cout << "2 " << j;
            for(int i=1;i<=n;i++)
            {
                cout << " " << i;
            }
            cout << endl;
        }
    }
    return 0;
}