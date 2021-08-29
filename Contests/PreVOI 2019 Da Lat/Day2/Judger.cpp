#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < n; ++i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,b,a) for (int i = b; i >= a; --i)

#define all(v) v.begin(), v.end()
#define debug(a) cerr << #a << " = " << a << "\n"

#define task ""

using namespace std;

void test() {
    ofstream inp(task".inp");

    inp.close();
}

int main() {
    ios::sync_with_stdio();
    cin.tie(0); cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    int n = 100;
    FOR(i, 1, n) {
        test();

        double Time1 = clock();
        system(task".exe");
        Time1 = (clock() - Time1) / 1000;
        debug(Time1);

        double Time2 = clock();
        system(task"_BF.exe");
        Time2 = (clock() - Time2) / 1000;
        debug(Time2);

        if (system("fc "task".out "task".ans")) {
            return 0;
        } else cerr << "CORRECT!\n";
    }
}
