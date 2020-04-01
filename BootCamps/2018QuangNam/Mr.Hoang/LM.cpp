using namespace std;
#include <stdio.h>
#include <iostream>
#include <set>
long long n,x;
char ch;
const int N = 1e8;
set<int> s;
bool ok(int x)
{
    while (x)
        if (s.find(x%10)!=s.end()) x/=10; else return 0;
    return 1;
}
int main()
{
    freopen("LM.inp","r",stdin);
    freopen("LM.out","w",stdout);
    scanf("%lld",&n);
    while (scanf(" %c",&ch)!=EOF) s.insert(ch-'0');
    x = 0; int cnt = 0;
    while (cnt<=N)
    {
        x += n; cnt++;
        if (ok(x))
        {
            cout << x;
            return 0;
        }
    }
    cout << 0;
}
