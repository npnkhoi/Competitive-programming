#include <bits/stdc++.h>

using namespace std;
int n, a[212345];
vector<int> b;
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = n - (n%2); i >= 2; i -= 2) b.push_back(a[i]);
    for (int i = 1; i <= n; i += 2) b.push_back(a[i]);
    if (n%2 == 0)
        for (int i = 0; i < n; i++) cout << b[i] << " ";
    else for (int i = n-1; i >= 0; i--) cout << b[i] << " ";
    return 0;
}
/**/