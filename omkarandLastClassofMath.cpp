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

        if(n%2==0)
        {
            cout << n/2 << " " << n/2 << endl;
        }
        else{
            int p=1;
            for(ll i=2;i*i<=n;i++)
            {
                if(n%i==0)
                {
                    p=n/i;
                    break;
                }
            }
            cout << p << " " << n-p << endl;
        }
    }
    return 0;
}
//1sec in 1e7 or 1e8 max