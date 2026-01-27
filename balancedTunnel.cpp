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
        int n;cin >> n;
        vector<int>a(n),b(n);
        vector<int> pos(n+1);
        for(int i=0;i<n;i++)
        cin >> a[i];
        for(int i=0;i<n;i++)
        {
            cin >> b[i];
            pos[b[i]]=i+1;
        }
        int fined=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(pos[a[i]]<maxi)
            {
                fined++;
            }
            maxi=max(maxi,pos[a[i]]);
        }
        cout << fined  << endl;
    }
    return 0;
}