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
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        int sum=accumulate(a.begin(),a.end(),0);
        // cout << sum << endl; debugging
        long long temp_sum=0;
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            temp_sum+=a[i];
            if(temp_sum<=0)
            {
                flag=true;
            }
        }
        temp_sum=0;
        for(int i=n-1;i>=0;i--)
        {
            temp_sum+=a[i];
            if(temp_sum<=0)
            {
                flag=true;
            }
        }
        if(flag)
        {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }

    }
    return 0;
}