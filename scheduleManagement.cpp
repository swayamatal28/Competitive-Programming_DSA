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

bool possible(int t,vector<int> &a,int n,map<int,int> &mpp)
{
    int m=a.size();

    long long k=0;
    for(int i=1;i<=n;i++)
    {
        long long  oh=1LL*min(mpp[i],t);
        long long  th=1LL*(t-oh)/2;
        k+=(oh+th);
    }
    if(k>=m) return true;
    return false;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int t;cin>>t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> a(m);
        map<int,int>mpp;
        for(int i=0;i<m;i++) {
            cin >> a[i];
            mpp[a[i]]++;
        }

        int low=0;
        int high=2*m;
        int time=-1;
        while(low<=high)
        {
            int mid=(high+low)/2;

            if(possible(mid,a,n,mpp))
            {
                time=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        cout << time << endl;
    }
    return 0;
}