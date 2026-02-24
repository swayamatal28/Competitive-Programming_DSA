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
       for(int i=0;i<n;i++)
        cin >> a[i];
        set<int> s;
        int count=1;
        int temp=a[0];
       for(int i=1;i<n;i++)
       {
            if(a[i]<=a[i-1]+1 && a[i]>temp)
            {
                continue;
            }
            else{
                count++;
                temp=a[i];  
            }
       }
       cout << count << endl;


    }
    return 0;
}