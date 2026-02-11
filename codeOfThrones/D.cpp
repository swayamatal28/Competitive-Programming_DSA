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
const int MAX_SUM=400005;
int cnt[MAX_SUM];
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
        vector<int> b(n);
        for(int i=0;i<n;i++) cin >> b[i];

        vector<vector<int>> groups(n+1);
        for(int i=0;i<n;i++){
            groups[a[i]].push_back(b[i]);
        }

        long long ans=0;    
        int lx=sqrt(2*n);

        for(int x=1;x<=lx && x<=n;x++){
            if(groups[x].empty()) continue;
            for(int val:groups[x]){
                cnt[val]++;
            }

            int maxy=(2*n)/x;
            if(maxy>n) maxy=n;

            for(int y=x;y<=maxy;y++){
                if(groups[y].empty()) continue;

                long long target=(long long)x*y;
                if(target> 2*n) continue;
                if(x==y){
                    long long cur_pairs=0;
                    for(int val:groups[x]){
                        int needed=target-val;
                        if(needed>=1 && needed<=n){
                            cur_pairs+=cnt[needed];
                            if(needed==val) cur_pairs--;
                        }
                    }
                    ans+=cur_pairs/2;
                }
                else{
                    for(int val:groups[y]){
                        int needed=target-val;
                        if(needed>=1 && needed<=n){
                            ans+=cnt[needed];
                        }
                    }
                }

            }
            for(int val:groups[x]) cnt[val]--;
        }
        cout << ans << endl;
    }
    return 0;
}