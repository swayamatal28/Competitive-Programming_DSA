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
        ll n,k;cin >> n >> k;
        vector<ll> a(n);
        for(int i=0;i<n;i++) cin >> a[i];

        vector<ll> temp;
        for(int i=0;i<n;i++)
        {
            if(a[i]%k==0)
            {
                temp.push_back(0);
            }
            else if(a[i]<k)
            {
                temp.push_back(k-a[i]);
            }
            else
            {
                temp.push_back(k-(a[i]%k));
            }
        }
        map<int,int> mpp;
        sort(temp.begin(),temp.end());
        // for(auto t:temp) cout << t << " ";
        // cout << "temp:" << endl;

        long long maxi=0;
        for(int i=0;i<n;i++)
        {
            if(temp[i]%k==0){
                continue;
            }
            int freq=mpp[temp[i]];
            // cout << freq << "for " <<  temp[i] << " ";
            maxi=max(maxi,(temp[i]+1)+(freq*k));
            mpp[temp[i]]++;
        }
        cout << maxi << endl;


    }
    return 0;
}