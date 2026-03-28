#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define pll pair<ll, ll>
#define vll vector<ll>
const int N=1e5+11,mod=1e9+7;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int t;cin>>t;
    while(t--)
    {
        int n;cin >> n;
        vector<pair<int,int>>a(n);
        ordered_set st;
        for(int i=0;i<n;i++){
            cin >> a[i].second;
            cin >> a[i].first;
        }
        sort(a.begin(),a.end());
        long long ans=0;
        st.insert(a[0].second);
        for(int i=1;i<n;i++){
            ans+=1LL*(st.size()-st.order_of_key(a[i].second));
            st.insert(a[i].second);
        }
        cout <<ans << endl;
    }
    return 0;
}