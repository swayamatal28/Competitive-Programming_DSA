#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define pll pair<ll, ll>
#define vll vector<ll>
const int N=1e5+11,mod=1e9+7;

bool issort(vector<int> &a,vector<int> &b,int divergence,int n)
{
    // cout << divergence << " ";
    for(int i=0,j=divergence;i<n-divergence ,j<n; i++,j++)
    {
        if(b[j]<=a[i]) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin >> n >> m;
        vector<int> a(n),b(n);
        a[0]=1;
        for(int i=1;i<n;i++)
        {
            cin >> a[i];
        }
        for(int i=0;i<n;i++) cin >> b[i]; 
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        int low=0,high=n;
        int ops=1e9;
        while(low<=high)
        {
            int mid=(high+low)/2;
            bool chk=issort(a,b,mid,n);
            if(chk)
            {
                // cout << "hey with mid:" << mid << " ";
                high=mid-1;
                ops=min(ops,mid);
            }
            else{
                // cout << " ohh no ";
                low=mid+1;
            }
        }
        cout << ops << endl;

    }
    return 0;
}