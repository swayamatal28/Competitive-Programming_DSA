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
    
    int t;
    t=1;
    while(t--)
    {
        int n;cin >> n;
        vector<int> b(n);
        for(int i=0;i<n;i++) cin >> b[i];

        // O(n^2) not allowed
        map<int,vector<int>> mpp;
        for(int i=0;i<n;i++){
            mpp[(i+1)-b[i]].push_back(b[i]);
        }
        long long sum=0;

        for(auto m:mpp){
            // cout << m.first << ": ";
            long long cnt=0;
            for(auto mp:m.second) cnt+=(1LL*mp);
        
            sum=max(sum,cnt);
        }
        cout << sum << endl;
    }
    return 0;
}