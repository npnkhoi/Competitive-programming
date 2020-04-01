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
const int N = 105;
const int M = 15;

int a[N], b[N], c[N], save[N];
int n, m;

void rev(int pos) {
    REP(i, m) c[(pos+i)%n] = (1 - c[(pos+i)%n]);
}
bool ok() {
    REP(i, n) if (c[i]) return 0;
    return 1;
}
int main() {
    freopen("LATCO.inp", "r", stdin);
    freopen("LATCO.out", "w", stdout);
    scanf("%d%d", &n, &m);

    char ch;
    REP(i, n) {
        scanf(" %c", &ch);
        a[i] = (ch == '1');
    }
    REP(i, n) {
        scanf(" %c", &ch);
        b[i] = (ch == '1');
    }

    int res = n;
    REP(i, n) {
        //printf("** pos = %d\n", i);
        REP(j, n) {
            save[j] = (a[(i+j)%n] != b[j]);
            //cerr << save[j] << " ";
        }
        //cerr << endl;
        REP(mask, 1 << (m-1)) {
            REP(j, n) c[j] = save[j];
            //printf("mask = %d\n", mask);
            int cnt = __builtin_popcount(mask);
            REP(j, m-1) if ((mask & (1<<j)) > 0) {
                rev(j);
                //printf("pre-verse %d\n", j);
                /*REP(z, n) cerr << c[z] << " " ;
                cerr << endl;*/
            }
            FOR(j, m-1, n-1) if (c[j]) {
                rev(j), ++ cnt;
                /*REP(z, n) cerr << c[z] << " ";
                cerr << endl;*/
            }
            if (ok()) res = min(res, cnt);
            //printf("res = %d\n", res);
        }
    }
    printf("%d", res);
    return 0;
}
/** Happy Coding ^^ */

