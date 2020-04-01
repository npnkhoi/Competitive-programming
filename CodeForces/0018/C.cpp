using namespace std;
#include <iostream>
#include <stdio.h>
int n, s, x, a[100010],res;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), s+= a[i];
    if (s % 2)
    {
        cout << 0;
        return 0;
    }
    for (int i = 1; i < n; i++)
        x += a[i], res += x+x == s;
    cout << res;


}
