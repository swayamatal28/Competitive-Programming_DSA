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
    
    int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.emplace_back(x);
        }
        sort(v.begin(), v.end());
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            ll y;
            cin >> y;
 
            auto it = upper_bound(v.begin(), v.end(), y);
            int ans = (it - v.begin());
            
 
            cout << ans << endl;
        }
    return 0;
}