#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
#define mp make_pair
#define fi first
#define se second
const int N = 1e6 + 7;

int n, m;
int a[N];
map<int, int> id;
int tmp[N], cnt[N];
bool ok(int num) {
    int cl = a[n] - a[num];
    //cout << "num: " << num << " " << cl << endl;
    for (int i = 1; i <= m; i++) tmp[i] = cnt[i];
    //for (int i = 1; i <= m; i++) cout << i << " " << tmp[i] << endl;

    for (int i = n; i >= 1; --i) if (tmp[id[a[i]]] > 0) {
        -- tmp[id[a[i]]];
        //cout << id[a[i]] << " ";
        if (id.find(a[i] - cl) == id.end()) return 0;
        if (tmp[id[a[i] - cl]] <= 0) return 0;
        else -- tmp[id[a[i] - cl]];
        //cout << id[a[i] - cl] << endl;
    }
    return 1;
}
void sub1(){
    //cout << "ok\n";
    n = 2*n;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
        if (i == 1 || a[i] != a[i-1]) {
            id[a[i]] = ++ m;
            cnt[m] ++;
        }

    int res = 0;

    for (int i = n/2; i < n; i++) {
        res += ok(i);
        //cout << "res: " << res << endl;
    }
    printf("%d", res);
}
void sub2() {
    int res = 0;
    for (int i = 1; i <= n; i++) res += (n%i == 0);
    cout << res;
}
int main() {
    freopen("GRN.inp", "r", stdin);
    freopen("GRN.out", "w", stdout);
    scanf("%d", &n);
    //cout << n << endl;
    if (n <= 1000)
    sub1();
    else
    sub2();
}
