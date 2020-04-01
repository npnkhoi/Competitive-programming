#include <bits/stdc++.h>

using namespace std;
string str;
int i, j, n;
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    cin >> str; i = str.size();
    str = '0' + str;
    if (i%2) i--; else i -= 2;
    while (i >= 0) {
        bool ok = 1;
        for (int j = 1; j <= i/2 && ok; j++)
        if (str[j] != str[j+i/2]) ok = 0;
        if (ok) {
            cout << i;
            return 0;
        }
        i -= 2;
    }
    cout << 0;
    return 0;
}
/**/

