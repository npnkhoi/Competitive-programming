#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define REP(i,n) for (int i = 0; i < n; i++)
#define FORD(i,b,a) for (int i = b; i >= a; i--)

#define task "delstr"
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
    int n = Rand(7, 10);
    inp << n << "\n";
    REP(i, n) inp << char(Rand(0, 4) + 'a');
    inp.close();
}
int main() {
    srand(time(NULL));
    FOR(love, 1, nTest) {
        printf("Test %d: \n", love);
        makeTest();

        double timer = clock();
        system(task".exe");
        timer = (clock() - timer) / CLOCKS_PER_SEC;
        system(task"_BF.exe");

        if (system("fc "task".out "task".ans")) {
        //if (system("fc "task".out "task".out")) {
            printf("WRONG ANSWER s!!!!!!!!!!\n");
            return 0;
        } else printf("CORRECT :) %lf\n", timer);
        if (timer > 1) {
            printf("TIME LIMIT EXCEEDED!!!!!\n");
            return 0;
        }
    }
    printf("---> Congrats :)");
    return 0;
}
