#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x)
{
    if (x < 2) return false;
    for (long long i = 2; i * i <= x; i++)
    {
        if (1LL*x % i == 0)
            return false;
    }
    return true;
}

bool hasPd(int x)
{
    int cnt = 0;
    for (long long i = 2; i * i <= x; i++)
    {
        if (1LL*x % i == 0 && isPrime(i))
        {
            cnt++;
            if(isPrime(x/i) && x/i!=i) cnt++;    
        }
    }
    return cnt >= 2;
}

int getprime(int x)
{
    for (long long i = 2; i * i <= x; i++)
    {
        if (1LL*x % i == 0)
            return i;
    }
    return x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        if (is_sorted(arr.begin(), arr.end()))
        {
            cout << "Bob\n";
            continue;
        }

        bool alice = false;

        for (int i = 0; i < n; i++)
        {
            if (hasPd(arr[i]))
            {
                alice = true;
                break;
            }
            if(arr[i]!=1)
            arr[i] = getprime(arr[i]);
        }

        if (alice)
        {
            cout << "Alice\n";
            continue;
        }

        if (is_sorted(arr.begin(), arr.end()))
            cout << "Bob\n";
        else
            cout << "Alice\n";
    }
}