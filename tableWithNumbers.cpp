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
        int n,h,l;cin >> n >> h >> l;
        vector<pair<int,int>>s;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        int r=0,c=0,both=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<=h && a[i]<=l) both++;
            if(a[i]<=h) r++;
            if(a[i]<=l) c++;
        }
        // cout << r << " " << c << " " << both << " " << endl; 
        int remaining=max(r,c)-both;
        if(both<=remaining)
        {
            cout << both << endl;
            continue;
        }
        int pairs=remaining;
        int to_take=both-remaining;
        // if(to_take<=remaining){
        //     cout << to_take << endl;
        //     continue;
        // }
        pairs=pairs+(to_take)/2;
        // cout << remaining << ";" << to_take << ";";
        cout << pairs << endl;

    }
    return 0;
}