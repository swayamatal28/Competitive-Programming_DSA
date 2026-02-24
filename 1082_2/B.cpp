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
        int n;cin >>n;
        string x;cin >> x;
        if(n%2==0)
        {
            bool flag=true;
            int len=x.size();
            for(int i=1;i<len;i++)
            {
                if(i%2==1 && x[i-1]==x[i] && x[i]!='?')
                {
                    flag=false;
                    break;
                }
            }
            if(flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else{
            bool flag=true;
            if(x[0]=='b') flag=false;
            int len=x.size();
            for(int i=1;i<len;i++)
            {
                if(i%2==0 && x[i-1]==x[i] && x[i]!='?')
                {
                    flag=false;
                    break;
                }
            }
            if(flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}