#include<bits/stdc++.h>
using namespace std;
#define ll long long;

int main()
{
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        int ans=0;
        // while(n>2)
        // {
        //     ans+=n/3;
        //     if(n%3==1){
        //         n=(n/3)+1;
        //     }
        //     else if(n%3==2)
        //     {
        //         n=(n/3)+2;
        //     }
        //     else {
        //         n=n/3;
        //     }
        // }
        // while(n>2)
        // {
        //     if(n%2==1)
        //     {
        //         ans+=(n/4);
        //         n=(n-)
        //     }
        // }
        int a;
        if(n%2==1)
        {
            a=1;
        }
        else {
            a=2;
        }
        cout << ((n-a+2)/2)-1 << endl;
    }
}