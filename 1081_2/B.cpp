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
        string s;cin >> s;
        
        vector<int> temp;
        int ones=0;

        for(char c:s) if(c=='1') ones++;
        if(n%2==1 && ones%2==1) 
        {
            cout << -1 << endl;
            continue;
        }

        if(ones%2==0)
        {
            for(int i=0;i<n;i++)
            {
                if(s[i]=='1') temp.push_back(i+1);
            }
        }
        else{
            for(int i=0;i<n;i++)
            {
                if(s[i]=='0') temp.push_back(i+1);
            }
        }

        cout << temp.size() << endl;

        for(int i=0;i<temp.size();i++)
        {
            cout << temp[i] << " ";
        }
        if(temp.size()!=0)
        cout << endl;

    }
    return 0;
}