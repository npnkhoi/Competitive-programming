#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define taskName "voisort"

const int N = 1e3 + 5;
int a[N], r[N], l[N], n, ok[N], cntOK;
set<int> data;
set<int>::iterator it;
int next_per() {
    //cerr << "next_per\n";
    FORD(i, n-1, 1) if (a[i] < a[i+1]) {
        int tmp = i+1;
        FOR(j, i+2, n) if (a[j] > a[i] && a[j] < a[tmp]) tmp = j;
        swap(a[i], a[tmp]);
        sort(a+i+1, a+n+1);
        return n - i + 1;
    }
    return -1;
}
void update(int m) {
    //cerr << "update\n";
    FORD(i, n, n-m+1) {
        r[i] = min(r[i+1], a[i]);
        data.erase(a[i]);
        cntOK -= ok[i];
        ok[i] = 0;
    }
    /*cerr << "ok\n";
    cerr << data.size() << "\n";*/
    FOR(i, n-m+1, n) {
        if (data.empty() || a[i] < *data.begin()) l[i] = 0;
        else  {
            it = data.upper_bound(a[i]);
            it --;
            l[i] = *it;
        }
        if (l[i] < r[i]) {
            ok[i] = 1;
            cntOK ++;
        } else ok[i] = 0;
        data.insert(a[i]);
    }
    /*FOR(i, 1, n) cerr << a[i] << " "; cerr << "\n";
    FOR(i, 1, n) cerr << l[i] << " "; cerr << "\n";
    FOR(i, 1, n) cerr << r[i] << " "; cerr << "\n";
    cerr << "end update\n";*/
}
void test() {
    srand(time(NULL));
    ofstream fou(taskName".inp");
    int n = rand() % 5;
    int k = rand() % 1000000;
    fou << n << " " << k << "\n";
    int tmp[n];
    REP(i, n) tmp[i] = i+1;
    random_shuffle(tmp, tmp + n);
    REP(i, n) fou << tmp[i] << " ";
    fou.close();
}
int main() {
    //test();
    //freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    int k;
    scanf("%d%d", &n, &k);
    if (n == 1) {
        printf("1");
        exit(0);
    }
    FOR(i, 1, n) scanf("%d", &a[i]);
    r[n+1] = n+1;

    FOR(i, 1, n) {
        ok[i] = 1;
        cntOK = n;
    }
    update(n);
    int res = (cntOK == n);

    REP(z, k-1) {
        int tmp = next_per();
        if (tmp == -1) break;
        update(tmp);
        res += (cntOK == n);
        /*if (cntOK == n) {
            FOR(i, 1, n) cerr << a[i] << " "; cerr << "\n";
        }*/
    }
    printf("%d", res);
}
/** Happy Coding :D */

/*#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;
int a[N], n, cnt;
void show(int l, int r) {
    if (l > r) return;
    int x = l;
    for (int i = l+1; i <= r; ++i) if (a[i] > a[x]) x = i;
    show(l, x-1); show(x+1, r); {
        cnt ++;
        printf("%d ", a[x]);
        if (a[x] != cnt) cnt = -1;
    }
}
int main() {
    int cntTSORT = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) a[i] = i;
    do {
        for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
        cout << "--> ";
        cnt = 0;
        show(1, n);
        if (cnt == n) {
            printf(" TSOST!!");
            cntTSORT ++;
        }
        cout << "\n";
    } while (next_permutation(a+1, a+n+1));
    cerr << "count = " << cntTSORT << "\n";
}*/

