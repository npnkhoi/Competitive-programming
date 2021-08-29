#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define task "WC3"
const int nTest = 100;

const int N = 1e5 + 5;
int n, q, a[N];
vector<ii> que; 

ll Rand(ll l, ll r) {
    return l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r - l + 1);
}
void test() {
    que.clear();
    ofstream inp(task".inp");
    inp << "1\n";
    n = 100; 
    q = Rand(1, 1e5);
    inp << n << " " << q << "\n";
    for (int i = 1; i <= n; i ++) a[i] = Rand(-5e5, 5e5);
    for (int i = 1; i <= q; i ++) {
        int deci = Rand(0, 3);
        if (deci == 0) {
            int u = Rand(1, n-1), v = Rand(u + 1, n);
            inp << "? " << u << " " << v << "\n";
            que.pb(mp(u, v));

        } else {
            int u = Rand(1, n-1), v = Rand(u + 1, n);
            inp << "! " << u << " " << v << " " << a[v] - a[u] << "\n";
        }
    }
    inp.close();
}
int stringToNum(string &s) {
    int idx;
    if (s[0] == '-') idx = 1;
    else idx = 0;
    long long res = 0;
    for (int i = idx; i < s.size(); i ++) {
        res = res * 10 + s[i] - '0';
    }
    if (s[0] == '-') res = -res;
    return res;
}
void check() {
    ifstream out(task".out");
    int i = 0;
    string s;
    while (getline(out, s)) {
        //cerr << s << "\n";
        if (s[0] != 'U') {
            long long val = stringToNum(s);
            //cerr << val << "\n";
            //
            if (val != a[que[i].se] - a[que[i].fi]) {
                cerr << "WRONG! at "<< i << "\n";
                cerr << que[i].se << " " << que[i].fi << "\n"; 
                cerr << s << " " << val << " " << a[que[i].se] - a[que[i].fi] << "\n";
                exit(0);
            }
        }
        i ++;
        //cerr << i << "\n";
    }
    cerr << "CORRECT\n";
    out.close();
}

int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    srand(time(NULL));
    FOR(love, 1, nTest) {
        printf("*TEST NUMBER %d\n", love);
        test();

        double timer1 = clock();
        system(task".exe");
        timer1 = (clock() - timer1) / CLOCKS_PER_SEC;
        double timer2 = clock();
        //system(task"_BF.exe");
        timer2 = (clock() - timer2) / CLOCKS_PER_SEC;
        printf("Time: %lf %lf\n", timer1, timer2);
        cerr << "checking\n";
        check();
        cerr << "done check\n";
    }
}
