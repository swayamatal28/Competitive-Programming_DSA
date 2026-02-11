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
        vector<int> even;
        vector<int> odd;
        for(int i=0;i<n;i++)
        {
            if(i%2==0) even.push_back(a[i]);
            else odd.push_back(a[i]);
        }
        sort(even.begin(),even.end());
        bool ch=true;
        int e=even.size();
        for(int i=0;i<e-1;i++){
            if(even[i]+1==even[i+1]) ch=false;
        }
        sort(odd.begin(),odd.end());
        int o=odd.size();
        for(int i=0;i<o-1;i++){
            if(odd[i]+1==odd[i+1]) ch=false;
        }

        if(ch) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}