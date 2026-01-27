#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define pll pair<ll, ll>
#define vll vector<ll>
const int N = 1e5 + 11, mod = 1e9 + 7;
ll max(ll a, ll b) { return ((a > b) ? a : b); }
ll min(ll a, ll b) { return ((a > b) ? b : a); }

string convert(string s)
{
        int con_v = 0;

        string str;
         for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'v')
                con_v++;
            else
            {
                for (int j = 0; j < con_v - 1; j++)
                {
                    str += 'w';
                }
                
                if(con_v==1) str+='v';
                con_v = 0;
                str += s[i];
            }
        }
         for (int j = 0; j < con_v - 1; j++)
        {
            str += 'w';
        }
        if(con_v==1) str+='v';
        return str;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    while (t--)
    {
        string s;
        cin >> s; // 1e6
        string str=convert(s);
        long long w=0,wo=0,wow=0;
        for(char c:str)
        {
            if (c == 'w') {
                w++;
                wow=wow+wo;
        } 
        else if (c == 'o') {
            wo=wo+w;
        }
        }
        cout << wow << endl;
    }
    return 0;
}

