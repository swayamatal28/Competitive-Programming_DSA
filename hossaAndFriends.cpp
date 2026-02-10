#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define pll pair<ll, ll>
#define vll vector<ll>
const int N=1e5+11,mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin >> n >> m;
        vector<int> mn(n);
        for(int i=0;i<n;i++) mn[i]=n;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin >> x >> y;
            x--;y--;
            if(x>y) swap(x,y);
            mn[x]=min(mn[x],y);
        }
            for(int i=n-2;i>=0;i--) mn[i]=min(mn[i],mn[i+1]);
            // for(int i=0;i<n;i++) cout << mn[i] << " ";
            long long ans=0;
            for(int i=0;i<n;i++)
            {
                ans+=1LL*(mn[i]-i);
            }
        cout << ans << endl;
    }
    return 0;
}


// 13
// 23

// 0  1  2 
// 2  2  2