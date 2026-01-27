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
        int n,m;cin >> n >> m;
        vector<string> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        vector<int> zeros(n);
        int digi=0;
        for(int i=0;i<n;i++)
        {
            int zero=0;
            int len=a[i].size();
            for(int j=len-1;j>=0 && a[i][j]=='0';j--)
            {
                zero++;
            }  
            zeros[i]=(zero);
            digi+=(len-zeros[i]);
        }
        // for(auto auth:zeros) cout << auth << " " ;
        // cout << endl;
        sort(zeros.rbegin(),zeros.rend());
        for(int i=0;i<n;i++)
        {
            if(i&1)
            {
                digi+=zeros[i];
            }
        }
        if(digi-1>=m) cout << "Sasha" << endl;
        else cout << "Anna" << endl;

    }
    return 0;
}