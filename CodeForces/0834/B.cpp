using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)

int n, k;
const int N = 1e6 + 10;
int l[30], r[30], a[N];
string str;
int main() {
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d %d", &n, &k);
    cin >> str;
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);

    for (int i = 0; i < n; i++) {
        int x = str[i] - 'A';
        //cout << x << " " << l[x];
        if (l[x] == -1) l[x] = r[x] = i;
        else r[x] = i;
        //printf("->> %d %d\n", l[x], r[x]);
    }

    for (int i = 0; i < 26; i++)
    if (l[i] != -1)
    {
            a[l[i]] ++, a[r[i]+1] --;
            //cout << l[i] << " " << a[l[i]] << endl;
        }
    //for (int i = 0; i <= n; i++) cout << a[i] << " ";
    int t = 0;
    for (int i = 0; i <= n; i++) {
        t += a[i];
        if (t > k) {
            printf("YES");
            return 0;
        }
    }
    printf("NO");

    return 0;
}
/**/
