#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define pll pair<ll, ll>
#define vll vector<ll>
const int N=1e5+11,mod=1e9+7;

long long f(vector<vector<long long>>& dp,vector<int>& h1,vector<int>& h2,int n1,int prev){
    //we have following options
    //1.do not chosse any
    //2.choose anyone
    if(n1<0) return 0;
    if(prev!=-1 && dp[n1][prev]!=-1) return dp[n1][prev];
    long long a=0,b=0,c=0;
    if(prev==0 || prev==-1){
        a=1LL*h2[n1]+f(dp,h1,h2,n1-1,1);
    }
    if(prev==1 || prev==-1){
        b=1LL*h1[n1]+f(dp,h1,h2,n1-1,0);
    }
    c=1LL*f(dp,h1,h2,n1-1,prev);

    if(prev==-1) return max(a,max(b,c));
    return dp[n1][prev]=max(a,max(b,c));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int t=1;
    while(t--)
    {
        int n;cin >> n;
        vector<int> h1(n),h2(n);
        for(int i=0;i<n;i++) cin >> h1[i];
        for(int i=0;i<n;i++) cin >> h2[i];
        vector<vector<long long>> dp(n,vector<long long>(3,-1));
        cout <<  f(dp,h1,h2,n-1,-1) << endl;
    }
    return 0;
}