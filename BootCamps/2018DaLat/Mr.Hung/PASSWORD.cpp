using namespace std;

#include <bits/stdc++.h>

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const int N = 1e5 + 5;
char a[N], b[N];
int s[N];
int LEFT, RIGHT, m, n, resL, resR;
bool ok(int l, int r) {
    if (b[l] == '0' && l < r) return 0;
    int numB = 0;
    for (int i = l; i <= r; i++) numB = 10*numB + b[i] - '0';
    r = r - n + m;
    int numA = s[r] - s[l-1];
    return numA == numB;
}
int main() {
    freopen("PASSWORD.inp", "r", stdin);
    freopen("PASSWORD.out", "w", stdout);
    resL = 0, resR = -1;
    scanf("%s %s", a+1, b+1);
    m = strlen(a+1);
    n = strlen(b+1);
    LEFT = 0; RIGHT = n+1;
    for (int i = 1; i <= min(m, n); i++)
        if (a[i] == b[i]) LEFT ++;
        else break;
    for (int i = 0; i < min(m, n); i++)
        if (a[m - i] == b[n - i]) RIGHT --;
        else break;
    for (int i = 1; i <= m; i++) s[i] = s[i-1] + a[i] - '0';

    for (int l = max(RIGHT-6, 1); l <= min(LEFT+1, n); l++)
        for (int r = max(l, RIGHT - 1); r <= min(l + 5, n); r++)
            if (ok(l, r) && r - l > resR - resL)
                resL = l, resR = r;
    printf("%d %d\n", resL, resR + m - n);
    return 0;
}
/** Happy Coding ^^ */

