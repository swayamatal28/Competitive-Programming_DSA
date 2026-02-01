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
        vector<int>a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        int dif=1e9;
        for(int i=0;i<n;i++)
        {
            if(i<n-1)
            {
                dif=min(dif,a[i+1]-a[i]);
            }
        }
        // cout << dif << " ";
        if(dif<0 || dif==1e9) cout << 0 << endl;
        else if(dif==0) cout << 1 << endl;
        else if(dif%2==0) cout << dif/2+1 << endl;
        else cout << (dif+1)/2 << endl;//never priint any answer in double , either typecast it into int or use some other here dont do (ceil(dif/2.0)).;
        // else cout << (dif/2.0) << endl; -> this should not happen
    }
    return 0;
}