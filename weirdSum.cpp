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
    
    int t=1;
    while(t--)
    {
        int n,m;cin >> n >> m;
        map<int,pair<vector<int>,vector<int>>> mpp; 
        vector<vector<int>> adj(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin >> adj[i][j];
                mpp[adj[i][j]].first.push_back(i);
                mpp[adj[i][j]].second.push_back(j);
            }
        }
        long long sum=0;
        // for(auto m:mpp)
        // {
        //     vector<pair<int,int>> temp=m.second;
        //     int t=temp.size();
        //     cout << "for "<< m.first << endl;
        //     for(int i=0;i<t;i++)
        //     {
        //         cout << temp[i].first << " " << temp[i].second << endl;
        //     }
        //     cout << "next->" << endl;
        // }
        // continue;

        for(auto m:mpp)
        {
            vector<int> row=m.second.first;
            sort(row.begin(),row.end());
            vector<int> col=m.second.second;
            sort(col.begin(),col.end());
            int r=row.size(),c=col.size();
            for(int i=0;i<r;i++)
            {
                sum+=1LL*(2*i+1-r)*row[i];
            }
            for(int i=0;i<c;i++)
            {
                sum+=1LL*(2*i+1-c)*col[i];
            }
        }
        cout << sum << endl;

    }
    return 0;
}