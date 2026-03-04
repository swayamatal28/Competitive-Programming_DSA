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
        ll n,x,y;
        cin >> n >> x >> y;

        vector<int> a(n);
        int odds=0;
        for(int i=0;i<n;i++) 
        {
            cin >> a[i];
            if(a[i]%2) odds++;
        }

        if(odds%2==1)
        {
            if(x%2==y%2)
            {
                cout << "Bob" << endl;
            }
            else{
                cout << "Alice" <<  endl;
            }
        }
        else{
            if((x%2)!=(y%2))
            {
                cout << "Bob" << endl;
            }
            else{
                cout << "Alice" <<  endl;
            }
        }

    }
    return 0;
}