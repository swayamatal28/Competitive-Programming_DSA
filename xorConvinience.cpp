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
        vector<int> p(n);
        p[n-1]=1;
        if(n%2==0)
        {
            p[0]=n;
        }
        else{
            p[0]=n-1;
        }
        for(int i=2;i<n;i++)
        {
            if(i%2==0)
            {
                p[i-1]=i+1;
            }
            else{
                p[i-1]=i-1;
            }
        }
        for(auto val:p)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}