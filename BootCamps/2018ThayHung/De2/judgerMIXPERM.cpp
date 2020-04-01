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
#define FORD(i,b,a) for (int i = b; i >= a; i--)
#define task "mixperm"
const int nTest = 100;

ll Rand(ll l, ll r) {
    return l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r - l + 1);
}
void makeTest() {
    ofstream inp(task".inp");
    int n = Rand(1, 500);
    int a[n+1], b[n+1];
    FOR(i, 1, n) a[i] = b[i] = i;
    random_shuffle(a+1, a+n+1);
    random_shuffle(b+1, b+n+1);
    //swap(a[1], b[1]);
    //swap(a[n], b[n]);
    inp << n << "\n";
    FOR(i, 1, n) inp << a[i] << " "; inp << "\n";
    FOR(i, 1, n) inp << b[i] << " "; inp << "\n";
    inp.close();
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    FOR(i, 1, nTest) {
        printf("* TEST NUMBER: %d\n", i);
        makeTest();
        double timer = clock();
        system(task".exe");
        timer = (clock() - timer) / CLOCKS_PER_SEC;
        system(task"_BF.exe");

        if (system("fc "task".out "task".ans")) {
        //if (system("fc "task".out "task".out")) {
            printf("WRONG ANSWER :'( :'( :'( :'( :'( :'(\n");
            return 0;
        }   else printf("CORRECT :D :D :D :D :D :D (%lf)\n", timer);
        if (timer > 1) {
            printf("TIME LIMIT EXCEEDED :( :( :( :( :(\n");
            return 0;
        }
    }
    return 0;
}
