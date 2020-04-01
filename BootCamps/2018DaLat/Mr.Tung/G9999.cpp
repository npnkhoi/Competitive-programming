using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

//ifstream inp(".inp");
//ofstream out(".out");
const int N = 10;
int memo[N][N][N][N];
vector<int> v;

int dp(int a, int b, int c, int d) {
    if (memo[a][b][c][d] != -1) return memo[a][b][c][d];
    else {
        FOR(i, a+1, min(a+3, 9)) if (dp(i, b, c, d) == 0)
            return memo[a][b][c][d] = 1;
        FOR(i, b+1, min(b+3, 9)) if (dp(a, i, c, d) == 0)
            return memo[a][b][c][d] = 1;
        FOR(i, c+1, min(c+3, 9)) if (dp(a, b, i, d) == 0)
            return memo[a][b][c][d] = 1;
        FOR(i, d+1, min(d+3, 9)) if (dp(a, b, c, i) == 0)
            return memo[a][b][c][d] = 1;
        return memo[a][b][c][d] = 0;
    }
}
int main() {
    freopen("G9999.inp", "r", stdin);
    freopen("G9999.out", "w", stdout);
    memset(memo, -1, sizeof memo);
    memo[9][9][9][9] = 1;
    //printf("%d\n", dp(9, 9, 9, 9));
    //printf("%d\n", dp(9, 9, 9, 8));
    int n;
    scanf("%d", &n);
    int num;
    while (n--) {
        scanf("%d", &num);
        v.clear();
        while (num) {
            v.push_back(num%10);
            num /= 10;
        }
        while (v.size() < 4) v.push_back(0);
        if (dp(v[0], v[1], v[2], v[3])) printf("N");
        else printf("Y");
    }

    return 0;
}
/** Happy Coding :D */
