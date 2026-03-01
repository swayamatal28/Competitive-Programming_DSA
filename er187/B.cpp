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
        ll x;cin>> x;
        vector<int> dig;
        ll temp=x;
        while(temp>0)
        {
            dig.push_back(temp%10);
            temp=temp/10;
        }
        int sum=0;
        for(auto di:dig) sum+=di;
        if(sum<=9)
        {
            cout << 0 << endl;
            continue;
        }
        int req=sum-9;
        vector<int> v;
        for(int i=0;i<dig.size();i++)
        {
            if(i==dig.size()-1)
            {
                v.push_back(dig[i]-1);
            }
            else{
                v.push_back(dig[i]);
            }
        }
        sort(v.rbegin(),v.rend());
        int ans=0;
        int cur=0;
        for(int val:v)
        {
            cur+=val;
            ans++;
            if(cur>=req) break;
        }
        cout << ans << endl;
    }
    return 0;
}