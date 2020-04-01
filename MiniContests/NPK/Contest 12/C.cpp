#include <bits/stdc++.h>

using namespace std;
string str;
unsigned long long n, x, t;
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    cin >> str;
    scanf("%lld", &n);
    x = str.size();
    while (n > x)
    {
        t = x;
        while ( (t<<1) < n) t = t << 1;
        if (n-t == 1) n--;
        else n -= t+1;
        //cout << n << " " << t;
    }
    cout << str[n-1];
    return 0;
}
/**/
