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
        for(int i=0;i<n;i++) cin>> a[i];
        sort(a.begin(),a.end());
        int zeros=0,ones=0;
        for(int i=0;i<n;i++) {
            if(a[i]==0) zeros++;
            else if(a[i]==1) ones++;
        }
        if(zeros==0) cout << "NO" << endl;
        else if(zeros>=2 && ones==0) cout << "NO" << endl;
        else cout << "YES" << endl; 
    }
    return 0;
}