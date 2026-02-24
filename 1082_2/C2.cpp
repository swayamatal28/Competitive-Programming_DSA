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
       vector<int> a(n+1);
       for(int i=1;i<=n;i++)
        cin >> a[i];
        
       vector<int> last(n+1,1);
       for(int i=2;i<=n;i++)
       {
        if(a[i]>a[i-1]+1) last[i]=i;
        else last[i]=last[i-1];
       } 
       vector<int> pse(n+1,0);
       stack<int> s;
       for(int i=1;i<=n;i++)
       {
        while(!s.empty() && a[s.top()]>=a[i]) s.pop();
        if(!s.empty()) pse[i]=s.top();
        else pse[i]=0;
        s.push(i);
       }
       long long ans=0;
       for(int i=1;i<=n;i++)
       {
        ll temp=0;
        if(pse[i]>=last[i])
        {
            temp=i-pse[i];
        }
        else temp=i;

        ans+=(1LL*temp*(n-i+1LL));
       }
       cout << ans << endl;


    }
    return 0;
}