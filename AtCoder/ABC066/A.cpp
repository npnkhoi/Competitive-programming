#include <bits/stdc++.h>

using namespace std;
int a, b, c;
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d%d", &a, &b, &c);
    cout << a+b+c - max(a, max(b, c));
    return 0;
}
/**/
