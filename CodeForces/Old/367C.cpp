using namespace std;
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
const int N = 1e5 + 50;
string str;
int x[N], y[N], z[N], l, r, a, b, c, d, q;

int main()
{
    //freopen("test.inp","r",stdin);
    cin >> str;
    //cout << str.size() << endl;

    for (int i = 0; i <= str.size(); i++)
    {
        x[i] = x[i-1] + (str[i] == 'x');
        y[i] = y[i-1] + (str[i] == 'y');
        z[i] = z[i-1] + (str[i] == 'z');
    }
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d %d", &l, &r);
        l--; r--;
        if (r - l < 2)
        {
            printf("YES\n");
            continue;
        }
        a = x[r] - ((l>0) ? x[l-1] : 0);
        b = y[r] - ((l>0) ? y[l-1] : 0);
        c = z[r] - ((l>0) ? z[l-1] : 0);
        //printf(" a = %d b = %d c = %d\n",a,b,c);
        d = min(a,min(b,c));
        if (a-d <= 1 && b-d <= 1 && c-d <= 1) printf("YES\n");
        else printf("NO\n");
    }
}
