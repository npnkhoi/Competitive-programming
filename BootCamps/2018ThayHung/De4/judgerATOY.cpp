#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,b,a) for (int i = b; i >= a; i--)
#define task "atoy"
const int nTest = 100;
const int maxE = 100;
const int N = 1e5 + 5 ;
vector<ii> child[N];
int cnt;
queue<int> q;

ll Rand(ll l, ll r) {
    return l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r - l + 1);
}
void test() {
    ofstream inp(task".inp");
    int n = Rand(1, 1000);
    inp << n << "\n";
    int cnt = 1;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int x = 0;
        if (n - cnt == 1) x = 1;
        else if (n - cnt >= 2) x = Rand(1, 2);
        if (x == 0) inp << "0 0 0 0\n";
        else if (x == 1) {
            q.push(cnt + 1);
            inp << cnt + 1 << " " << Rand(1, maxE) << " 0 0\n";
            cnt ++;
        } else {
            q.push(cnt + 1);
            q.push(cnt + 2);
            inp << cnt + 1 << " " << Rand(1, maxE) << " "
            << cnt + 2 << " " << Rand(1, maxE) << "\n";
            cnt += 2;
        }
    }
    inp << Rand(1, n);
    inp.close();
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    srand(time(NULL));
    FOR(love, 1, nTest) {
        printf("TEST NUMBER %d\n", love);
        test();
        double timer = clock();
        system(task".exe");
        timer = (clock() - timer) / CLOCKS_PER_SEC;
        system(task"_BF.exe");
        if (system("fc "task".out "task".ans")) {
            printf("WRONG ANSWER\n");
            return 0;
        } else printf("CORRECT (%lf)\n", timer);
        if (timer > 1) {
            printf("TIME LIMIT EXCEEDED\n");
            return 0;
        }
    }
}
